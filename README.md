# Student Record Management System

## Description

This is a C mini project for managing student records using a singly linked list.

The project uses dynamic memory allocation, file handling, searching, sorting and linked-list operations.

## Student Details

Each student record contains:

- Roll Number
- Name
- Marks
- Next pointer

### Menu
- a/A : Add new record
- d/D : Delete a record
- s/S : Show the list
- m/M : Modify a record
- v/V : Save records
- e/E : Exit
- t/T : Sort the list
- l/L : Delete all the records
- r/R : Reverse the list


### COMPILATION
cc stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c -o student

### EXECUTION
./student

### PROJECT FUNCTION BREAKDOWN

### 1. main()

- `headptr` stores the address of the first node of the linked list.
- `load_student()` is called first to load saved records from `student.dat`.
- The program displays the menu continuously using a `while(1)` loop.
- The user enters a menu choice.
- The choice is converted to lowercase so both uppercase and lowercase inputs work.
- The `switch` statement calls the required function.
- The program continues until the user selects Exit.

### 2. add_student()

- Memory is allocated for a new student node using `malloc()`.
- The student name and marks are taken from the user.
- Marks are checked to make sure they are between 0 and 100.
- The program searches for the smallest unused positive roll number.
- The roll number, name and marks are stored in the new node.
- The new node is linked at the end of the list.

### 3. del_student()

- The user can choose to delete using roll number or name.
- The linked list is searched for the required record.
- If the record is found, the links are changed to remove the node.
- The memory of the deleted node is released using `free()`.
- If multiple students have the same name, all matching records are displayed.
- The user then enters the roll number of the record to delete.
- If the record does not exist, a record-not-found message is displayed.

### 4. show_student()

- The function starts from the first node.
- It traverses the linked list using the `next` pointer.
- The roll number, name and marks of each student are displayed in table format.
- Traversal continues until the pointer becomes `NULL`.

### 5. modify_student()

- The user can search for a student using roll number, name or marks.
- The linked list is traversed to find the required record.
- If multiple records match the name or marks, the matching records are displayed and the roll number is used to select the required record.
- The name and marks can then be modified.
- The roll number remains unchanged.
- Marks are checked to make sure they are between 0 and 100.

### 6. save_student()

- The file `student.dat` is opened in write-binary mode.
- The linked list is traversed from the first node.
- The roll number, name and marks of every student are written to the file.
- The file is closed after saving.

### 7. load_student()

- The file `student.dat` is opened in read-binary mode.
- If the file does not exist, the list remains empty.
- Student data is read from the file.
- Memory is allocated for each new node using `malloc()`.
- The data is stored in the new node.
- The nodes are linked together to rebuild the linked list.
- The file is closed after loading.

### 8. sort_student()

- The user can select sorting by name or marks.
- For name sorting, `strcmp()` is used to compare student names alphabetically.
- For marks sorting, the marks are compared and arranged in descending order.
- The student data is swapped between existing nodes.
- No additional set of nodes is created for sorting.

### 9. delete_all()

- The function starts from the first node.
- The current node is stored temporarily.
- The head pointer is moved to the next node.
- The previous node is released using `free()`.
- This continues until all nodes are deleted.
- Finally, the head pointer becomes `NULL`.

### 10. reverse_student()

- The function reverses the linked list by changing the `next` pointers.
- Three pointers are used: `prev`, `cur` and `next`.
- The current node's `next` pointer is changed to point to the previous node.
- The pointers are moved forward one node at a time.
- Finally, `headptr` is updated to point to the last node of the original list.
- No new nodes are created.

### 11. exit_student()

- The user gets two options: Save and Exit or Exit without Saving.
- For Save and Exit, `save_student()` is called first.
- All remaining nodes are then freed.
- For Exit without Saving, the records are not saved.
- All remaining nodes are freed before the program terminates.
