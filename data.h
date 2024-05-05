#ifndef data
#define data
#include <stdbool.h>
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

} Task;

typedef struct taskList {
    int size;
    Task** tasks;

    
} taskList;
/**
*   returns a pointer to a new task with a name 
*/
Task* makeTask( char* name, Type type, char* note, int priority );

/**
*   creates a new list
*/
taskList* makeList(); 
/**
*   will destroy a task once the program is done with it 
*/
void destroyTask( Task* task );

/**
    will destroy a list once the program is done with it 
*/
void destroyList( taskList* list );
/**
    will add a task to the taskList
*/
bool addTask ( taskList* list, Task* task );

bool removeTask ( taskList* list, Task* task );

#endif