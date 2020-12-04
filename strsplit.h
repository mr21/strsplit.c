#ifndef _strsplit_h
#define _strsplit_h

#include <stddef.h>

char** strsplit( const char* s, const char* delim );
char** strsplit_count( const char* s, const char* delim, size_t* nb );

#endif
