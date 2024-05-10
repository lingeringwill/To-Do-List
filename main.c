#include <stdlib.h>
#include "data.h"

int main( int argv, char* argc[] )
{
    Task **head = NULL;
    Type laundry = TODO;
   Task* node = makeTask( "laundry", laundry, "stinky", 1 );
    
    insertAtBeginning( head, node );

    printList( *head );
    return EXIT_SUCCESS;
}
