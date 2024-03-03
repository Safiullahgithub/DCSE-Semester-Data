#include<stdio.h>
#include<pthread.h>
#define T 2
#define n 2
int A[n][n]={{9,5},{7,2}};
int B[n][n]={{5,6},{1,5}};
int C[n][n]={{0}};
void *add(void *arg)
{
int id=*(int*)arg;
for(int i=id; i<n; i+=T)
{
for(int j=0; j<n; j++)
{
C[i][j]=A[i][j]+B[i][j];
}
}
pthread_exit(NULL);
}
int main()
{
pthread_t tid[T];
int t[T];
for(int i=0; i<T; i++)
{
t[i]=i;
pthread_create(&tid[i],NULL,add,&t[i]);
}
for(int i=0; i<T; i++)
{
pthread_join(tid[i],NULL);
}
for(int i=0; i<n; i++)
{
for (int j=0; j<n; j++)
{
printf((j<n-1)? "%d ":"%d\n",C[i][j]);
}
}
return 0;
}
