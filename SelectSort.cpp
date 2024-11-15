#include<stdio.h>

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selectionSort(int arr[],int len){
	
	for(int i=0;i<len-1;i++){
		int min = i;
		
		for(int j=i+1;j<len;j++){
			if(arr[j]<arr[min]){
				min = j;
			}
		}
		swap(&arr[min],&arr[i]);
	}
}

int main(){
	int arr[]={15,65,2,6,14,74,25,3,26,1,4,5,11,97};
	int len = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr,len);
	for(int i=0;i<len;i++)
		printf("%d\t",arr[i]);
	putchar('\n');
	
	return 0;
}

