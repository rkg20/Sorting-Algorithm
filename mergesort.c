#include<stdio.h>
int merge(int a[],int lb,int mid,int ub);
int mergesort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
          mergesort(a,lb,mid);
          mergesort(a,mid+1,ub);
          merge(a,lb,mid,ub);
    }
}
int merge(int a[],int lb,int mid,int ub)
{
    int i=lb,j=mid+1,k=lb;
    int b[ub+1];
      while(i<=mid&&j<=ub)
      {
        if(a[i]<=a[j])
        {
          b[k]=a[i];
          k++;
          i++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
      if(i>mid)
      {
        while(j<=ub)
        {
            b[k]=a[j];
            k++;
            j++;
        }

     }
        else
        {
            while(i<=mid)
            {
                b[k]=a[i];
                 k++;
                 i++;
            }
        }
        
    
       for(k=lb;k<=ub;k++)
        a[k]=b[k];
}
int main(void)
{
    int i,n;
      printf("enter the size\n");
      scanf("%d",&n);
    int a[n];
      printf("enter the element\n");
        for(i=0;i<n;i++)
           scanf("%d",&a[i]);
         mergesort(a,0,n-1);
         for(i=0;i<n;i++)
            printf("%d\t",a[i]);
    return 0;
}
