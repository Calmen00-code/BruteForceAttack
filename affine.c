#include <stdio.h>
#include "header.h"
#include "affine.h"
#include "alphabet.h"
#include "euclidean.h"

void encrypt( char *plaintext, char *ciphertext, int keyA, int keyB )
{
    int i, value;
    char c = ' ';

    if ( plaintext != NULL )
    {
        value = 0;
        for ( i = 0; plaintext[i] != '\0'; ++i )
        {
            if ( isAlpha( plaintext[i] ) == TRUE )
            {
                if ( isLower( plaintext[i] ) == TRUE )
                {
                    value = getIntLow( plaintext[i] ); 
                    value = processEncrypt( value, keyA, keyB );
                    c = asciiToLower( value );
                }
                else
                {
                    value = getIntUp( plaintext[i] );
                    value = processEncrypt( value, keyA, keyB );
                    c = asciiToUpper( value );
                }
                ciphertext[i] = c;
            }
            else
                ciphertext[i] = plaintext[i];   /* Other symbols such as ' ', '$' etc. */
        }
    }
}

void decrypt( char *ciphertext, char *plaintext, int keyA, int keyB )
{
    int i, value;
    char m = ' ';

    if ( ciphertext != NULL )
    {
        value = 0;
        for ( i = 0; ciphertext[i] != '\0'; ++i )
        {
            if ( isAlpha( ciphertext[i] ) == TRUE )
            {
                if ( isLower( ciphertext[i] ) == TRUE )
                {
                    value = getIntLow( ciphertext[i] ); 
                    value = processDecrypt( value, keyA, keyB );
                    m = asciiToLower( value );
                }
                else
                {
                    value = getIntUp( ciphertext[i] );
                    value = processDecrypt( value, keyA, keyB );
                    m = asciiToUpper( value );
                }
                plaintext[i] = m;
            }
            else
                plaintext[i] = ciphertext[i];
        }
    }
}

/**
IMPORT: character from the text
EXPORT: integer value of the character from the table
PURPOSE: Get the integer value of the lowercase character in the table
*/
int getIntLow( char character )
{
    char ch = 'a';
    int value = 0;

    while ( ch >= 'a' && ch <= 'z' && ch != character )
    {
        ++ch;
        ++value;
    }
    return value;
}

/**
IMPORT: character from the text
EXPORT: integer value of the character from the table
PURPOSE: Get the integer value of the uppercase character in the table
*/
int getIntUp( char character )
{
    char ch = 'A';
    int value = 0;

    while ( ch >= 'A' && ch <= 'Z' && ch != character )
    {
        ++ch;
        ++value;
    }
    return value;
}

/**
IMPORT: integer value of the plain character, key used
EXPORT: integer value after computing encryption by caesar cipher
PURPOSE: Computes the formula of caesar cipher encryption
*/
int processEncrypt( int mValue, int keyA, int keyB )
{
    int cValue = 0;
    cValue = ((mValue * keyA) + keyB) % NUM_CHARS;
    return cValue;
}

/**
IMPORT: integer value of the cipher character, key used
EXPORT: integer value after computing decryption by caesar cipher
PURPOSE: Computes the formula of caesar cipher encryption
*/
int processDecrypt( int cValue, int keyA, int keyB )
{
    int x, y;
    int mValue = 0;
    int ans = 0;

    /* Using NUM_CHARS as affine ciphers is mod NUM_CHARS */
    extendedEuclidean( keyA, NUM_CHARS, &x, &y );

    /* Check if it is inverse negative modulo */
    /* Convert it to positive equivalent as the table is 0 to 25 */
    if ( x < 0 ) 
        x += NUM_CHARS; 

    /* Check if the value is negative */
    ans = cValue - keyB;
    if ( ans < 0 )
        ans += NUM_CHARS;   /* Convert to positive as the table is 0 to 25 */

    mValue = (x * (ans)) % NUM_CHARS;

    return mValue;
}
