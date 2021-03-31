#ifndef ALPHABET
#define ALPHABET

#define NUM_CHARS 26
#define DIFF 32
#define FIRST_LOWER 97
#define FIRST_UPPER 65

#include "header.h" /* Boolean value */

int isUpper( char );
int isLower( char );
int isAlpha( char );
char toUpper( char );
char toLower( char );
char asciiToUpper( int );
char asciiToLower( int );

#endif
