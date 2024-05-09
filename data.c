#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INITIAL_LIST_SIZE 5
//creates new task node for the linkedList
Task* makeTask( char* name, Type type, char* note, int priority )
{
    //allocates a node onto the stack
    Task* task = ( Task* ) malloc( sizeof( Task ) );

    if ( !task ) {
        printf( "you failed to allocate something" );
        exit( 1 );
    }

    task->name = name;
    task->type = type;
    task->note = note;
    task->priority = priority;
    //sets the next value to be null
    task->next = NULL;

    return task;
}

void insertAtBeginning( Task **head, Task *node ) {

    node->next = *head;
    *head = node;
}

void insertAtEnd( Task **head, Task *node ) {

   if ( *head == NULL ) {
    *head = node;
    return;
   }

   Task* temp = *head;

   while ( temp->next != NULL ) {
        temp = temp->next;
   }

   temp->next = node;


} 

void freeList( Task* head ) {
    
    Task* temp = head;
    
    if ( temp == NULL ) {
        return;
    }
    freeList( temp->next );
    free( temp );
}

void destroyTask( Task* task ) {
    free( task );
}


