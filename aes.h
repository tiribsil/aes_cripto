#ifndef AES_H
#define AES_H

#include <stdint.h>

typedef uint32_t word;

void encrypt(char* key, char* message);
void decrypt(char* key, char* message);

#endif // AES_H
