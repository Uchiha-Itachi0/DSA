#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// method 1 with O(n) space complexity
int missingNumber1(vector<int> arr, int num){
	int storage[num + 1];
	for(int i = 0; i < num + 1; i ++){
		storage[i] = 0;
	}
	for(int i = 0; i < num - 1; i++){
		storage[arr[i]] = 1;
	}
	for(int i = 1; i <= num; i++){
		if(storage[i] == 0){
			return i;
		}
	}
	return -1;
}

// method 2 with O(1) space complexity
int missingNumber2(vector<int> arr, int num){
	int rightSum = (num * (num + 1) / 2);
	int currSum = 0;
	for(auto value: arr){
		currSum += value;
	}
	return rightSum - currSum;
}

// one line
int missingNumber3(vector<int> arr, int num){
	return ((num * (num + 1)) / 2) - (accumulate(arr.begin(), arr.end(), 0));
}
int main(){
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 10};
	int num = 10;
	cout << missingNumber3(arr, num);
}
