#include<iostream>
#include<unordered_map>
using namespace std;

int getPair(int arr[], int n, int k){
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(arr[i] + arr[j] == k){
				count++;
			}
		}
	}
	return count;
}

// Method 2 Time complexity O(n)
int getPair2(int arr[], int n, int k){
	unordered_map<int, int> freq;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int diff = k - arr[i];
		if(freq[diff]){
			ans += freq[diff];
		}
		freq[arr[i]]++;
	}
	return ans;
}

int main(){
	int 
		arr[] = {1, 3, 1, 5, 3, 2, 2, 1, 5},
		n = sizeof(arr) / sizeof(int),
		k = 4;
		
	cout << getPair2(arr, n, k);
}
