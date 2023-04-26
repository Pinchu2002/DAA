#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// swaping function
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
// heapify function
void buildMaxHeap(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // if child is bigger than parent
        if (arr[i] > arr[(i - 1) / 2])
        {
            int j = i;
     
            // swap child and parent until
            // parent is smaller
            while (arr[j] > arr[(j - 1) / 2])
            {
                int temp=arr[j];
                arr[j]=arr[(j-1)/2];
                arr[(j-1)/2]=temp;
                j = (j - 1) / 2;
            }
        }
    }
}

// heapsort function
void heapsort(int arr[], int n){
	buildMaxHeap(arr, n);
 
    for (int i = n - 1; i > 0; i--)
    {
        // swap value of first indexed
        // with last indexed
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
     
        // maintaining heap property
        // after each swapping
        int j = 0, index;
         
        do
        {
            index = (2 * j + 1);
             
            // if left child is smaller than
            // right child point index variable
            // to right child
            if (arr[index] < arr[index + 1] &&
                                index < (i - 1))
                index++;
         
            // if parent is smaller than child
            // then swapping parent with child
            // having higher value
            if (arr[j] < arr[index] && index < i)
            {
                int tem1=arr[j];
                arr[j]=arr[index];
                arr[index]=tem1;
            }
         
            j = index;
         
        } while (index < i);
    }
}

// main function
int main(){
	int lower, upper, count;
	FILE *in_file =  fopen("input.txt","r");
	FILE *out_file = fopen("output.txt", "w");
	if(in_file  == NULL || out_file == NULL){
		printf("Error! File does not open\n");
		exit(-1);
	}
	else{
		fscanf(in_file, "%d %d %d", &lower, &upper, &count);
		srand(time(0));
		for(int i = 0; i < count; i++){
			int num = (rand()%(upper-lower + 1))+ lower;
			fprintf(out_file,"%d ",num);
		}
        int i = 0;
		int arr[count];
		while(fscanf(out_file, "%d ", &arr[i]) == 1){
            i++;
        }
        heapsort(arr,count);
		clock_t start, end;
		start = clock();
		heapsort(arr,count);
		end = clock();
		double time = ((double)(end-start));
		printf("Iterative HeapSort time: %lf\n",time/CLOCKS_PER_SEC);
	}
	return 0;	
}
