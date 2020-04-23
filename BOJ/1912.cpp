#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[100001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int dp[100001];
	dp[0] = arr[0];
	for (int i = 0; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}
	int ans = -987654321;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}