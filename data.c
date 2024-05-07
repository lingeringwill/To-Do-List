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

bool removeTask ( taskList* list, Task* task ) 
{
    // points to the pointers
    Task** target = list->tasks;
    // while the pointer to the task is not null
    while ( *target ) {
        if ( strcmp( ( *target )->name, task->name ) == 0 ) {
            // the refernce pointing to the data is gone, but not the data itself
            destroyTask( *target );
           
           //we need to close the gap created by destroying the task in the list
           // target is now set pointing to pointer of the task we removed
           // create a temp variable pointing to that null variable
            Task** temp = target;

            while ( *( temp ) + 1 ) {
                *temp = *( temp ) + 1;
                ++temp;
            } 

            *temp = NULL;

            list->size--;

            return true;
        }
        ++target;
    }

    return false;
}

Task* findTaskByName( taskList* list, char * name ) 
{
    // first create a target

    Task** target = list->tasks;
    
    
    while ( *target ) {
        
        if ( strcmp( ( *target )->name, name ) == 0 ) {
            return *target;
        }

        ++target;
    }

    return NULL;
}

void sortTasks( taskList * list, int ( *compare )( void const *a, void const *b ) ) {
    qsort( list, list->size, sizeof( list ), compare );
}