#include<stdio.h>
int main(){
    int n,p;
    printf("enter the no. : ");
    scanf("%d",&n);
    printf("enter the power : ");
    scanf("%d",&p);
    int result =1;
    for(int i =0;i<p;i++){
        result*=n;
    }
    printf("result is : %d \n",result);
    return 0;
}