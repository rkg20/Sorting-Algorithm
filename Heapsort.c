#include<stdio.h>
#include<stdlib.h>
void max_heap(int *a,int i,int n)
{
	int l,r,largest,temp,k;
	l=2*i+1;
	r=2*i+2;
	largest=i;
	if(l<n&&*(a+l)>*(a+i))
		largest=l;
	if(r<n&&*(a+r)>*(a+largest))
		largest=r;
	if(largest!=i)
	{
		temp=*(a+largest);
		*(a+largest)=*(a+i);
		*(a+i)=temp;
		max_heap(a,largest,n);
	}
}
void heapify(int *a,int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
		max_heap(a,i,n);
}
void heapSort(int *a,int n)
{
	int temp,i=1,k,j;
	heapify(a,n);
	for(i=n;i>=2;i--)
	{
		temp=*(a+i-1);
		*(a+i-1)=*(a+0);
		*(a+0)=temp;
		printf("\nAfter pass %d elements are :",j++);
		for(k=0;k<n;k++)
			printf("%d\n",*(a+k));
		max_heap(a,0,i-1);
	}
}
int main()
{
	int i,*a,n;
	printf("Enter the number of element :");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("\nEnter elements to be sorted :");
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	heapSort(a,n);
	printf("\nSORTED ELEMENT \n\n");
	for(i=0;i<n;i++)
		printf("%4d",*(a+i));
	return 0;
}
