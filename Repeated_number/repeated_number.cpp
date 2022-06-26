#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// method 1 Time complexity O(n^2)
vector<int> repeatedNumber(int arr[], int n){
	vector<int> repeated;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(arr[i] == arr[j]){
				repeated.push_back(arr[i]);
				break;
			}
		}
	}
	if(repeated.size() == 0){
		repeated.push_back(-1);
	}
	return repeated;
}

// Method 2 Time complexity O(n)
vector<int> repeatedNumber2(int arr[], int length){
	vector<int> repeated;
	for(int i = 0; i < length; i++){
		arr[arr[i] % length] = arr[arr[i] % length] + length;
	}
	for(int i = 0; i < length; i++){
		if(arr[i] >= 2 * length){
			repeated.push_back(i);
		}
	}
	if(repeated.size() == 0){
		repeated.push_back(-1);
	}
	return repeated;
}

// Method 3 Time complexity O(n) space complexity O(n)

vector<int> repeatedNumber3(int arr[], int length){
	vector<int> repeated;
	int storage[length];
	for(int i = 0; i < length; i++){
		storage[i] = 0;
	}
	for(int i = 0; i < length; i++){
		storage[arr[i]]++;
	}
	for(int i = 0; i < length; i++){
		if(storage[i] > 1){
			repeated.push_back(i);
		}
	}
	if(repeated.size() == 0 ){
		repeated.push_back(-1);
	}
	return repeated;
	
}
int main(){
	int arr[] = {1, 2, 3, 2, 1, 3, 4};
	int length = sizeof(arr) / sizeof(int);
	vector<int> res = repeatedNumber2(arr, length);
	for(auto value: res){
		cout << value << " ";
	}
}
