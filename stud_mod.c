#include "student.h"

////////////////////////////////////////////////////////////////////////// 
//////////stud_mod.c has modify student and sorting student logic/////////
//////////////////////////////////////////////////////////////////////////

void modify_student(S **ptr)
{
    char choice;
    int r_temp;
    char name_temp[50];
    double marks_temp;
    S *temp, *found = NULL;

    if(*ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");

    scanf(" %c", &choice);

    if(((choice >> 5) & 1) != 1)
        choice = choice + 32;

    switch(choice)
    {
        case 'r':
            printf("Enter rollno to search: ");
            scanf("%d", &r_temp);
            temp = *ptr;
            while(temp)
            {
                if(r_temp == temp->rollno)
                {
                    found = temp;
                    break;
                }
                temp = temp->next;
            }
            break;

        case 'n':
            printf("Enter name to search: ");
            scanf("%49s", name_temp);

            temp = *ptr;

            while(temp)
            {
                if(strcmp(name_temp, temp->name) == 0)
                    printf("%d %s %.6lf\n", temp->rollno, temp->name, temp->marks);
                temp = temp->next;
            }
            printf("Enter rollno to modify: ");
            scanf("%d", &r_temp);
            temp = *ptr;
            while(temp)
            {
                if(r_temp == temp->rollno && strcmp(name_temp, temp->name) == 0)
                {
                    found = temp;
                    break;
                }
                temp = temp->next;
            }
            break;

        case 'p':
            printf("Enter percentage to search: ");
            scanf("%lf", &marks_temp);
            temp = *ptr;
            while(temp)
            {
                if(marks_temp == temp->marks)
                    printf("%d %s %.6lf\n", temp->rollno, temp->name, temp->marks);
                temp = temp->next;
            }

            printf("Enter rollno to modify: ");
            scanf("%d", &r_temp);
            temp = *ptr;
            while(temp)
            {
                if(r_temp == temp->rollno && marks_temp == temp->marks)
                {
                    found = temp;
                    break;
                }
                temp = temp->next;
            }
            break;

        default:
            printf("Invalid choice\n");
            return;
    }

    if(found == NULL)
    {
        printf("Record not found\n");
        return;
    }

    printf("Current details: %d %s %.6lf\n", found->rollno, found->name, found->marks);

    printf("Enter new name: ");
    scanf("%49s", found->name);

    printf("Enter new marks: ");
    scanf("%lf", &marks_temp);

    while(marks_temp < 0 || marks_temp > 100)
    {
        printf("Invalid marks. Enter between 0 and 100: ");
        scanf("%lf", &marks_temp);
    }

    found->marks = marks_temp;

    printf("Record modified successfully\n");
}

void sort_student(S **ptr)
{
    char choice;
    S *i, *j, *temp;

    if(*ptr == 0)
    {
        printf("No records found\n");
        return;
    }

    printf("N/n : Sort with name\n");
    printf("P/p : Sort with percentage\n");

    scanf(" %c", &choice);

    if(((choice >> 5) & 1) != 1)
        choice = choice + 32;

    switch(choice)
    {
        case 'n':
            for(i = *ptr; i != NULL; i = i->next)
            {
                for(j = i->next; j != NULL; j = j->next)
                {
                    if(strcmp(i->name, j->name) > 0)
                    {
                        temp = i;
                        i = j;
                        j = temp;
                    }
                }
            }

            printf("Sorted by name\n");
            break;

        case 'p':
            for(i = *ptr; i != NULL; i = i->next)
            {
                for(j = i->next; j != NULL; j = j->next)
                {
                    if(i->marks < j->marks)
                    {
                        temp = i;
                        i = j;
                        j = temp;
                    }
                }
            }

            printf("Sorted by percentage\n");
            break;

        default:
            printf("Invalid choice\n");
            return;
    }
}
