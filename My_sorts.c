/*This is my sorting code, this code will have
merge sort, binary sort, insert sort, quick sort*/


#include <stdio.h>
#include <stdlib.h>
int i,j;
void insert_sort(int *array_num,int size);
int two_sum(int *array_num,int size);

void insert_sort(int *array_num,int size)  //this is the insertion sorting function
{
	int key,j;  //key varible is needed for keeping to current element in the array
	
	
	for(i=1;i<size;i++)
	{
		key=array_num[i];   //key equals the current element in the array to the 
		j=i-1;              //j starts at 1 - i means if i=2 than j=1
		
		while(j>=0 && array_num[j]>key)    //make sure j is not negative, compare the j element 
		{								   //in the array to the key element which is the current element
			array_num[j+1]=array_num[j];    //if the j element is larger than set j+1 to j which means
			j=j-1;                          //switch the j+1 element with j
		}                                   //than j-1 is for going throug the loop again
		
		array_num[j+1]=key;					//this will place the current element key to the j+1 element
	                                        //this will place the biggest element at the end of the array
	}

}

int two_sum(int *array_num,int size)
{
	int target,i,sum,p,t;
	int sum_array[2]={0,0};
	
	printf("Enter a target value\n");
	scanf("%d",&target);
	
	for(i=0;i<size;i++)
	{
		t=i+1;//array_num[i+1];
		p=i;
		
		while(t<size){
			sum=array_num[t]+array_num[p];
			
			if(array_num[p]==array_num[t])
				t++;
			
			else if(array_num[p]!=array_num[t] && sum==target){
				sum_array[0]=array_num[p];
				sum_array[1]=array_num[t];
				printf("%d %d\n",sum_array[0],sum_array[1]);
				break;
			}
			else
				t++;
		}
	
	}

	if(sum_array[0]==0&&sum_array[1]==0&&target!=0)
		printf("None of the summation in the array equaled to the target value\n");
	
}














int main(int argc, int *argv[])
{
	int *array_num;
	int size,target;
	array_num=(int*) malloc(size* sizeof(int));
	
	printf("Enter the size of the array\n");
	scanf("%d",&size);
	
	
	printf("Enter numbers in the array\n");
	
	for(i=0;i<size;i++)
		scanf("%d",&array_num[i]);

	two_sum(array_num,size);
	//insert_sort(array_num,size);
	
	/*for(j=0;j<size;j++)
		printf("%d ",array_num[j]);

	
	printf("\n");*/
	return 0;
}
