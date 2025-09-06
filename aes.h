#ifndef AES_H
#define AES_H

#define MATRIX_ORDER 4
#define KEY_SIZE 16

void encrypt(char* key, char* message);
void decrypt(char* key, char* message);

#endif // AES_H
