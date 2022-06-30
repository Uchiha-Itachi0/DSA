#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> findLeader(int arr[], int n){
	vector<int> ans;
	int flag;
	for(int i = 0; i < n; i++){
		flag = 0;
		for(int j = i + 1; j < n; j++){
			if(arr[i] < arr[j]){
				flag++;
				break;
			}
		}
		if(flag == 0){
			ans.push_back(arr[i]);
		}
	}
	return ans;
	
}

vector<int> findLeader2(int arr[], int n){
	vector<int> res = {arr[n - 1]};
	int 
		i = n - 1,
		j = i - 1;
	while (j >= 0){
		if(arr[j] >= arr[i]){
			res.push_back(arr[j]);
			i = j;
		}
		j--;
	}
	reverse(res.begin(), res.end());
//	i = res.size() - 1;
//	j = 0;
//	while (j < i){
//		int temp = res[j];
//		res[j] = res[i];
//		res[i] = temp;
//		i--;
//		j++;
//	}
	return res;
}
int main(){
	int 
		arr[] = {1, 6, 2, 3, 5, 0, 3},
		n = sizeof(arr) / sizeof(int);
	vector<int> res = findLeader2(arr, n);
	for(auto value: res){
		cout << value << " ";
	}
}
