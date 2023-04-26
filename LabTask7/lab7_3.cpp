// MATRIX CHAIN MULTIPLICATION

#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1 . . . n
int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int mini = INT_MAX;
	int count;

	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k)
				+ MatrixChainOrder(p, k + 1, j)
				+ p[i - 1] * p[k] * p[j];

		mini = min(count, mini);
	}
	return mini;
}

int main()
{
	// int arr[] = { 1, 2, 3, 4, 3 };
	// int N = sizeof(arr) / sizeof(arr[0]);
    cout<<"Enter size of array: ";
    int n; cin>>n;
    int arr[n];
    cout << "Enter values of array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
	cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, 1, n - 1);
	return 0;
}