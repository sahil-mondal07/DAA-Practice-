    // Write a program to check whether a given string is a palindrome. Ignore spaces and differences between uppercase and lowercase letters.
#include<stdio.h>
#include<string.h>
#include<ctype.h>//characters ko direclty func se lower and upper me convert kar sakte hai 
int main(){
    char str[100];
    printf("enter a string : ");
    scanf("%s", str);
    int len =strlen(str);
    int right=len-1;
    int left=0;
    int palindrome=1;
    while(left<right){
        if(tolower(str[left])!=tolower(str[right])){ 
            palindrome = 0;
            break;
        }
        left++;
        right--;
    }
    if(palindrome==1){
        printf("the string is palindrome");
    }
    else{
        printf("string is not palindrome");
    }
    return 0;

}