#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(long int* xp, long int* yp)
{
    long int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(long int arr[], long int n)
{
    long int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
 
/* Function to sort an array using insertion sort*/
void insertionSort(long int arr[], long int n)
{
    long int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// Function to sort an array using selection sort
void selectionSort(long int arr[], long int n)
{
    long int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}
 
int main(){
	long int lower, upper, count;
	FILE *in_file =  fopen("input.txt","r");
	FILE *out_file = fopen("output.txt", "w");
	int it = 0;
	double tim1[10], tim2[10], tim3[10];
	
	// checking file 
	if(in_file  == NULL || out_file == NULL){
		printf("Error! File does not open\n");
		exit(-1);
	}

	else{
		printf("A_size, Bubble, Insertion, Selection\n");
		while(it++ < 10){
			fscanf(in_file, "%li %li %li", &lower, &upper, &count);
			srand(time(0));
			long int a[count], b[count], c[count];
			// Dynamic memory allocation
			//int *ptr = (int*)malloc(count*sizeof(int));
			for(long int i = 0; i < count; i++){
				long int num = (rand()%(upper-lower + 1))+ lower;
				a[i] = num;
				b[i] = num;
				c[i] = num;
				//fprintf(out_file,"%d ",*(ptr1+i));
			}
			clock_t start , end;
		
			// Bubble Sort 
			start = clock();
			bubbleSort(a, count);
			end = clock();
			tim1[it] = ((double)(end-start));
	
		
			// Insertion Sort 
			start = clock();
			insertionSort(b, count);
			end = clock();
			tim2[it] = ((double)(end-start));
			
			
			// Selection Sort 
			start = clock();
			selectionSort(c, count);
			end = clock();
			tim3[it] = ((double)(end-start));
			
			printf(" %li\t %li\t  %li\t   %li\n",count,(long int)tim1[it],(long int)tim2[it],(long int)tim3[it]);
			fclose(in_file);
			fclose(out_file);
			count += 10;
		}
	}
	return 0;
}
