#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high-1; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1] , &arr[high]);
    return (i+1);
}


// recursive implementation
void quicksort_rec(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quicksort_rec(arr, low, pi-1);
        quicksort_rec(arr, pi+1, high);
    }
}
void quickSortIterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];
  
    // initialize top of stack
    int top = -1;
  
    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;
  
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
  
        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);
  
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}
int main(){
    // int n;
    // printf("Enter size of array: " );
    // scanf("%d", &n);
    // int arr[n];
    // printf("Enter elements of array: ");
    
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
        // quickSortIterative(arr, 0, count-1);
        clock_t start, end;
        start = clock();
        quicksort_rec(arr, 0, count-1);
        // for(int i = 0; i < n; i++){
            // printf("%d ", arr[i]);
        // }
        end = clock();
        double time1 = ((double)(end - start));
        printf("Recursive Quicksort Time: %lf\n", time1/CLOCKS_PER_SEC);
     	fclose(in_file);
		fclose(out_file);
	}
    return 0;
}