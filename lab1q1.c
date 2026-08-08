//Write a C program to find the second-largest distinct element in an array without sorting it.
#include<stdio.h>
int main(){
    int a[]={12,56,34,89,52,3,15,64,40,87};
    int n=sizeof(a)/sizeof(a[0]);
    int max1=a[0], max2=a[1];
    if(max2>max1){
        int temp=max1;
        max1=max2;
        max2=temp;
    };
    for(int i=2;i<n;i++){
        if(a[i]>max1){
            max2=max1;
            max1=a[i];
        }
        else if(a[i]>max2 && a[i]< max1){
            max2=a[i];
        }
        else if (a[i]==max1 || a[i]==max2){
            continue;
        }
        else if (max2>a[i]){
            continue;
        }
    };
    printf("The second largest distinct element is: %d", max2);
    return 0;
}


