#include <stdlib.h>
#include "data.h"

#define BUFFER_SIZE 100
int main( int argv, char* argc[] )
{
   
    Task** head = ( Task ** )malloc(sizeof( Task* )) ;
    *head = NULL;
    /*there should be a maximum of 6 arguments*/
   

    bool isOver = false;
    char init[ BUFFER_SIZE ] = " ";
    char *tok = " ";

    char *name = " ";
    char *type = " ";
    char *note = " ";
    char *priority = " ";
   while ( !isOver ) {

    printf("cmd> ");

    // getting string input from user
    fgets( init, sizeof( init ), stdin );
    
    if ( init[ strlen( init ) - 1 ] == '\n' ) {
        init[ strlen( init ) - 1 ] = '\0';
    }

    //tokenize the first value
   tok = strtok( init, " " );

    if ( tok == NULL ) {
        printf("invalid input\n");
    } else if ( strcmp( tok, "list" ) == 0 ) {
        char *extra = strtok( NULL, " ");
        if ( extra == NULL ) {
            printList( *head );
        } else {
            printf("invalid input\n");
        }

    } else if ( strcmp( tok, "quit" ) == 0 ) {
        isOver = true;
    } else if ( strcmp( tok, "remove" ) == 0 ) {

        if ( ( name = strtok( NULL, " " ) ) != NULL ) {
            if ( strtok( NULL, " " )  == NULL ) {
                removeTask( head, name );
            }
        }
        
    } else if ( strcmp( tok, "add" ) == 0 ) {
        if ( ( name = strtok( NULL, " " ) ) != NULL ) {
            if ( ( type = strtok ( NULL, " " ) ) != NULL ) {
                if ( ( note = strtok ( NULL, " ") ) != NULL ) {
                    if ( ( priority = strtok ( NULL, " ") ) != NULL ) {
                        if ( strtok( NULL, " " )  == NULL ) {
                            Task* test = makeTask( name, type, note, atoi( priority ) );
                            insertAtEnd( head, test );
                            printList( *head );
                        }
                    
                    } else { printf( "invalid inputs\n" ); }
                } else { printf( "invalid inputs\n" ); }

            } else { printf( "invalid inputs\n" ); }

        } else { printf( "invalid inputs\n" ); }
    } else {
        printf( "invalid input\n" );
    } 
    printf("\n");

   }
  
    freeList( *head );
    free( head );
    return EXIT_SUCCESS;
}
