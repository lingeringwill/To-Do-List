#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INITIAL_LIST_SIZE 5

Task* makeTask( char* name, Type type, char* note, int priority )
{
    
    Task* task = ( Task* ) malloc( sizeof( Task ) );

    if ( !task ) {
        printf( "you failed to allocate something" );
        return NULL;
    }

    task->name = name;
    task->type = type;
    task->note = note;
    task->priority = priority;

    return task;
}


void destroyTask( Task* task ) {
    free( task );
}

void destroyList ( taskList* list ) {
    
    Task **target = list->tasks;
    Task *temp = NULL;
    while ( ( *target ) ) {
        temp = *target;
        destroyTask( temp );
        ++(target);
    }

    free( list );
}

taskList* makeList()  
{
    int initial_capacity = INITIAL_LIST_SIZE;
    taskList* list = ( taskList* ) malloc ( sizeof( taskList ) );
    list->tasks = ( Task** ) malloc ( sizeof( Task* ) );
    list->size = 0;
    return list;
} 

bool addTask ( taskList* list, Task* task ) 
{   // first we want to check if there is space for the new task
    int capacity = ( sizeof( list->tasks ) / sizeof( Task** ) );

    if ( ( list->size + 1 ) > capacity ) {
        capacity *= 2;
        realloc( list ,capacity );
    }


    //we want to make sure that the task isn't already present
    Task **target = list->tasks;

    while ( *target ) {
        if ( strcmp(( *target )->name, task->name ) == 0 ) {
            return false;
        }
        ++target;
    }
    // now that we've checked that there's no repeats we want to add the task to the end of the list
    // we can do this with the size field
    list->tasks[ list->size + 1 ] = task;
    
    //don't forget to increase your size.
    list->size++;

    //if we've made it to this point we can return true
    return true;

}

bool removeTask ( taskList* list, Task* task ) {
    Task** target = list->tasks;
    
    while ( *target ) {
        if ( strcmp(( *target )->name, task->name ) == 0 ) {
            destroyTask( task );
            return true;
        }
        ++target;
    }

    return false;
}