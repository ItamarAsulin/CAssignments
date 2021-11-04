#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int factorial(int num) {
    int ans = 1;
    for (int i = 1; i <= num; ++i) {
        ans *= i;
    }
    return ans;
}

int isPrime(int num) {
    if(num == 1){
        return 1;
    }
    int rootOfNum = sqrt(num);
    for (int i = 2; i < rootOfNum + 1; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int isStrong(int num) {
    int ans = 0;


    int length = snprintf(NULL, 0, "%d", num);

    char *numToString = malloc(length + 1);
    sprintf(numToString, "%d", num);

    for (int i = 0; i < length; ++i) {
        int currentNum = 0;
        char c = numToString[i];
        currentNum = c - '0';
        ans += factorial(currentNum);
    }
    if (ans == num) {
        return 1;
    }
    return 0;

}
