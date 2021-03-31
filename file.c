#include <stdio.h>
#include "header.h"
#include "file.h"
#include "alphabet.h"
#include "affine.h"

void readNWrite( char *cipherFile, char *fileWrite, int keyA, int keyB )
{
    char readChar, writeChar;
    int readVal;
    int plainVal;
    FILE *readPtr = NULL, *writePtr = NULL;

    readPtr = fopen(cipherFile, "r");
    writePtr = fopen(fileWrite, "w");

    printf("\n\n");
    if ( readPtr == NULL )
        perror("Error while reading file ");
    else if ( writePtr == NULL )
        perror("Error while writing file ");
    else
    {
        readChar = writeChar = ' ';

        readChar = fgetc( readPtr );
        while ( readChar != EOF )
        {
            if ( isAlpha( readChar ) == TRUE )
            {
                /* Get the value of the character in the table */
                if ( isLower( readChar ) == TRUE )
                {
                    readVal = getIntLow( readChar ); 
                    plainVal = processDecrypt( readVal, keyA, keyB );
                    writeChar = asciiToLower( plainVal ); 
                }
                else
                {
                    readVal = getIntUp( readChar ); 
                    plainVal = processDecrypt( readVal, keyA, keyB );
                    writeChar = asciiToUpper( plainVal ); 
                }
                fprintf(writePtr, "%c", writeChar);
                printf("%c", writeChar);
            }
            else
            {
                fprintf(writePtr, "%c", readChar);  /* No changes from the readChar */
                printf("%c", readChar);
            }
            readChar = fgetc( readPtr );
        }
        fclose(readPtr);
        fclose(writePtr);
        readPtr = NULL;
        writePtr = NULL;
    }
}
