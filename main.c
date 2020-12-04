#include "strsplit.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void printTest( const char* s, const char* delim, char** arr ) {
	printf( "<%s><%s>", s, delim );
	for ( int i = 0; arr[ i ]; ++i ) {
		printf( " [%s]", arr[ i ] );
	}
	printf( "\n" );
}

static void test( const char* s, const char* delim ) {
	char** arr = strsplit( s, delim );

	if ( arr ) {
		printTest( s, delim, arr );
		free( arr );
	}
}

static int comp( const void* a, const void* b ) {
	const char* sa = *( const char** )a;
	const char* sb = *( const char** )b;

	return strcmp( sb, sa );
}

static void testSort( const char* s, const char* delim ) {
	size_t nbWords;
	char** arr = strsplit_count( s, delim, &nbWords );

	if ( arr ) {
		qsort( arr, nbWords, sizeof( *arr ), comp );
		printTest( s, delim, arr );
		free( arr );
	}
}

int main( void ) {
	test( "a", " " );
	test( "a b", " " );
	test( "a b c", " " );
	test( "a", "a" );
	test( "a b", "a" );
	test( "a b", "b" );
	test( "a b c", "b" );
	test( "a b c", " b " );
	test( "a b c d e f g h i j k l m n o p q r s t u v w x y z", " " );
	test( "a bc def ghij klmno pqrstu vwxyz", " " );
	test( "a.:.bc.:.def.:.ghij.:.klmno.:.pqrstu.:.vwxyz", ".:." );
	test( ".:.a.:.bc.:.def.:.ghij.:.klmno.:.pqrstu.:.vwxyz.:.", ".:." );
	test( "abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz" );
	test( "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz" );
	test( "abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz_" );

	testSort( "a", " " );
	testSort( "a b", " " );
	testSort( "a b c", " " );
	testSort( "a", "a" );
	testSort( "a b", "a" );
	testSort( "a b", "b" );
	testSort( "a b c", "b" );
	testSort( "a b c", " b " );
	testSort( "a b c d e f g h i j k l m n o p q r s t u v w x y z", " " );
	testSort( "a bc def ghij klmno pqrstu vwxyz", " " );
	testSort( "a.:.bc.:.def.:.ghij.:.klmno.:.pqrstu.:.vwxyz", ".:." );
	testSort( ".:.a.:.bc.:.def.:.ghij.:.klmno.:.pqrstu.:.vwxyz.:.", ".:." );
	testSort( "abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz" );
	testSort( "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz" );
	testSort( "abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz_" );
	return 0;
}
