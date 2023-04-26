#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int min(int x, int y){
	return (x<y)? x:y;
}

// MERGE SORT
void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for(i = 0; i < n1; i++) 
		L[i] = arr[l+i];
	for(j = 0; j < n2; j++)
	 	R[j] = arr[m+l+j];
	i = 0;	// initial index of first subarray
	j = 0;	// initial index of second subarray
	k = l;	// initial index of merged subarray
	while(i < n1 && j < n2){
		if(L[i] < R[j]){
			arr[k] = L[i];
			i++;
		} else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2){
		arr[k] = R[j];
		j++;
		k++;	}
}

void mergeSort_recursive(int arr[], int l, int r){
	if(l < r){
		int m = l + (r-l)/2;
		mergeSort_recursive(arr, l, m);
		mergeSort_recursive(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

void mergeSort_iterative(int arr[], int n){
	int curr_size;
	int left_start;
	for(curr_size = 1; curr_size <= n-1; curr_size = 2*curr_size){
		for(left_start = 0; left_start < n-1; left_start += 2*curr_size){
			int mid = min(left_start+curr_size-1, n-1);
			int right_end = min(left_start+2*curr_size-1, n-1);
			merge(arr, left_start, mid, right_end);
		}	
	}
}


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
		mergeSort_iterative(arr, count);
		clock_t start, end;
		start = clock();
		mergeSort_recursive(arr, 0, count-1);
		end = clock();
		double time1 = ((double)(end-start));
		printf("Recursive MergeSort time: %lf\n", time1/CLOCKS_PER_SEC);
		fclose(in_file);
		fclose(out_file);
	}
}
