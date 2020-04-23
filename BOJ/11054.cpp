#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 0;
int N;
int A[1001];
int dp1[1001];
int dp2[1001];

//증가수열
void maxCres() {
	for (int i = 0; i < N; i++) {
		dp1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j] && dp1[i] < dp1[j] + 1) {
				dp1[i] = dp1[j] + 1;
			}
		}
	}

}

//감소수열
int maxDesc(int k) {
	for (int i = k+1; i < N; i++) {
		dp2[i] = 1;
		for (int j = k+1; j < i; j++) {
			if (A[i] < A[k] && A[j] < A[k] && A[i] < A[j] && dp2[i] < dp2[j] + 1) {
				dp2[i] = dp2[j] + 1;
			}
		}
	}

	int MAX = 0;
	for (int i = k + 1; i < N; i++) {
		if (A[i] != A[k]) {
			MAX = max(MAX, dp2[i]);
		}
	}
	return MAX;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	maxCres();
	int ans = -1;
	int idx = -1;
	for (int i = 0; i < N; i++) {
		int sum = dp1[i] + maxDesc(i);
		if (sum > ans) {
			ans = sum;
			idx = i;
		}
			
	}
	
	cout << ans << '\n';
	return 0;
}