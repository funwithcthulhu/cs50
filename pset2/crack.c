#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define SALT "50"

int key_check(char *key, char *hash);

int main(int argc, char *argv[])
{
    // Check for 1 input argument
    if (argc != 2) {
        printf("Usage ./crack hash\n");
        return 1;
    }

    // put input arg1 into hash variable
    char *hash = argv[1];

    // create array with all characters that can possibly appear in pw to be cracked
    char *input = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // initialize a string of 5 bytes (the assignment specified the pw can be max 4 characters long)
    char key[5];

    // set all idx of the string = to null
    //for (int i = 0; i < 5; i++) {
    //    key[i] = '\0';
    //}


    for (int i = 0, n = strlen(input); i < n; i++) {
        key[0] = input[i];
        key[1] = '\0';
        if (key_check(key, hash)) {
            printf("%s\n", key);
            return 0;
        }
        for (int j = 0; j < strlen(input); j++) {
            key[0] = input[i];
            key[1] = input[j];
            key[2] = '\0';
            if (key_check(key, hash)) {
                printf("%s\n", key);
                return 0;
            }
            for (int k = 0; k < strlen(input); k++) {
                key[0] = input[i];
                key[1] = input[j];
                key[2] = input[k];
                key[3] = '\0';
                if (key_check(key, hash)) {
                    printf("%s\n", key);
                    return 0;
                }
                for (int m = 0; m < strlen(input); m++) {
                    key[0] = input[i];
                    key[1] = input[j];
                    key[2] = input[k];
                    key[3] = input[m];
                    if (key_check(key, hash)) {
                        printf("%s\n", key);
                        return 0;
                    }
                }
            }
        }
    }
}

// checks if the key, when crypted with the SALT, equals the input hash
int key_check(char *key, char *hash)
{
    key = crypt(key, SALT);
    if (strcmp(key, hash) == 0) {
        return 1;
    }
    return 0;
}