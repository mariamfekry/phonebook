#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
typedef struct birthday
{
    int day;
    int month;
    int year;
} birth;

typedef struct phonebook
{
    char firstname[100];
    char lastname[100];
    char address[100];
    char email[100];
    birth date;
    char number[100];
} contact;
FILE *r;
FILE *m;
int counter=0;


void addcontact(contact*pf)
{
    printf("Enter first name:");
    scanf("%s",pf[counter].firstname);
    fflush(stdin);
    printf("Enter last name:");
    scanf("%s",pf[counter].lastname);
    fflush(stdin);
    printf("Enter your birthday:\n");
    printf("Enter day:");
    scanf("%d",&pf[counter].date.day);
    fflush(stdin);
    printf("Enter month:");
    scanf("%d",&pf[counter].date.month);
    fflush(stdin);
    printf("Enter year:");
    scanf("%d",&pf[counter].date.year);
    fflush(stdin);
    printf("Enter address:");
    scanf("%[^\n]s",pf[counter].address);
    fflush(stdin);
    printf("Enter email:");
    scanf("%s",pf[counter].email);
    fflush(stdin);
    printf("Enter number:");
    scanf("%s",pf[counter].number);
    while(!valid(pf[counter].number))
    {
        printf("InValid Number\n");
        printf("Enter the Number: ");
        scanf("%s",pf[counter].number);
    }
    fflush(stdin);
    counter++;
    printf("CONTACT IS ADDED SUCCESSFULLY!\n");
    getch();
    system("cls");
    menu(pf);
}
void read(contact*pf)
{
    m=fopen("phonebook.txt","r");
    while(!feof(m))
    {
        fscanf(m,"%[^,],",pf[counter].firstname);
        fscanf(m,"%[^,],",pf[counter].lastname);
        fscanf(m,"%d-",&pf[counter].date.day);
        fscanf(m,"%d-",&pf[counter].date.month);
        fscanf(m,"%d,",&pf[counter].date.year);
        fscanf(m,"%[^,],",pf[counter].address);
        fscanf(m,"%[^,],",pf[counter].email);
        fscanf(m,"%s\n",pf[counter].number);
        counter++;
    }
    fclose(m);
}

void displaycontact(contact*pf)
{

    int i;
    printf("Contacts List:\n");
    if(counter!=0)
    {
        sort(pf);
        for(i=0; i<counter; i++)
        {
            printf("\nFIRST NAME:%s\nLAST NAME:%s\nBIRTHDAY:%d-%d-%d\nADDRESS:%s\nEMAIL:%s\nPHONE NUMBER:%s\n",pf[i].firstname,pf[i].lastname,pf[i].date.day,pf[i].date.month,pf[i].date.year,pf[i].address,pf[i].email,pf[i].number);
            //printf("\n");
        }

    }
    else
    {
        printf("No contacts added!");
    }
    fflush(stdin);
    getch();
    system("cls");
    menu(pf);
}
void searchcontact(contact*pf)
{
    char name[20];
    printf("Enter the last name of contact to search :\n");
    scanf("%s",name);
    int i=0;
    int flag=0;
    for(i=0; i<counter; i++)
    {
        if(strcasecmp(pf[i].lastname,name)==0)
        {
            printf("\nFIRST NAME:%s",pf[i].firstname);
            printf("\nLAST NAME:%s",pf[i].lastname);
            printf("\nBIRTHDAY:%d-",pf[i].date.day);
            printf("%d-",pf[i].date.month);
            printf("%d",pf[i].date.year);
            printf("\nADDRESS:%s",pf[i].address);
            printf("\nEMAIL:%s",pf[i].email);
            printf("\nPHONE NUMBER:%s\n",pf[i].number);
            flag=1;
        }
    }
    if(flag==0)
        printf("contact not found!");
    fflush(stdin);
    getch();
    system("cls");
    menu(pf);
}
void deletecontact(contact*pf)
{

    int i,j,flag=0;
    char fname[20];
    char lname[20];
    printf("Enter first name of the contact to delete:\n");
    scanf("%s",fname);
    printf("Enter last name of the contact to delete:\n");
    scanf("%s",lname);
    for(i=0; i<=counter-1; i++)
    {
        if(strcasecmp(pf[i].firstname,fname)==0)
        {
            if(strcasecmp(pf[i].lastname,lname)==0)
            {
                for(j=i; j<=counter-2; j++)
                {
                    strcpy(pf[j].firstname,pf[j+1].firstname);
                    strcpy(pf[j].lastname,pf[j+1].lastname);
                    pf[j].date.day==pf[j+1].date.day;
                    pf[j].date.month==pf[j+1].date.month;
                    pf[j].date.year==pf[j+1].date.year;
                    strcpy(pf[j].address,pf[j+1].address);
                    strcpy(pf[j].email,pf[j+1].email);
                    strcpy(pf[j].number,pf[j+1].number);

                }
                flag++;
                counter--;


            }
        }
    }
    if(flag!=0)
        printf("contact deleted");
    else
        printf("Contact was not found, please try again.");
    fflush(stdin);
    getch();
    system("cls");
    menu(pf);
}
void savecontact(contact*pf)
{

    r=fopen("phonebook.txt","w");
    int i;
    for(i=0; i<counter; i++)
    {
        fflush(stdin);
        fprintf(r,"%s,%s,%d-%d-%d,%s,%s,%s\n",pf[i].firstname,pf[i].lastname,pf[i].date.day,pf[i].date.month,pf[i].date.year,pf[i].address,pf[i].email,pf[i].number);
        //printf("\n");

    }
    printf("                         Saved to file Successfully!\n");
    fclose(r);
    getch();
    system("cls");
    menu(pf);
}
void sort(contact*pf)
{
    contact temp;
    int i,j;
    for(i=0; i<counter; i++)
    {
        for(j=i+1; j<counter; j++)
        {
            if(strcasecmp(pf[i].lastname,pf[j].lastname)>0)
            {
                temp=pf[i];
                pf[i]=pf[j];
                pf[j]=temp;
            }
            else if(strcasecmp(pf[i].lastname,pf[j].lastname)==0)
            {
                if(strcmp(pf[i].firstname,pf[j].firstname)>0)
                {
                    temp=pf[i];
                    pf[i]=pf[j];
                    pf[j]=temp;
                }
                else if(strcasecmp(pf[i].firstname,pf[j].firstname)==0)
                {
                    if(strcasecmp(pf[i].firstname,pf[j].firstname)>0)
                    {
                        temp=pf[i];
                        pf[i]=pf[j];
                        pf[j]=temp;
                    }
                }
            }
        }
    }
}

void modifycontact(contact*pf)
{
    char name[20];
    printf("Enter the last name to modify:\n");
    gets(name);
    int j=1;
    int i;
    for( i=0; i<counter; i++)
    {
        if(strcasecmp(name,pf[i].lastname)==0)
        {
            printf("\nContact number:%d",j);
            printf("\nFIRSTNAME: %s",pf[i].firstname);
            printf("\nLASTNAME: %s",pf[i].lastname);
            printf("\nBIRTHDAY: %d",pf[i].date.day);
            printf("-%d",pf[i].date.month);
            printf("-%d",pf[i].date.year);
            printf("\nADDRESS: %s",pf[i].address);
            printf("\nEMAIL: %s",pf[i].email);
            printf("\nNUMBER: %s\n\n",pf[i].number);
            j++;
        }
    }

    if(j>2)
    {
        int first[50];
        printf("\nwrite first name of contact you want to modify:");
        scanf("%s",first);
        for(int k=0; k<counter; k++)
        {
            if(strcasecmp(pf[k].firstname,first)==0&&strcasecmp(pf[k].lastname,name)==0)
            {
                printf("\tenter first name:");
                scanf("%s",pf[k].firstname);
                fflush(stdin);
                printf("\tenter last name:");
                scanf("%s",pf[k].lastname);
                fflush(stdin);
                printf("\tenter birthday:");
                printf("\tenter day:");
                scanf("%d",&pf[k].date.day);
                fflush(stdin);
                printf("\tenter month:");
                scanf("%d",&pf[k].date.month);
                fflush(stdin);
                printf("\tenter year:");
                scanf("%d",&pf[k].date.year);
                fflush(stdin);
                printf("\tenter address:");
                scanf("%[^]s",pf[k].address);
                fflush(stdin);
                printf("\tenter email:");
                scanf("%s",pf[k].email);
                fflush(stdin);
                printf("\tenter your number:");
                scanf("%s",pf[k].number);
                while(!valid(pf[k].number))
                {
                    printf("InValid Number\n");
                    printf("Enter the Number: ");
                    scanf("%s",pf[k].number);
                }

            }
        }
    }

    else if(j==2)
    {
        for (i=0; i<counter; i++)
        {
            if(strcasecmp(pf[i].lastname,name)==0)
            {
                printf("\tenter first name:");
                scanf("%s",pf[i].firstname);
                fflush(stdin);
                printf("\tenter last name:");
                scanf("%s",pf[i].lastname);
                fflush(stdin);
                printf("\tenter birthday:");
                fflush(stdin);
                printf("\tenter day:");
                scanf("%d",&pf[i].date.day);
                fflush(stdin);
                printf("\tenter month:");
                scanf("%d",&pf[i].date.month);
                fflush(stdin);
                printf("\tenter year:");
                scanf("%d",&pf[i].date.year);
                fflush(stdin);
                printf("\tenter address:");
                scanf("%[^]s",pf[i].address);
                fflush(stdin);
                printf("\tenter email:");
                scanf("%s",pf[i].email);
                fflush(stdin);
                printf("\tenter your phone number:");
                scanf("%s",pf[i].number);
                while(!valid(pf[i].number))
                {
                    printf("InValid Number\n");
                    printf("Enter the Number: ");
                    scanf("%s",pf[i].number);
                }
            }
        }

    }
    else
        printf("not found");

    getch();
    system("cls");
    menu(pf);



}

int valid(char num[])
{
    int i;
    for(i=0; i<strlen(num); i++)
    {
        if(num[i]<48||num[i]>57)
        {
            return 0;
        }
    }
    return 1;
}


#endif // MAIN_H_INCLUDED
