#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int n;
void enter_values(int mat[][n],int m)
{
printf("Enter elements of the matrix\n");
for(int i=0; i<m; i++)
{
for(int j=0; j<n; j++)
{
scanf("%d",&mat[i][j]);
}
}}
void print(int mat[][n], int m)
{
for(int i=0; i<m; i++)
{
for(int j=0; j<n; j++)
{
printf("%d", mat[i][j]);
printf(" ");
}
printf("\n");
}
}
int main(void)
{
printf("Enter the size of an NxN Matrix: ");
scanf("%d",&n);
int mat1[n][n], mat2[n][n];
int sum[n][n];
enter_values(mat1,n);
printf("first matrix is = \n");
print(mat1,n);
enter_values(mat2,n);
printf("second matrix is = \n");
print(mat2,n);
int pid;
for(int k=0; k<n; k++)
{
pid=fork();
if(pid==0)
{
printf("Child %d doing addition of %d row \n",k+1,k+1);
for(int a=0; a<n; a++ )
{
sum[k][a]=mat1[k][a]+mat2[k][a];
}
}
else
{
exit(0);
}
}
printf("Printing the resulting matrix: \n");
print(sum,n);

return 0;
}

