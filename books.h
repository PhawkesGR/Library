#ifndef BOOKS4_H_
#define BOOKS4_H_
#define MAXREVIEWS 10
#define MAXSTRING 100

enum genres {fiction, scientific, politics};

struct book{																			
	int id;																			
	char reviews[MAXREVIEWS];															
	char title[MAXSTRING];
	char author[MAXSTRING];
	enum genres genre;
	struct book *next;													
};																						


typedef struct book book;
typedef struct book *list;													

void printMenu();			 //prints menu														
void displayBooks(list);	//prints all the books											
int updateBook(book,list);  //updates a book's info
int addBook(book,list);	    //adds a book to the list													
list deleteBook(book, list); //deletes a book	 											
void save(char*,list);		//saves the data to a .dat file														
list load(FILE*);			//load data from file													
book findBook(book,list);    //finds book by id, then calls print, to print the info of the book, if the book exists
void print(book);			//prints a specific book, after the user has entered the id of the book(findBook function)

int lookForId(int,list);   //I use that function to validate the uniqueness of book id






#endif
