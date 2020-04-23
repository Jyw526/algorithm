#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int arr[2][MAX];

int sticker(int n) {
	int dp[2][MAX];
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[0][1] = arr[1][0] + arr[0][1];
	dp[1][1] = arr[0][0] + arr[1][1];
	for (int i = 2; i < n; i++) {
		dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
		dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
	}
	return max(dp[0][n - 1], dp[1][n - 1]);
}
int main() {
	int T;
	cin >> T;
	while (T > 0) {
		T--;
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		cout << sticker(n) << '\n';
	}
	return 0;
}