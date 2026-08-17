// Write a program to count the frequency of each distinct element in an array.
#include<stdio.h>
int main(){
    int a[]={2,5,2,67,10,5,67,2,10};
    int size=sizeof(a)/sizeof(a[0]);
    int count =0;
    for(int i=0;i<size;i++){ //this loop to get inside the array 
        count =1 ;
        for(int j=i+1;j<size;j++){ //this loop for count 
            if(a[i]==a[j]){
                count++;
                a[j]=-1;
            }
        }
        if(a[i]!=-1){
            printf("Element %d occurs %d times\n", a[i], count);
        }
    }
    return 0;
}