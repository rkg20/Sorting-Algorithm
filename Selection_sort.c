#include<stdio.h>
int main(void)
{
  int i,j,n,min,t;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n-1;i++)
  {
    min=i;
    for(j=i+1;j<n;j++)
    {
      if(a[j]<a[min])
      min=j;
    }
    if(min!=i)
    {
      t=a[i];
      a[i]=a[min];
      a[min]=t;
    }
  }
  for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}
