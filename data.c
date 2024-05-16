#include "data.h"

#define INITIAL_LIST_SIZE 5
//creates new task node for the linkedList
Task* makeTask( char* name, char *type, char* note, int priority )
{
    //allocates a node onto the stack
    Task* task = ( Task* ) malloc( sizeof( Task ) );

    if ( !task ) {
        printf( "you failed to allocate something" );
        exit( 1 );
    }

    
    task->name = strdup( name );
    task->type = stringToType( type );
    task->note = strdup( note );
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
    char* temp;
    switch ( type ) {
        case TODO: temp = malloc(strlen("TO-DO" ) + 1 );
        strcpy( temp, "TO-DO");
        break;
        case DOING: temp = malloc( strlen ( "DOING" ) + 1 );
        strcpy( temp, "DOING");
        break;
        case COMPLETE: temp = malloc ( strlen( "COMPLETE" ) + 1 );
        strcpy( temp,  "COMPLETE" );
        break;
    }

    return temp;

    
}

Type stringToType( char* str ) {
    if ( strcmp( str, "todo") == 0 ) {
        return TODO;
    } else if ( strcmp ( str, "doing" ) == 0 ) {
        return DOING;
    } else if ( strcmp ( str, "complete" ) == 0 ) {
        return COMPLETE;
    } 
    printf( "fatal error");
    exit(1);
}

void printList ( Task *head ) {

    if ( head == NULL ) {
        printf( "nada\n" );
    }
    // We don't want  shift the actual head, just start there
    Task* temp = head;
    
    while ( temp != NULL ) {
        
        // need this in variable form to free later
        char* typeName = typeToString( temp->type );
        //we want to print out the headings 
        printf( "%-10s %-10s %-10s %-10s\n", "Name     |", "Type     |", "Note     |", "Priority     |" );
        // now we want to print out the values that matter 
        printf("%-10s %-10s %-10s %-10d\n", temp->name, typeName, temp->note, temp->priority );
        // moving on to the next one until it's a null value
        temp = temp->next;
        printf("\n");
        free( typeName );
    }

   
    
}

bool removeTask( Task** head, char* name ) {
    Task* temp = *head;

    if ( temp == NULL ) {
        return false;
    }

     //looking at the head, if it's the only one there and it matches, remove it
    if ( strcmp( temp->name, name ) == 0 && temp->next == NULL ) {
        *head = NULL;
        free( temp );
        return true;
    } else if ( strcmp( temp->name, name ) == 0 ) {
        Task* temp2 = temp->next;
        *head =  temp2;
        
        free( temp );   
        return true;    
    }

    //now in the case that the value we want to remove isn't the head
    while ( temp ) {
        if ( strcmp( temp->next->name, name ) == 0 ) {
           Task* temp2 = temp->next->next;
           free( temp->next );
           temp->next = temp2;
           return true;
        }
        temp = temp->next;
    } 


    return false;
}



void destroyTask( Task* task ) {
    free( task );
}


