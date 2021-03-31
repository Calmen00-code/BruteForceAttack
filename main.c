#include <stdio.h>
#include <string.h>
#include "header.h"
#include "file.h"

int main(int argc, char *argv[])
{
    int keyA, keyB;
    char cipherFile[STR] = "";
    char *writeFile = "plain.txt";

    if ( argc < 2 )
        printf("To run the program: ./main [cipher.txt]\n");
    else
    {
        keyA = keyB = 0;

        strcpy(cipherFile, argv[1]);

        printf("Key A: ");
        scanf("%d", &keyA);

        printf("Key B: ");
        scanf("%d", &keyB);
    
        readNWrite(cipherFile, writeFile, keyA, keyB); 
    }
    return 0;
}
