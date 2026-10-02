#include "student.h"

////////////////////////////////////////////////////////////////////////// 
//stud_add.c has save student and load student data from file logic///////
//////////////////////////////////////////////////////////////////////////

void save_student(S *ptr)
{
    FILE *fp;

    fp = fopen("student.dat", "wb");

    if(fp == NULL)
    {
        printf("File opening failed\n");
        return;
    }

    while(ptr)
    {
        fwrite(&ptr->rollno, sizeof(ptr->rollno), 1, fp);
        fwrite(ptr->name, sizeof(ptr->name), 1, fp);
        fwrite(&ptr->marks, sizeof(ptr->marks), 1, fp);

        ptr = ptr->next;
    }
    fclose(fp);
    printf("Records saved successfully\n");
}


void load_student(S **ptr)
{
    FILE *fp;
    S *new, *last;
    fp = fopen("student.dat", "rb");

    if(fp == NULL)
    {
        *ptr = NULL;
        return;
    }

    while(1)
    {
        new = malloc(sizeof(S));

        if(new == NULL)
        {
            printf("Memory allocation failed\n");
            fclose(fp);
            return;
        }
        if(fread(&new->rollno, sizeof(new->rollno), 1, fp) != 1)
        {
            free(new);
            break;
        }
        fread(new->name, sizeof(new->name), 1, fp);
        fread(&new->marks, sizeof(new->marks), 1, fp);
        new->next = NULL;
        if(*ptr == NULL)
        {
            *ptr = new;
        }
        else
        {
            last = *ptr;
            while(last->next)
                last = last->next;
            last->next = new;
        }
    }
    fclose(fp);
}

void exit_student(S **ptr)
{
    char choice;
    S *temp;

    printf("S/s : Save and exit\n");
    printf("E/e : Exit without saving\n");
    printf("Enter your choice: ");

    scanf(" %c", &choice);

    if(((choice >> 5) & 1) != 1)
        choice = choice + 32;

    switch(choice)
    {
        case 's':
            save_student(*ptr);
            while(*ptr)
            {
                temp = *ptr;
                *ptr = (*ptr)->next;
                free(temp);
            }
            printf("Saved and exiting...\n");
            exit(0);

        case 'e':
            while(*ptr)
            {
                temp = *ptr;
                *ptr = (*ptr)->next;
                free(temp);
            }
            printf("Exiting without saving...\n");
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
    }
}
