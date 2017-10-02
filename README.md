# strsplit.c

## Prototype
``` C
char** strsplit( const char* s, const char* del );
```

## Example
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
