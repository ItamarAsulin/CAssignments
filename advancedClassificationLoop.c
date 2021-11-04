//
// Created by itamarq on 25/10/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//int isArmstrong(int n){
//    int counter =0;
//    int checker=n;
//    int sum=0;
//    int x=0;
//    while (checker!=0){
//        checker=checker/10;
//        counter++;
//    }
//    checker=n;
//    for (int i = 0; i <counter ; i++) {
//        int m=1;
//        x=checker%10;
//        for (int j = 0; j <counter ; j++) {
//            m=m*x;
//        }
//        int sum1=m;
//        sum=sum+sum1;
//        checker=checker/10;
//    }
//    if (sum==n) {
//        return 1;
//    }
//    else{
//        return 0;
//    }
//
//}


int isArmstrong(int num){
    if(num < 10){
        return 1;
    }
    int ans =0;
    int length = snprintf(NULL, 0, "%d", num);
    char stringOfNum [length +1 ];
    snprintf(stringOfNum, length +1, "%d", num);


    for (int i = 0; i <length ; ++i) {
        char currentIth = stringOfNum[i];
        int currNum = currentIth - '0';
        ans += pow(currNum, length);
    }
    if(ans == num){
        return 1;
    }
    return 0;
}

int isPalindrome(int num){
    int length = snprintf(NULL, 0, "%d", num);
    char *stringOfNum = malloc(length + 1);
    snprintf(stringOfNum, length +1, "%d", num);
    int i =0;
    int j = length -1;
    for (i = 0; i <= j; i++, j--) {
        if(stringOfNum[i] != stringOfNum[j]){
            return 0;
        }
    }
    return 1;
}
//int main(){
//
//    int test = 5;
//    int ans = isArmstrong(test);
//    printf("%d", ans);
//    return 0;
//}



