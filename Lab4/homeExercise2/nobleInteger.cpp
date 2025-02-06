#include <iostream>
using namespace std; 

int nobleInteger(int arr[], int n) 
{ 
	// Declare a countArr which keeps count of all elements greater than or equal to arr[i]. Initialize it with zero. 
	int countArr[n + 1];
    for (int i = 0; i < n+1; i++) countArr[i] = 0;
	// Iterating through the given array 
	for (int i = 0; i < n; i++) { 
		// If current element is less than zero, it cannot be a solution so we skip it. 
		if (arr[i] < 0) continue;  
		// If current element is >= size of input array, if will be greater than all elements which can be considered as our solution, as it cannot be 
		// greater than size of array. 
		else if (arr[i] >= n) countArr[n]++; 
		// Else we increase the count of elements >= our current array in countArr 
		else countArr[arr[i]]++; 
	} 
	// Initially, countArr[n] is count of elements greater than all possible solutions 
	int totalGreater = countArr[n]; 
	// Iterating through countArr 
	for (int i = n - 1; i >= 0; i--) { 
		// If totalGreater = current index, means we found arr[i] for which count of elements >= arr[i] is equal to arr[i] 
		if (totalGreater == i && countArr[i] > 0) return i; 
		// If at any point count of elements greater than arr[i] becomes more than current index, then it means we can no longer have a solution 
		else if (totalGreater > i) return -1; 
		// Adding count of elements >= arr[i] to totalGreater. 
		totalGreater += countArr[i]; 
	} 
	return -1; 
} 
int main() 
{ 
	// int arr[] = { 10, 3, 20, 40, 2 }; 
	int arr[] = { 1, 3, 3, 4, 5};
	int res = nobleInteger(arr, 5); 
	if (res != -1) 
		cout << "The noble integer is " << res; 
	else
		cout << "No Noble Integer Found"; 
	return 0; 
}
