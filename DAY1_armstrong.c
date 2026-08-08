#include<stdio.h>
#include<math.h>//power function ke liye math module include kar rhe hai

int main(){
    int n, temp, digit = 0, sum = 0, rem;
    printf("Enter the number: ");
    scanf("%d", &n);
    temp = n; //no. of digit count hoga 
    while(temp != 0){
        digit++;
        temp = temp / 10;
    } 
    temp = n; //jitna digit count hoga uska power har ek no. pe lagake add hoga
    while(temp != 0){
        rem = temp % 10;             //last digit nikalne ke liye 
        sum += (int)pow(rem, digit); 
        temp = temp / 10;
    }
    if(sum == n)
        printf("%d is an Armstrong number.\n", n);
    else
        printf("%d is NOT an Armstrong number.\n", n);

    return 0;
}