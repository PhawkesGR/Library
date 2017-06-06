#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "books4.h"
#define MAXREVIEWS 10
#define MAXSTRING 100																	



int main(int argc, char ** argv)
{
	book b;
	list firstBook = (list)malloc(sizeof(book));						
	assert(firstBook);																
	firstBook->next = NULL;													
	firstBook->id = 0;																
	
	char *filename[MAXSTRING];
    printf("Give a file(.dat), to store the data!\n");
	scanf("%s", filename[MAXSTRING]);
	
	FILE* stream;																		
	stream = fopen(filename[MAXSTRING], "a+");	
										

	list lastBook = firstBook;												 
	list currentBook = firstBook;											
	list tempBook = firstBook;

	fseek(stream, 0, SEEK_END);															
	int fileSize = ftell(stream);														
	int data = fileSize / sizeof(book);										
	fseek(stream, 0, SEEK_SET);															


	int i;
	for (i = 0; i<data; i++){
		tempBook = load(stream);													
		if (currentBook == firstBook)
		{
			firstBook = tempBook;													
			firstBook->next = NULL;											
			currentBook = currentBook->next;
			lastBook = firstBook;
		}
		else
		{
			list newBook = (list)malloc(sizeof(book));				
			assert(newBook);															
			newBook = tempBook;													
			lastBook->next = newBook;										
			lastBook = lastBook->next;										
			newBook->next = NULL;

		}
	}
	
	
	int choice = 0;
	int bookId,flag;
	do
	{
		printMenu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			displayBooks(firstBook);
			break;
		case 2:
			displayBooks(firstBook);
			
			if (firstBook->id == 0)
			{
				printf("Empty list!\n");
			}
			else
			{
				flag = updateBook(b,firstBook);
				if(flag==1){
					printf("Book updated!\n");
				}else{
					printf("Book does not exist!\n");
				}
			}
			break;
		case 3:
			flag = addBook(b,firstBook);
			if(flag==1){
				printf("Book added! First book on the list!\n");
			}else if(flag==2){
				printf("Book added to the list!\n");
			}
			break;
		case 4:
			displayBooks(firstBook);
			if (firstBook->id == 0)
			{
				printf("Empty list! Add books, before trying to delete!\n");
			}
			else
			{
				printf("\nEnter the id of the book you wish to delete: ");
				scanf("%d", &(b.id));
				firstBook = deleteBook(b, firstBook);
				
			}
			break;
		case 5:
			
			if (firstBook->id == 0)
			{
				printf("Empty list!\n");
			}else{
				b = findBook(b,firstBook);
				if(b.id==6666){
                    printf("Book not found.\n");
					
				}else{
					print(b);
				}
			}
			break;
		case 6:
			choice = -1;
			break;
		default:
			printf("Invalid choice, try again.\n");
			break;
		}
		
	}while(choice!=-1);
	
	save(filename[MAXSTRING], firstBook);
    
	free(firstBook);


}

