#include<stdio.h>
#include<time.h>

int binarysearch(int a[], int n, int data);
int main(){
    int target, size;
    printf("enter size of array : ");
    scanf("%d",&size);
    int A[size];
    
    for(int i = 0; i<size;i++){
        printf("enter elements of the array : ");
        scanf("%d",&A[i]);
    }

    printf("enter the target element : ");
    scanf("%d",&target);

    clock_t start, end;
    start = clock();

    int result = binarysearch(A,size,target);

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
int binarysearch(int a[],int n,int data){
    int low = 0, high = n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==data) return mid;
        else if(a[mid]<data) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
