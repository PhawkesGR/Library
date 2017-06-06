#include<stdio.h>
#include<stdlib.h>
#include"books4.h"
#include<assert.h>
#include<string.h>
#define MAXREVIEWS 10
#define MAXSTRING 100

//this function returns a book, then print() takes that book and prints it
book findBook(book b, list firstBook){
	list currentBook = firstBook;
	int i;
	int found = -1;
	printf("What is the id of the book you are looking for?\n");
	scanf("%d", &(b.id));
	while(1){
		if(currentBook->id == b.id){
			found = 1;
			printf("Book found.\n");
			strcpy(b.reviews, currentBook->reviews);
			strcpy(b.author, currentBook->author);
			strcpy(b.title, currentBook->title);
			b.genre = currentBook->genre;
			//displayBooks(currentBook);
			return b;
		}else{
			currentBook = currentBook->next;
			if (currentBook == NULL){
				break;
			}
		}
	}
	if (found == -1){
		b.id=6666;
		return b;	
	}
}


int lookForId(int id, list l){
	list currentBook = l;
	int found = 1;
	while(1){
		if(currentBook->id == id){
			found = -1;
			return found;
		}else{
			currentBook = currentBook->next;
			if (currentBook == NULL){
				break;
			}
		}
	}
	if (found == 1){
		return found;
	}
}

void print(book b){
	int i;
	if(b.id==0){
		printf(" Genre: fiction\n");
	}else if(b.id==1){
		printf(" Genre: scientific\n");
	}else{
		printf(" Genre: politics\n");
	}
	printf("   Title: %s \n   Author: %s \n   Reviews: %s \n   Id: %d ", b.title, b.author, b.reviews, b.id);
	
	
		

}

int updateBook(book b, list firstBook){
	list currentBook = firstBook;
	int i,j,choice;
	int found = -1;
	int temp = 0;
	printf("What is the id of the book you want to update?\n");
	scanf("%d", &(b.id));
	while(1){
		
		if(currentBook->id == b.id){
			found = 1;
			printf("If you wish to change the title, press 1, if not, press 2: \n");
			scanf("%d", &choice);
			if(choice==1){
				printf("Give a new title!\n");
				scanf("%s", &(currentBook->title[MAXSTRING]));
			}
			
			printf("If you wish to change the author, press 1, if not, press 2: \n");
			scanf("%d", &choice);
			if(choice==1){
				printf("Give new author: \n");
			scanf("%s", &(currentBook->author[MAXSTRING]));	
			}
			
			printf("If you wish to change the genre, press 1, if not, press 2: \n");
			scanf("%d", &choice);
			if(choice==1){
				printf("Give new genre (press 0 for fiction, 1 for scientific, 2 for politics): \n");
				scanf("%u", &(currentBook->genre));	
			}
			
			
			printf("If you wish to change the review, press 1, if not, press 2: \n");
			scanf("%d", &choice);
			if(choice==1){
				printf("Give a new review: \n");
				scanf("%s", &(currentBook->reviews[MAXSTRING]));
			}
			
			
			return found;
		}else{
			currentBook = currentBook->next;
			if (currentBook == NULL){
				return found;
			}
		}
		
		
	}

}


list deleteBook(book b, list firstBook){
	list currentBook = firstBook;
	list lastBook = firstBook;
	int choice;
	int found = -1;
	
	while (1)
	{
		if (currentBook->id == b.id)
		{
			found = 1;
			printf("Book with id=%d found.\n\tWould you like to delete that book, Yes or No?\nPress 1 for Yes or 2 for No.\n", currentBook->id);
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				printf("Book with id=%d deleted!\n", currentBook->id);
				if (currentBook->id == firstBook->id)					
				{
					currentBook = firstBook->next;
					firstBook->id = 0;										
										
					if (currentBook != NULL)
						return currentBook;									
				}																
				else if (currentBook->next == NULL)
				{
					lastBook->next = NULL;							 
					free(currentBook);										
				}
				else
				{
					lastBook->next = currentBook->next;		
					free(currentBook);										
				}

				return firstBook;
			case 2:
				printf("Deleting Canceled.\n");
				return firstBook;
			default:
				printf("Wrong choice.\n Please try again.\n");
				break;
			}
		}
		lastBook = currentBook;
		currentBook = currentBook->next;
		if (currentBook == NULL)
			break;


	}
	if (found == -1){
		printf("This book does not exist!\n");
	}
		
}

void printMenu(){
	int i = 1;
	printf("\n\n\n");
	printf("Choose one of the following:\n");
	printf("a)To display the books press %d.\n", i);
	i++;
	printf("b)To update a book's information press %d.\n", i);
	i++;
	printf("c)To add a book press %d.\n", i);
	i++;
	printf("d)To delete a book press %d.\n", i);
	i++;
	printf("e)To find a specific book press %d.\n", i);
	i++;
	printf("f)To exit press %d.\n", i);

	printf("\n\n");
	printf( "Give your choice! \n");

	

}


int addBook(book b, list firstBook){
	int a, findId, result;
	//first book in the list
	if (firstBook->next == NULL && firstBook->id == 0){
		
		printf("Please enter author: ");
		scanf("%s", firstBook->author);
		
		printf("Please enter title: ");
		scanf("%s", firstBook->title);
		
		printf("Please press 0 if the genre of the book is fiction, 1 if it's scientific or 2 if it's politics: ");
		scanf("%u", &firstBook->genre);
		
		printf("Please enter review: ");
		scanf("%s", firstBook->reviews);
		
		printf("Please enter id: ");
		scanf("%d", &firstBook->id);
		
		firstBook->next = NULL;
		a = 1;
		return a;
		//not first
	}else{
		list newBook = (list)malloc(sizeof(book));			
	
		printf("Please enter author: ");
		scanf("%s", newBook->author);
		
		printf("Please enter title: ");
		scanf("%s", newBook->title);
		
		printf("Please press 0 if the genre of the book is fiction, 1 if it's scientific or 2 if it's politics: ");
		scanf("%u", &newBook->genre);
		
		printf("Please enter review: ");
		scanf("%s", newBook->reviews);
				
		
		//check uniqueness of book id
		while(1){
			printf("Please enter id: ");
			scanf("%d", &findId);
			result = lookForId(findId, newBook); //if function returns 1, that means the id is not used.
			if(result==1){						   //If not, user has to pick another id
				newBook->id = findId;
				break;
			}else{
				printf("That id already exists! Please pick another one!\n");
			}
		}
		
		
		newBook->next = NULL;
	
		list currentBook = firstBook;					
		list lastBook = firstBook;						
		while (currentBook != NULL)								
		{
			currentBook = currentBook->next;			
			if (currentBook != NULL)								
				lastBook = currentBook;						
		}

		lastBook->next = newBook;
		a = 2;
		return a;
	}

							
}


void displayBooks(list firstBook){
	list currentBook = firstBook;
	int i=1;
	if (firstBook->id == 0)
	{
		printf("No books!!\n");
		return;
	}
	printf("The books stored are the following:\n");
	while (currentBook != NULL)
	{
		if(currentBook->genre==0){
			printf("%d) Genre: fiction\n", i);
		}else if(currentBook->genre==1){
			printf("%d) Genre: scientific\n", i);
		}else{
			printf("%d) Genre: politics\n", i);
		}
		printf("   Title: %s \n   Author: %s \n   Reviews: %s  \n   Id: %d \n", currentBook->title,currentBook->author, currentBook->reviews, currentBook->id);
			
		
		currentBook = currentBook->next;
		i++;
	}
	
}

void save(char* filename, list firstBook){
	FILE* stream = fopen(filename, "w");							
	list currentBook = firstBook;						
	while (currentBook != NULL)
	{
		fwrite(currentBook, sizeof(book), 1, stream);			
		currentBook = currentBook->next;
		if (currentBook == NULL)
			printf("Data stored succesfully!\n");
	}
	fclose(stream);			
}


list load(FILE* stream){
	
	list tempBook = (list)malloc(sizeof(book));			

	fread(tempBook, sizeof(book), 1, stream);							
	return tempBook;														
}
