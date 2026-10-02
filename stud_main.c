#include "student.h"
int main()
{
S *headptr = 0;
int c = 0;
char choice;
load_student(&headptr);
while(1)
{
printf("\na/A : Add new record\nd/D : Delete a record\ns/S : Show the list\nm/M : Modify a record\nv/V : Save records\ne/E : Exit\nt/T : Sort the list\nl/L : Delete all the records\nr/R : Reverse the list\n");
printf("enter your choice: ");

scanf(" %c", &choice);

if(((choice>>5)&1)!=1)
choice = choice + 32;

switch(choice)
{
case 'a': add_student(&headptr); break;
case 'd': del_student(&headptr); break;
case 's': show_student(headptr); break;
case 'm': modify_student(&headptr); break;
case 'v': save_student(headptr); break;
case 'e': exit_student(&headptr); break;
case 't': sort_student(&headptr); break;
case 'l': delete_all(&headptr); break;
case 'r': reverse_student(&headptr); break;
default: printf("try again!!!\n"); break;
}
}
}
