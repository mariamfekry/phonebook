#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include"main.h"

void read();
void menu();
void displaycontact();
void addcontact();
void deletecontact();
void modifycontact();
void savecontact();
void searchcontact();
void sort();
int valid(char num[]);
char filename[100];

int main()
{
    system("color 3");
    contact*pf;
    pf=(contact*) malloc(sizeof(contact)*100);
    read(pf);
    menu(pf);

    return 0;

}
void menu(contact*pf)
{
    system("cls");
    char ch;

    printf("\t\t**********WELCOME TO PHONEBOOK*************");
    printf("\n1-Display all contacts");
    printf("\n2-Add new contact");
    printf("\n3-Search For a Contact");
    printf("\n4-Modify a Contact");
    printf("\n5-Delete a Contact");
    printf("\n6-Exit");
    printf("\n7-save");
    printf("\n PLEASE ENTER YOUR CHOICE:");
    scanf("%c",&ch);
    fflush(stdin);
    system("cls");
    switch(ch)
    {
    case '1':

        displaycontact(pf);
        break;
    case '2':
        addcontact(pf);
        break;
    case '3':
        searchcontact(pf);
        break;
    case '4':
        modifycontact(pf);
        break;
    case '5':
        deletecontact(pf);
        break;
    case '6':
        exit(0);
        break;
    case'7':
            savecontact(pf);
        break;
    default:
        system("cls");
        printf("\nERROR! ENTER FROM 1 TO 7 ONLY");
        printf("\nPRESS ANY KEY");
        getch();
        menu(pf);
    }
}
