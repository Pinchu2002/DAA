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
void heapify(int arr[], int n, int i){
	int largest = i;
	int left = 2*i+1;
	int right = 2*i + 2;
	if(left < n && arr[left] > arr[largest]){
		largest = left;
	}
	if(right < n && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest != i){
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

// heapsort function
void heapsort(int arr[], int n){
	for(int i = n/ 2 - 1; i >= 0; i--){
		heapify(arr, n, i);
	}
	for(int i = n-1; i >= 0; i--){
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
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
		printf("Recursive HeapSort time: %lf\n",time/CLOCKS_PER_SEC);
	}
	return 0;	
}
