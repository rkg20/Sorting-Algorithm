#include<stdio.h>
void quick(int a[],int lb,int ub);
int partition(int a[],int lb,int ub)
{
int pivot=a[lb];
int start=lb;
int end=ub;
 while(start<end)
{
  while(a[start]<=pivot)
  {
    start++;
  }
  while(a[end]>pivot)
  {
    end--;
  }
if(start<end)
 {
  int t= a[start];
    a[start]=a[end];
    a[end]=t;
 }
}
    int t=a[lb];
    a[lb]=a[end];
    a[end]=t;
    return end;
}
void quick(int a[],int lb,int ub)
{
  if(lb<ub)
  {
  int p=partition(a,lb,ub);
      quick(a,lb,p-1);
      quick(a,p+1,ub);
  }
}
int main(void)
{
  int i,n;
  printf("enter size\n");
  scanf("%d",&n);
int a[n];
   printf("enter element\n");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
    quick(a,0,n-1);
for(i=0;i<n;i++)
   printf("%d\t",a[i]);
}


