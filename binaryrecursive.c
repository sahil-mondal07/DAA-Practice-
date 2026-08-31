// binary using recursive 
#include<time.h>
#include<stdio.h>
int recursive(int A[], int low , int high , int data);
int main(){
    int size , target;
    printf("enter size of the array : ");
    scanf("%d",&size);
    int a[size];

    for(int i=0;i<size;i++){
        printf("enter elements : ");
        scanf("%d",&a[i]);
    }

    printf("enter target : ");
    scanf("%d",&target);

    clock_t start, end;

    start = clock();

    int result = recursive(a,0,size-1,target);

    end = clock();

    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

    if(result != -1){
        printf("Found at index: %d\n", result);
    }
    else{
        printf("Not found\n");
    }
    
     printf("Time taken: %f seconds\n", time_taken);

     return 0;

}
int recursive(int A[],int low , int high,int data){
    int mid=(low+high)/2;
    if(low>high){
        return -1;
    }
    else if(A[mid]==data){
        return mid;
    }
    else if(A[mid]<data){
        return recursive(A,mid+1,high,data);
    }
    else{
        return recursive(A,low,mid-1,data);
    }
}