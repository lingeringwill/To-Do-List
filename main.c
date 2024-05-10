#include <stdlib.h>
#include "data.h"

int main( int argv, char* argc[] )
{
    
    Type laundry = TODO;
    Type running = COMPLETE;
   Task* node = makeTask( "laundry", laundry, "stinky", 1 );
    Task **head = &node;

    Task* node2 = makeTask( "run", running, "stinky", 2 );

    insertAtEnd( head, node2 );

    printList( *head );
    freeList( *head );
    return EXIT_SUCCESS;
}
