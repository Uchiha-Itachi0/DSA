#include<iostream>
using namespace std;

// Method 1 Time complexity O(n)
int transitionPoint1(int arr[], int n){
	for(int i = 0; i < n; i++){
		if(arr[i] == 1){
			return i;
		}
	}
	return -1;
}

// Method 2 Time complexity O(logn)
int transitionPoint2(int arr[], int n){
	int 
		left = 0,
		right = n - 1;
	
	while (left <= right){
		int mid = (left + right) / 2;
		if(arr[mid] == 1){
			if(arr[mid - 1] == 0){
				return mid;
			}
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
}
int main(){
	int 
		arr[] = {1},
		n = sizeof(arr) / sizeof(int);
	cout << transitionPoint2(arr, n);
}
