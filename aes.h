#ifndef AES_H
#define AES_H

#include <stdint.h>

#define MATRIX_ORDER 4
#define KEY_SIZE 16

typedef uint32_t word;

void encrypt(char* key, char* message);
void decrypt(char* key, char* message);

#endif // AES_H
