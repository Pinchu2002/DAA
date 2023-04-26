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
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}

// MAIN FUNCTION
int main(){
	int n;
	printf("Enter size of array: ");
	scanf("%d", &n);
	int arr[n];
	int num = (rand()%(10)) +1;
	arr[0] = num;
	printf("Array values: ");
	for(int i = 1; i < n; i++){
		arr[i] = num;
		if(i%6 == 1) num++;
		else if(i % 6 == 3) num += 2;
		else if(i % 6 == 5) num += 3;
	}
	quicksort_rec(arr, 0, n-1);
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	int x; 
    printf("Enter element you want to search? ");
    scanf("%d", &x);
    int result = binarySearch(arr, 0, n - 1, x);
    if(result == -1){
		printf("Index of the first occurence of %d is -1\n", x);
		printf("Number of occurrences of %d is 0\n", x);
	}else{
		printf("Index of the first occurence of %d is %d\n", x, result);
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(arr[i] == x) cnt++;
		}
		printf("Number of occurrences of %d is %d\n", x, cnt);
	}
	return 0;
}
