#include "data.h"



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

    if ( temp == NULL )
        return;

    freeList( temp->next );
    free( temp );
}

char* typeToString( Type type ) {
    char* temp = "";
    switch ( type ) {
        case TODO: temp = malloc(strlen("TO-DO" ) + 1 );
        strcpy( temp, "TO-DO");
        break;
        case DOING: temp = malloc ( strlen ( "DOING" ) + 1 );
        strcpy( temp, "DOING");
        break;
        case COMPLETE: temp = malloc ( strlen( "COMPLETE" ) + 1 );
        strcpy( temp,  "COMPLETE" );
        break;
    }

    return temp;

    
}

void printList ( Task *head ) {
    // We don't want  shift the actual head, just start there
    Task* temp = head;
    // need this in variable form to free later
    char* typeName = typeToString( temp->type );
    while ( temp != NULL ) {
        //we want to print out the headings 
        printf( "%6s %6s %6s %6s\n", "Name |", "Type |", "Note |", "Priority |" );
        // now we want to print out the values that matter 
        printf("%6s %6s %6s %6d\n", temp->name, typeName, temp->note, temp->priority );
        // moving on to the next one until it's a null value
        temp = temp->next;
    }
    
}

void destroyTask( Task* task ) {
    free( task );
}


