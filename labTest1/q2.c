// C program to implement recursive Binary Search
#include <stdio.h>
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
 
int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int x; 
    printf("Enter element you want to search? ");
    scanf("%d", &x);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)? printf("Index of the first occurence of %d is -1", x) : printf("Index of the first occurence of %d is %d", x, result);
    
    return 0;
}