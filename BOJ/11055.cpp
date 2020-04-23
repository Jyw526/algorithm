#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int A[1001];
	int dp[1001];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		dp[i] = A[i];
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j] && dp[i] < dp[j] + A[i]) {
				dp[i] = dp[j] + A[i];
			}
		}
	}
	int MAX = -1;
	for (int i = 0; i < N; i++) {
		if (dp[i] > MAX) {
			MAX = dp[i];
		}
	}
	cout << MAX << '\n';
	return 0;
}