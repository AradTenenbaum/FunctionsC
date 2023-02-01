#define _CRT_SECURE_NO_WARNINGS 
#define ERROR -1
#include "string.h"
#include "memory.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Fix bugs
String getString(int length) {
    char c;

    String ptr = malloc(sizeof(char) * length);
    memoryAndFileValidation(ptr);

    int i = 0;
    while (((c = getchar()) != EOF) && (c = getchar()) != '\n')
    {
        ptr[i++] = c;
    }
    ptr[i] = '\0';
    return ptr;
}

// Print string lines between received sepparators using strtok
void printStringSepparatedByChar(String str, String sepparators) {
    String token;
    token = strtok(str, sepparators);
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, sepparators);
    }
}

// Check if a string represent a number by it's ascii
bool isCharDigit(char c) {
    return (c <= '9' && c >= '0');
}

// Convert a string to number using atoi
int convertStringToNumber(String str) {
    for (int i = 0; i < strlen(str); i++)
        if (!isCharDigit(str[i])) return ERROR;
    return atoi(str);
}


