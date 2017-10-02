#include "strsplit.h"

char** strsplit( const char* s, const char* del ) {
	void* data;
	char* _s = ( char* )s;
	const char** ptrs;
	unsigned int
		ptrsSize,
		sLen = strlen( s ),
		delLen = strlen( del ),
		nbWords = 1;

	while ( ( _s = strstr( _s, del ) ) ) {
		_s += delLen;
		++nbWords;
	}
	ptrsSize = ( nbWords + 1 ) * sizeof( char* );
	ptrs = data = malloc( ptrsSize + sLen + 1 );
	if ( data ) {
		*ptrs = _s = strcpy( ( ( char* )data ) + ptrsSize, s );
		if ( nbWords > 1 ) {
			while ( ( _s = strstr( _s, del ) ) ) {
				*_s = '\0';
				_s += delLen;
				*++ptrs = _s;
			}
		}
		*++ptrs = NULL;
	}
	return data;
}
