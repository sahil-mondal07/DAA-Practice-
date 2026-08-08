//Write a program to multiply two matrices. Before multiplication, verify whether the given matrices are compatible.
#include<stdio.h>
int main(){
    int a[10][10],b[10][10],c[10][10],i,j,k,r1,c1,r2,c2;
    printf("enter the number of rows and columns of first matrix : ");
    scanf("%d %d",&r1,&c1);
    printf("enter the number of rows and columns of second matrix : ");
    scanf("%d %d",&r2,&c2);
    if(c1!=r2){
        printf("matrice not compatible for multiplication");
        return 0;
    }
    printf("enter the elements of first matrix :");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter the elements of second matrix :");
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            c[i][j]=0;
            for(k=0;k<c1;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    printf("the product of the matrices is : ");
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}