#include <stdio.h>
#include "aes.h"

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Usage: %s <key> <encripted message>\n", argv[0]);
        return 1;
    }

    char* key = argv[1];
    char* message = argv[2];
    
    decrypt(key, message);

    printf("Decrypted message:\n");

    printf("String: %s\nHex: ", message);
    for(int i = 0; *(message + i); i++) printf("%02x", (unsigned char)*(message + i));
    printf("\n");

    return 0;
}
