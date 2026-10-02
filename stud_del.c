#include "student.h"

////////////////////////////////////////////////////////////////////////// 
//////////stud_del.c has delete student and delete all logic//////////////
//////////////////////////////////////////////////////////////////////////

void del_student(S **ptr)
{
    char choice;
    int roll, count = 0;
    char name_temp[50];
    S *temp, *prev, *found = NULL;

    if(*ptr == NULL)
    {
        printf("No records found\n");
        return;
    }

    printf("R/r : Delete by roll number\n");
    printf("N/n : Delete by name\n");
    printf("Enter your choice: ");

    scanf(" %c", &choice);

    if(((choice >> 5) & 1) != 1)
        choice = choice + 32;

    switch(choice)
    {
        case 'r':

            printf("Enter rollno to delete: ");
            scanf("%d", &roll);

            temp = *ptr;
            prev = NULL;

            while(temp)
            {
                if(temp->rollno == roll)
                {
                    found = temp;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }

            if(found == NULL)
            {
                printf("Record not found\n");
                return;
            }

            if(prev == NULL)
                *ptr = found->next;
            else
                prev->next = found->next;

            free(found);

            printf("Record deleted successfully\n");
            break;
            
        case 'n':

            printf("Enter name to delete: ");
            scanf(" %49[^\n]", name_temp);

            temp = *ptr;

            while(temp)
            {
                if(strcmp(temp->name, name_temp) == 0)
                {
                    printf("%d %s %.6lf\n", temp->rollno,temp->name, temp->marks);
                    count++;
                }
                temp = temp->next;
            }

            if(count == 0)
            {
                printf("Record not found\n");
                return;
            }

            if(count == 1)
            {
                temp = *ptr;
                prev = NULL;

                while(temp)
                {
                    if(strcmp(temp->name, name_temp) == 0)
                        break;
                    prev = temp;
                    temp = temp->next;
                }

                if(prev == NULL)
                    *ptr = temp->next;
                else
                    prev->next = temp->next;

                free(temp);

                printf("Record deleted successfully\n");
            }
            else
            {
                printf("Multiple records found\n");
                printf("Enter rollno to delete: ");
                scanf("%d", &roll);

                temp = *ptr;
                prev = NULL;

                while(temp)
                {
                    if(temp->rollno == roll && strcmp(temp->name, name_temp) == 0)
                    {
                        found = temp;
                        break;
                    }

                    prev = temp;
                    temp = temp->next;
                }

                if(found == NULL)
                {
                    printf("Record not found\n");
                    return;
                }

                if(prev == NULL)
                    *ptr = found->next;
                else
                    prev->next = found->next;

                free(found);

                printf("Record deleted successfully\n");
            }
            break;

        default:
            printf("Invalid choice\n");
    }
}

void delete_all(S **ptr)
{
    S *temp;

    if(*ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    while(*ptr)
    {
        temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
    }

    *ptr = NULL;

    printf("All records deleted successfully\n");
}
