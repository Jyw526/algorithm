#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 10000
int arr[MAX];

int main() {
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	if (N == 1) {
		cout << "-1" << '\n';
		return 0;
	}
	bool check = false;
	for (int i = N-1; i >=0; i--) {
		if (i == 0) {
			cout << "-1";
			return 0;
		}
		//가장 아래자릿수 비교
		if (!check) {
			if (arr[i - 1] < arr[i]) {
				swap(arr[i - 1], arr[i]);
				break;
			}
			else {
				check = true;
				continue;
			}
		}

		if (check) {
			if (arr[i - 1] < arr[i]) {
				for (int j = N - 1; j >= i; j--) {
					if (arr[j] > arr[i-1]) {
						swap(arr[j], arr[i - 1]);
						break;
					}
				}
				sort(arr+i,arr+N);
				break;
			}
			else {
				continue;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';
	
	return 0;
}