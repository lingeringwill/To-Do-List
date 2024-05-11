#include <stdlib.h>
#include "data.h"

int main( int argv, char* argc[] )
{
    
    Type laundry = TODO;
    Type running = COMPLETE;
    Type sleeping = DOING;
    Type chilling = TODO;

    Task* node = makeTask( "laundry", laundry, "stinky", 1 );
    Task **head = &node;

    Task* node2 = makeTask( "run", running, "hello", 2 );

    Task* node3 = makeTask( "sleeping", sleeping, "goodbye", 3 );

    Task* node4 = makeTask("chilling", chilling, "sussy", 4 );

    insertAtEnd( head, node2 );
    insertAtEnd( head, node3 );
    insertAtEnd( head, node4 );

    removeTask( head, "sleeping");
    removeTask( head, "laundry");
    printList( *head );
    freeList( *head );
    return EXIT_SUCCESS;
}
