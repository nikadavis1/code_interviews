#include <stdio.h>

void bubble_sort(int[], int);
int swap(int, int);


void bubble_sort(int data[], int num_elts)
{
     int i,j,temp=0;
	 for(i=0; i < num_elts-1; i++)        //iterates through the whole array
	 {	 
		for(j=0; j < num_elts-1 - i; j++)  
		{
			if(data[j] > data[j+1])       //checks to see if the previous element is greater
			{                             //than the current element
			temp=data[j];                 //place the current element in a temperary varible
			data[j]=data[j+1];            //switch the elements in array
			data[j+1]=temp;               
			}
	 
		}
 
     }
		 
}


int main(void)
{
	int index, data[10] = {10,3,4,8,2,5,9,7,1,6};
	
	bubble_sort(data, 10);
	
	for (index = 0; index < 10; index++)
	{
		printf("%d",data[index]);
	}
	
	printf("\n");
	
	return 0;

}
