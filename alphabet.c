#include "alphabet.h"

int isAlpha( char ch )
{
    int alphabet = FALSE;

    if ( isLower( ch ) == TRUE || isUpper( ch ) == TRUE )
        alphabet = TRUE;
    return alphabet;
}       

int isLower( char ch )
{
    int lower = FALSE;

    if ( ch >= 'a' && ch <= 'z' )
        lower = TRUE;
    return lower;
}

int isUpper( char ch )
{
    int upper = FALSE;  

    if ( ch >= 'A' && ch <= 'Z' )
        upper = TRUE;
    return upper;
}       

char toUpper( char ch )
{   
    if ( isLower( ch ) == TRUE )
        ch = ch - DIFF;
    return ch;
}

char toLower( char ch )
{
    if ( isUpper( ch ) == TRUE )
        ch = ch + DIFF;
    return ch;
}

char asciiToLower( int value )
{
    char ch = ' ';

    value += FIRST_LOWER;
    ch = (char)(value);
    return ch;
}

char asciiToUpper( int value )
{
    char ch = ' ';

    value += FIRST_UPPER;
    ch = (char)(value);
    return ch;
}
