# strsplit.c

`strsplit()` cut a string into an array with a string delimiter.  
The function is written to have only one `malloc` / `free` per call.  
The array can be reordered or shrinked but its length can not be increased due to the original string which has been copied right after the last `NULL` pointer.

## Prototypes
``` C
char** strsplit( const char* s, const char* del );
char** strsplit_count( const char* s, const char* del, size_t* nb );
```

## Examples
``` C
#include <stdio.h>
#include <stdlib.h>
#include "strsplit.h"

int main( void ) {
	char** arr = strsplit( "qwerty:asdfgh::zxcvbn", ":" );

	if ( arr ) {
		printf( "%s\n", arr[ 0 ] ); // "qwerty"
		printf( "%s\n", arr[ 1 ] ); // "asdfgh"
		printf( "%s\n", arr[ 2 ] ); // ""
		printf( "%s\n", arr[ 3 ] ); // "zxcvbn"
		printf( "%p\n", arr[ 4 ] ); // NULL
		free( arr );
	}
	return 0;
}
```
``` C
#include <stdio.h>
#include <stdlib.h>
#include "strsplit.h"

int main( void ) {
	size_t nb;
	char** arr = strsplit_count( "qwerty:asdfgh::zxcvbn", ":", &nb );

	if ( nb == 4 ) {
		printf( "%s\n", arr[ 0 ] ); // "qwerty"
		printf( "%s\n", arr[ 1 ] ); // "asdfgh"
		printf( "%s\n", arr[ 2 ] ); // ""
		printf( "%s\n", arr[ 3 ] ); // "zxcvbn"
		printf( "%p\n", arr[ 4 ] ); // NULL
		free( arr );
	}
	return 0;
}
```
