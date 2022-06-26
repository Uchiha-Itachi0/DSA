#include<iostream>
#include<vector>
using namespace std;

// Brute force
vector<int> subArraySum1(int arr[], long long sum, int n){
	vector<int> index;
	for(int i = 0; i < n; i++){
		int summation = arr[i];
		for(int j = i + 1; j < n; j++){
			summation += arr[j];
			if(summation == sum){
				index.push_back(i + 1);
				index.push_back(j + 1);
				return index;
			}
		}
	}
	index.push_back(-1);
	return index;
}


// Optimise solution
vector<int> subArraySum2(int arr[], long long sum, int n){
	int 
		pointer1 = 0,
		pointer2 = 1, 
		summation = arr[pointer1];
	vector<int> index;
	while (pointer2 < n){
		if(summation == sum){
			index.push_back(pointer1 + 1);
			index.push_back(pointer2);
			return index;
		}
		if(summation > sum){
			summation -= arr[pointer1];
			pointer1 += 1;
		}
		else if(summation < sum){
			summation += arr[pointer2];
			pointer2 += 1;
		}
	}
	
	while(pointer1 < n){
		if(summation == sum){
			index.push_back(pointer1 + 1);
			index.push_back(pointer2);
			return index;	
		}
		summation -= arr[pointer1];
		pointer1 += 1;
	}

	index.push_back(-1);
	return index;
	
}
int main(){
	long long sum;
	int arr[] {135, 101, 170, 125, 79, 159, 163, 65, 106, 146, 82, 28, 162, 92, 196, 143, 28, 37, 192, 5, 103, 154, 93, 183, 22, 117, 119, 96, 48, 127, 172, 139, 70, 113, 68, 100, 36, 95, 104, 12, 123, 134};
	int length = sizeof(arr) / sizeof(arr[0]);
	cin >> sum;
	vector<int> result = subArraySum2(arr, sum, length);
	for(auto value: result){
		cout << value << " ";
	}
	return 0;
}
