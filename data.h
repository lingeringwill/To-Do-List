#ifndef data
#define data
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
    this is where I'll have my tasks and taskList will be defined
*/

typedef enum type {
    TODO,
    DOING,
    COMPLETE

} Type;

typedef struct task {
    char* name;
    Type type;
    char* note;
    int priority;
   struct task* next;

} Task;


/**
*   returns a pointer to a new task with a name 
*/
Task* makeTask( char* name, char *type, char* note, int priority );

/**
*   will destroy a task once the program is done with it 
*/
void destroyTask( Task* task );

void insertAtBeginning( Task **head, Task *node );

void insertAtEnd( Task **head, Task *node );

void freeList( Task* head );

void printList( Task* head );

bool removeTask( Task** head, char* name );

char* typeToString ( Type type );

Type stringToType( char* str );
#endif