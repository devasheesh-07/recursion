#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void mergeSort(int *arr, int s, int e) {

    //base case
    if(s >= e) {
        return;
    }
    
    int mid = (s+e)/2;

    //left part sort karna h 
    mergeSort(arr, s, mid);
    
    //right part sort karna h 
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, e);

}

int main() {

    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;

    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
} 

//-------------------------------- another solution for merge sort usingindex --------------------------------------
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Calculating next gap
int nextGap(int gap)
{
	if (gap <= 1)
		return 0;
		
	return (int)ceil(gap / 2.0);
}

// Function for swapping
void swap(int nums[], int i, int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

// Merging the subarrays using shell sorting
// Time Complexity: O(nlog n)
// Space Complexity: O(1)
void inPlaceMerge(int nums[], int start,
							int end)
{
	int gap = end - start + 1;
	
	for(gap = nextGap(gap); 
		gap > 0; gap = nextGap(gap)) 
	{
		for(int i = start; i + gap <= end; i++) 
		{
			int j = i + gap;
			if (nums[i] > nums[j])
				swap(nums, i, j);
		}
	}
}

// merge sort makes log n recursive calls
// and each time calls merge()
// which takes nlog n steps
// Time Complexity: O(n*log n + 2((n/2)*log(n/2)) +
// 4((n/4)*log(n/4)) +.....+ 1)
// Time Complexity: O(logn*(n*log n))
// i.e. O(n*(logn)^2)
// Space Complexity: O(1)
void mergeSort(int nums[], int s, int e)
{
	if (s == e)
		return;

	// Calculating mid to slice the
	// array in two halves
	int mid = (s + e) / 2;

	// Recursive calls to sort left
	// and right subarrays
	mergeSort(nums, s, mid);
	mergeSort(nums, mid + 1, e);
	
	inPlaceMerge(nums, s, e);
}

// Driver Code
int main()
{
	int nums[] = { 12, 11, 13, 5, 6, 7 };
	int nums_size = sizeof(nums) / sizeof(nums[0]);
	
	mergeSort(nums, 0, nums_size-1);
	
	for(int i = 0; i < nums_size; i++)
	{
		cout << nums[i] << " ";
	}
	return 0;
}

// This code is contributed by adityapande88
