//
// Created by itamarq on 26/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int recursionForArmstrong(int num, int power) {
    if (num == 0) {
        return 0;
    }
    if (num > 0) {
        return pow(num % 10, power) + recursionForArmstrong(num / 10, power);
    } else {
        return 0;
    }

}

int recursionForPalindrome(char num[]) {
    int length = strlen(num);
    if (length == 1) {
        return 1;
    }
    if (length == 2) {
        if (num[0] == num[1]) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (num[0] == num[length-1]) {
            char subString[length-2];
            for (int i = 1; i <length-1 ; ++i) {
                subString[i-1] = num[i];
            }
            return recursionForPalindrome(subString);
        } else {
            return 0;
        }
    }
}


int isArmstrong(int num){
    int length = snprintf(NULL, 0, "%d", num);
    if(length ==1){
        return 1;
    }
    int result = recursionForArmstrong(num, length);
    if( result == num){
        return 1;
    }else{
        return 0;
    }
}

int isPalindrome(int num) {

    int length = snprintf(NULL, 0, "%d", num);
    char *stringOfNum = malloc(length + 1);
    snprintf(stringOfNum, length + 1, "%d", num);
    return recursionForPalindrome(stringOfNum);
//    if (stringOfNum[0] == stringOfNum[length - 1]) {
//        char *stringOfNewNum = malloc(length - 1);
//        for (int i = 0; i < length - 2; ++i) {
//            stringOfNewNum[i] = stringOfNum[i + 1];
//        }
//        int newNum = atoi(stringOfNewNum);
//        return isPalindrome(newNum);
//    } else {
//        return 0;
//    }


}