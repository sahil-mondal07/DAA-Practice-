// Write a C program to find all pairs of elements in an array whose sum is equal to a given target value. Each pair should be displayed only once. 
//Array: 2 7 4 5 1 3 Target: 6 Output: (2, 4), (5, 1)

#include<stdio.h>
int main(){
    int a[]={1,2,3,4,5,6,7};
    int size=sizeof(a)/sizeof(a[0]);
    int target=7;
    int i,j;
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            if(a[i]+a[j]==target){
                printf("(%d,%d)",a[i],a[j]);
            }
        }
    }
    return 0;
}