#include "student.h"

////////////////////////////////////////////////////////////////////////// 
//////////stud_add.c has add student and reverse student logic////////////
//////////////////////////////////////////////////////////////////////////

void add_student(S **ptr)
{
    S *new, *temp;
    int roll = 1;
    int found;
    char name_temp[50];
    double marks_temp;

    new = malloc(sizeof(S));

    if(new == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter student name: ");
    scanf(" %49[^\n]", name_temp);

    while(name_temp[0] == '\0')
    {
        printf("Name cannot be empty\n");
        printf("Enter student name: ");
        scanf(" %49[^\n]", name_temp);
    }

    printf("Enter marks: ");
    scanf("%lf", &marks_temp);

    while(marks_temp < 0 || marks_temp > 100)
    {
        printf("Invalid marks. Enter between 0.00 and 100.00: ");
        scanf("%lf", &marks_temp);
    }

    //finding the smallest roll number
    while(1)
    {
        found = 0;
        temp = *ptr;
        while(temp)
        {
            if(temp->rollno == roll)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        
        if(found == 0)
            break;

        roll++;
    }
    
    new->rollno = roll;
    strcpy(new->name, name_temp);
    new->marks = marks_temp;
    new->next = NULL;

    if(*ptr == NULL)
    {
        *ptr = new;
    }
    else
    {
        temp = *ptr;
        while(temp->next)
            temp = temp->next;
        temp->next = new;
    }
    printf("Student added successfully\n");
}

void reverse_student(S **ptr)
{
    S *prev = NULL, *cur = *ptr, *next;

    if(*ptr == NULL)
    {
        printf("No records found\n");
        return;
    }

    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    *ptr = prev;

    printf("List reversed successfully\n");
}
