#include<iostream>
using namespace std;

// Example of DNF(Dutch National flag) Algorithm
void sort012(int arr[], int length){
	int
		left = 0,
		mid = 0,
		right = length - 1;
	
	while (right >= mid){
		if(arr[mid] == 0){
			int temp = arr[mid];
			arr[mid] = arr[left];
			arr[left] = temp;
			mid++;
			left++;
		}
		else if(arr[mid] == 1){
			mid++;
		}
		else{
			int temp = arr[mid];
			arr[mid] = arr[right];
			arr[right] = temp;
			right--;
		}
	}
}

int main(){
	int 
		arr[] = {0, 2, 2, 1, 0, 1, 2, 1, 0, 0, 1, 2, 0, 0},
		length = sizeof(arr) / sizeof(int);
	sort012(arr, length);	
	for(auto value: arr){
		cout << value << " ";
	}	
	return 0;
}
