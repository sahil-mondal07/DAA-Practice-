#inlcude<stdio.h>                   // 0=dont know , 1=knows 
int main(){
    int r,c;
    printf("enter no. of rows : ");
    scanf("%d",&r);
    printf("enter no. of col : ");
    scanf("%d",&c);
    int mat[r][c];
    for(int i = 0;i<r;i++){
        for(int j=0;j<r;j++){
            scanf("%d",&mat[i][j]);
        }
    }

    int a=0
    int b=1;
    while(b<r){
        if(mat[a][b]==1){
            a=b;
            b++;
        }
        else{
            b++;
        }
    }
    int candidate=a;
    for(int i=0;i<r;i++){
        if(i==candidate){
            if(mat[candidate][i]!=1){   //check if cand. knows himself
                printf("not the celebrity");
                return 0;
            }
        }
        else{
            if(mat[candidate][i]!=0){   // check if cand. knows anyother person
                printf("not the celebrity");
                return 0;
            }
            if(mat[i][candidate]==0){
                printf("not the celebrity");
                return 0;
            }
        }
    }
    printf("the celebrity is : %d\n",candidate);
    return 0;
}