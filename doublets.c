//find doublets in an array that sum to a given element..


# include<stdio.h>
# include<stdlib.h>
int main()
{
	int arr1[]={1,2,3,4,7,5};
	int arr2[]={0,4,5,3,2,7};
	int n=sizeof(arr1)/sizeof(arr1[0]);
	int m=sizeof(arr2)/sizeof(arr2[0]);
	int x=8;
	int i,j;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	if(arr1[i]+arr2[j]==x)
	printf("elements are %d, %d",arr1[i],arr2[j]);
}

