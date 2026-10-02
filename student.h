#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct student
{
    int rollno;
    char name[20];
    double marks;
    struct student *next;
} S;

void add_student(S **);
void del_student(S **);
void show_student(S *);
void mod_student(S **);
void save_student(S *);
void load_student(S **);
void exit_student(S **);
void sort_student(S **);
void reverse_student(S **);
void delete_student(S **);
void delete_all(S **);
