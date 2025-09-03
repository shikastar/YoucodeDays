#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_SIZE 100000

void    printBinary(int n) {
    if (n == 0) {
        printf("0\n");
        return ;
    }
    char bin[32] = {0};
    int i = 0;
    while (n) {
        
        if (n & 1) bin[i] = 1;
        i++;
        n /= 2;
    }
    while (--i >= 0) printf("%d", bin[i]); 
    printf("\n");
}

void    printHex(int n, const char *hex) {
    if (n < 16) {
        printf("%c", hex[n % 16]);
        return ;
    }
    printHex(n / 16, hex);
    int rest = n % 16;
    printf("%c", hex[rest]);
}


bool    isDigit(char c) {
    return (c <= '9' && c >= '0');
}

bool    isInvalidInteger(const char *num) {
    if (num == NULL) return 0;

    long long number = 0;

    for (int i = 0; num[i]; i++) {
        if (!isDigit(num[i])) return true;
        number = number * 10 + num[i] - '0';
        if (number > INT_MAX) return true;
    }
    return false;
}

int stringTointeger(char *num) {
    int number = 0, i = 0;
    while (num[i]) {
        number = number * 10 + (num[i] - '0');
        i++;
    }
    return number;
}

int readInput(void) {
    char number[MAX_SIZE];
    do {
        printf("Please enter a positive integer number:\n");
        scanf("%s", number);
    } while (isInvalidInteger(number));

    return stringTointeger(number);
}

int main() {
    int n = readInput();

    printf("Binary representation of %d:\n", n);
    printBinary(n);

    printf("=================================\n");
    printf("Hexadecimal representation of %d:\n", n);
    printHex(n, "0123456789ABCDEF");
    printf("\n");
}
