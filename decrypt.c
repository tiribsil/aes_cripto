#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aes.h"

int hex_char_to_int(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'a' && c <= 'f') return c - 'a' + 10;
        if (c >= 'A' && c <= 'F') return c - 'A' + 10;
        return -1;
}

void hex_to_bytes(const char* hex_str, char* byte_array, int hex_len) {
        for(int i = 0; i < hex_len; i += 2){
                    int high_nibble = hex_char_to_int(hex_str[i]);
                    int low_nibble = hex_char_to_int(hex_str[i + 1]);
                    if(high_nibble == -1 || low_nibble == -1) {
                        fprintf(stderr, "Invalid hex character in input.\n");
                        exit(1);
                    }
                    byte_array[i >> 1] = (unsigned char)((high_nibble << 4) | low_nibble);
                }
}

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Usage: %s <key> <encripted message>\n", argv[0]);
        return 1;
    }

    char* key = argv[1];
    char* message = argv[2];

    int len_key = strlen(key);
    int len_message = strlen(message);

    if((len_key != 16 && len_key != 32) || (len_message != 16 && len_message != 32)){
        printf("Key and message must be 128 bits (16 bytes) long.\n");
        return 1;
    }

    if(len_key == 32) hex_to_bytes(key, key, len_key);
    if(len_message == 32) hex_to_bytes(message, message, len_message);

    decrypt(key, message);

    printf("Decrypted message:\n");

    printf("String: [%.16s]\nHex: [", message);
    for(int i = 0; i < KEY_SIZE; i++) printf("%02x", (unsigned char)*(message + i));
    printf("]\n");

    return 0;
}
