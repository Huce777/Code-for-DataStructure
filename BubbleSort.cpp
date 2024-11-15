#include<stdio.h>
#include<stdbool.h>

#define ARR_LEN 255 /*数组长度上限*/

void bubbleSort(int arr[],int len)
{
	int i,j,temp;
	_Bool exchanged = true;
	
	/*exchanged值为true才有必要执行循环，否则值为false不执行循环*/
	for(i=0; exchanged && i<len-1; i++) 
	{
		exchanged = false;
		for(j=0; j<len-i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				exchanged = true;		
			}
		 } 
	}
 } 
 
 int main(void){
 	int arr[ARR_LEN]={3,5,1,-7,4,9,-6,8,10,4};
 	int len=10; // int len=sizeof(len)/sizeof(arr[0])
 	int i;
 	
 	bubbleSort(arr,len);
 	for(i=0;i<len;i++)
 		printf("%d\t",arr[i]);
 	putchar('\n');
 	
 	return 0;
 } 

