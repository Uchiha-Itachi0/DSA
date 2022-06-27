#include<iostream>
using namespace std;

int equilibriumPoint(long long arr[], int n){
	int 
		left = 0,
		right = n - 1,
		sumLeft = arr[left],
		sumRight = arr[right];
	
	if(n == 1){
		return 1;
	}
	while (right > left){
		if(sumLeft == sumRight){
			if(right - 1 == left + 1){
				return right;
			}
			left++;
			right--;
			sumLeft+= arr[left];
			sumRight += arr[right];
		}
		else if(sumLeft < sumRight){
			left++;
			sumLeft += arr[left];
		}
		else{
			right--;
			sumRight += arr[right];
		}
	}
	return -1;
}

int main(){
	long long a[] = {5, 2, 1, 2, 2};
	int n = sizeof(a) / sizeof(a[0]);
	cout << equilibriumPoint(a, n);
}
