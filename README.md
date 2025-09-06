# AES Encryption and Decryption

This is a simple implementation of the AES (Advanced Encryption Standard) algorithm in C. It can be used to encrypt and decrypt 128-bit messages using a 128-bit key.

## Compilation

To compile the project, simply run the `make` command:

```bash
make
```

This will generate two executables: `encrypt` and `decrypt`.

To clean up the compiled files, you can run:

```bash
make clean
```

## Usage

### Encryption

To encrypt a message, use the `encrypt` executable with the following syntax:

```bash
./encrypt <key> <message>
```

### Decryption

To decrypt a message, use the `decrypt` executable with the following syntax:

```bash
./decrypt <key> <encrypted_message>
```

## Input

The `<key>` and `<message>` (or `<encrypted_message>`) must be 128 bits (16 bytes) long. You can provide the input in two formats:

*   **ASCII String:** A 16-character string.
*   **Hexadecimal String:** A 32-character hexadecimal string.

## Example

Here is an example of how to encrypt and decrypt a message:

### Encrypt

```bash
./encrypt "Thats my Kung Fu" "Two One Nine Two"
```

**Output:**

```
Encrypted message:
String: [)???B?%?ޘ?j?%?]
Hex: [29c3505f571420f6402299b31a02d73a]
```

### Decrypt

```bash
./decrypt "Thats my Kung Fu" "$(printf '\x29\xc3\x50\x5f\x57\x14\x20\xf6\x40\x22\x99\xb3\x1a\x02\xd7\x3a')"
```

**Output:**

```
Decrypted message:
String: [Two One Nine Two]
Hex: [54776f204f6e65204e696e652054776f]
```
