//7. Write a C program to rotate an array to the right by K positions without using another array. 
//Array: 1 2 3 4 5 6 K = 2 Output: 5 6 1 2 3 4

#include<stdio.h>
int main(){
    int n;
    printf("enter how many times to rotate : ");
    scanf("%d",&n);
    int arr[]={4,8,6,4,1,12,9,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k =0;
    while(k<n){
        int last=arr[size-1];
        for(int i=size-1;i>=1;i--){
            arr[i]=arr[i-1];
        } 
        arr[0]=last;
        k++;
    }
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);

    }

    return 0;
}