#include <iostream>
#include <algorithm>
using namespace std;
int num[6];
int cnt;
string s;
int ans = -1;

void dfs(int n, int idx) {
	if (n == cnt) {
		int sum = 0;
		for (int i = 0; i < s.length(); i++) {
			sum += num[i] * pow(10, s.length() - i - 1);
		}
		ans = max(sum, ans);
		return;
	}
	for (int i = idx; i < s.size(); i++) {
		for (int j = i + 1; j < s.size(); j++) {
			if (num[i] <= num[j]) {
				swap(num[i], num[j]);
				dfs(n + 1, i);
				swap(num[i], num[j]);
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> s >> cnt;
		ans = 0;
		for (int j = 0; j < s.length(); j++) {
			num[j] = s[j] - '0';
		}
		dfs(0, 0);
		cout << "#" << i << " " << ans << '\n';
	}

}