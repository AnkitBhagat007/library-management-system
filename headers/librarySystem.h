// #include "./data-types.h"
// #include "./miscellaneous.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readLibraryFromFile(struct Book libraryBook[], int size) 
{
    FILE *file = fopen("./library-data/libraryBook.bin", "rb");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    fread(libraryBook, sizeof(struct Book), size, file);
    fclose(file);
}

void writeLibraryBookToFile(struct Book libraryBook[], int size)
{
    FILE *file = fopen("./library-data/libraryBook.bin", "wb");
    if (file == NULL) 
    {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(libraryBook, sizeof(struct Book), size, file);
    fclose(file);
}

void initializeBooks()
{
    struct Book libraryBook[50];
    char *bookNames[] = {"The Catcher in the Rye", "To Kill a Mockingbird", "1984", "The Great Gatsby", "Pride and Prejudice", "The Lord of the Rings", "The Hobbit", "Harry Potter and the Philosopher's Stone", "The Hunger Games", "The Da Vinci Code"};
    char *authorNames[] = {"J.D. Salinger", "Harper Lee", "George Orwell", "F. Scott Fitzgerald", "Jane Austen", "J.R.R. Tolkien", "J.K. Rowling", "Suzanne Collins", "Dan Brown"};
    
    for(int i=0;i<10;i++)
    {
        strcpy(libraryBook[i].name,bookNames[i]);
        strcpy(libraryBook[i].author,authorNames[i]);
        libraryBook[i].issueDate=20240411;
        libraryBook[i].dueDate=20240511;
    }

    writeLibraryBookToFile(libraryBook, sizeof(libraryBook) / sizeof(libraryBook[0]));
}

void printBooks(struct Book books[],int len)
{
    for(int i=0;i<len;i++)
    {
        printf("Book %d:-%s Author:-%s",i+1,books[i].name,books[i].author);
        printf("\n\n");
    }
}

void addToIssuedBook(struct Book bookIssued,char mail[50]){
    FILE *file;

        char fileName[50] = "";
        
        char book_issue_data[150] = "";
        
        sprintf(fileName, "book-issue-data/%s.txt", Email);
        sprintf(book_issue_data,"Book :-%s Author:-%s Issued Date:-%s Due Date:-%s",bookIssued.name,bookIssued.author,formatDate(bookIssued.issueDate),formatDate(bookIssued.dueDate));
        book_issue_data[149]='\n';

        file = fopen(fileName, "a+");
    
        fwrite(book_issue_data, sizeof(book_issue_data), 1, file);
        fclose(file);
}

void printIssuedBooks(char mail[50]){
    
        FILE *file;
        char fileName[50] = "";
        
        sprintf(fileName, "book-issue-data/%s.txt", Email);
        file = fopen(fileName, "r");
        char c = fgetc(file);

        while (c != EOF) 
        {  
            printf ("%c", c);  
            c = fgetc(file); 
        } 
}



void return_book(int book_number){
    
    FILE *file;
    char fileName[50] = "";
        
        sprintf(fileName, "book-issue-data/%s.txt", Email);
        
}

void printMessage(char mail[]){


    FILE *file;
    char fileName[50] = "";
        
        sprintf(fileName, "message/%s.txt", Email);

        file = fopen(fileName, "a+");
        char c = fgetc(file);

        if(c==EOF){
            printf("you have no messages\n");
        }else{
            while (c != EOF) 
                { 
                    printf ("%c", c); 
                    c = fgetc(file); 
                } printf("\n");
        }


}


