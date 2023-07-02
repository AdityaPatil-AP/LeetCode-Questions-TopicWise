#include <bits/stdc++.h>
using namespace std;

// QuickSort Function.
// It is one of most famous sorting techniques.
// It is based upon Divide and Conquer Algorithm.
// It contains of two functions -  1) QuickSort 2) Partition.
// 1) QuickSort contains the recursive calls for call the two subparts after finding the 
// position of the pivot. These two recursive calls are dividing the array.
// Invariant - Pivot is always getting the correct position as in the sorted version of the array.
// 2) Partition Function - It helps to find the correct position of the pivot in the array.


//  Partition function has time complexity of : O(n).
// The partition function ensures that : 
// 1) Returns the pivot element position.
// 2) As well as ensures that all the elements before pivot are smaller than pivot and 
// all the elements above pivot are greater than pivot.
// 3) Positions the pivot at it's correct position as in sorted version of the array.
// Basically after every call you can except some elements to be at their correct positions as in the sorted array.
int partition(int *arr, int low, int high){
    // Assume the first element to be the pivot.
    int pivot = arr[low];
    // i - ensures that all the elements before it are smaller than or equal to pivot.
    // j - ensures that all the elements after it are greater than the pivot.
    int i = low, j = high;
    // We are also swapping the elements so that elements which are smaller than or equal the pivot 
    // are before the pivot and elements greater than it are after the pivot. 
    while(i < j){
        while(arr[i] <= pivot && i <= high) i++;
        while(arr[j] > pivot) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    // J at the end indicates the correct position of the pivot.
    // we swap so that the pivot gets it's correct position as in the sorted version of the array.
    swap(arr[low], arr[j]);
    // Now all elements smaller than or equal to pivot are in the range (low, pivot - 1).
    // and all elements greater than pivot are in the range (pivot + 1, high).
    return j;
}

void quickSort(int *arr, int low, int high){
    // Atleast 2 elements are there. Otherwise for 1 element array is already sorted.
    if(low < high){
        // Finding the pivot element position.
        int pivot = partition(arr, low, high);
        // Calling the left part to be sorted.
        quickSort(arr, low, pivot - 1);
        // Calling the right part to be sorted.
        quickSort(arr, pivot + 1, high);
    }
}

// Time and Space Complexity Analysis
// Time Complexity. 
// Avg. Case : O(n * log2(n)).
// Best Case - When the pivot element is always in the middle, then it is the similar case to the mergesort and 
// we can get time complexity of O(n*log2(n)).
// Worst Case - When the array is already sorted. In that case we always get the first element as the pivot. and the partition function 
// has time complexity of O(n). And we make the call for the partition function n times making our time complexity O(n^2).
// Space Complexity : The maximum depth of our recursion tree may go upto n. Therefore space complexity is O(n). Which happens when the array is 
// sorted.

int main(){
    int arr[] = {1, 5, 6, 8, 16, 4, 9};
    // QuickSort
    int n = *(&arr + 1) - arr;
    cout << "Array Before Sorting : ";
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, 0, n - 1);
    cout << "Array after Sorting : ";
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}