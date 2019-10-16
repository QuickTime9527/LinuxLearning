#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void show(int *a,int n)
{
  int i,m;
  for(i=0;i<n;i++)
	printf("%4d  :  %4d\n",i,a[i]);
}
void initarray(int *a,int n)
{
  int i;
  srand(time(NULL));
  for(i=0;i<n;i++)
	a[i] = rand()%1000+1000;

}
