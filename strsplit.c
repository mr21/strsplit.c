#include "strsplit.h"
#include <string.h>
#include <stdlib.h>

static char** _strsplit( const char* s, const char* delim, size_t* nb ) {
	void* data;
	char* _s = ( char* )s;
	const char** ptrs;
	size_t
		ptrsSize,
		nbWords = 1,
		sLen = strlen( s ),
		delimLen = strlen( delim );

	while ( ( _s = strstr( _s, delim ) ) ) {
		_s += delimLen;
		++nbWords;
	}
	ptrsSize = ( nbWords + 1 ) * sizeof( char* );
	ptrs =
	data = malloc( ptrsSize + sLen + 1 );
	if ( data ) {
		*ptrs =
		_s = strcpy( ( ( char* )data ) + ptrsSize, s );
		if ( nbWords > 1 ) {
			while ( ( _s = strstr( _s, delim ) ) ) {
				*_s = '\0';
				_s += delimLen;
				*++ptrs = _s;
			}
		}
		*++ptrs = NULL;
	}
	if ( nb ) {
		*nb = data ? nbWords : 0;
	}
	return data;
}

char** strsplit( const char* s, const char* delim ) {
	return _strsplit( s, delim, NULL );
}

char** strsplit_count( const char* s, const char* delim, size_t* nb ) {
	return _strsplit( s, delim, nb );
}
