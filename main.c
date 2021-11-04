//
// Created by itamarq on 26/10/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "NumClass.h"

int main(){
    int min;
    int max;
    int inputA;
    int inputB;
    int lengthOfArrays;
    int indexForPalindromes = 0;
    int indexForArmstrong = 0;
    int indexForPrime = 0;
    int indexForStrong = 0;

    printf("Please enter first number; \n");
    scanf("%d", &inputA);
    printf("Please enter the second number: \n");
    scanf("%d", &inputB);
    if(inputA <= inputB){
        min = inputA;
        max = inputB;
    }else{
        min = inputB;
        max = inputA;
    }
    lengthOfArrays = max - min;
    int palindromeNumbers[lengthOfArrays];
    int armstrongNumbers[lengthOfArrays];
    int primeNumbers[lengthOfArrays];
    int strongNumbers[lengthOfArrays];

    for (int i = min; i <= max ; ++i) {
        if(isPalindrome(i) == 1){
            palindromeNumbers[indexForPalindromes] = i;
            indexForPalindromes++;
        }
        if(isArmstrong(i) == 1){
            armstrongNumbers[indexForArmstrong] = i;
            indexForArmstrong++;
        }
        if(isPrime(i) == 1){
            primeNumbers[indexForPrime] = i;
            indexForPrime++;
        }
        if(isStrong(i) == 1){
            strongNumbers[indexForStrong] = i;
            indexForStrong++;
        }
    }
    printf("The Armstrong numbers are:");
    for (int i = 0; i < indexForArmstrong; ++i) {
        int currentNUm = armstrongNumbers[i];
        printf(" %d", currentNUm);
    }
    printf("\nThe Palindromes are:");
    for (int i = 0; i <indexForPalindromes ; ++i) {
        int currentNum = palindromeNumbers[i];
        printf(" %d", currentNum);
    }
    printf("\nThe Prime numbers are:");
    for (int i = 0; i <indexForPrime ; ++i) {
        int currentNum = primeNumbers[i];
        printf(" %d", currentNum);
    }
    printf("\nThe Strong numbers are:");
    for (int i = 0; i <indexForStrong ; ++i) {
        int currentNum = strongNumbers[i];
        printf(" %d", currentNum);
    }
    printf("\n");
    return 0;


}