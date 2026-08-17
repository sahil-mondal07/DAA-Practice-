/* Student Result Analysis
 • Store the roll number, name, and marks in five subjects for N students using structures. 
 • Calculate the total, percentage, and grade of each student.
 • Display the class topper, students who failed in one or more subjects, and the class average.*/
 
 #include<stdio.h>
 struct student{
    int roll;
    char name[100];
    int marks[5];
    int total;
    float percent;
    char grade;
 };

 int main(){
    int n;
    printf("enter the no. of stud: ");
    scanf("%d",&n);
    struct student students[n];
    for(int i=0;i<n;i++){
        printf("enter detail of the stud : ",i+1);
        printf("roll : ");
        scanf("%d",&students[i].roll);
        printf("name : ");
        scanf("%s",students[i].name);
        students[i].total=0;
        printf("enter marks of 5 sub : ");
        
        }
 } 