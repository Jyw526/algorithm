#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int k;
int S[14];
int lotto[6];
void dfs(int s,int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = s; i < k; i++) {
		lotto[cnt] = S[i];
		dfs(i + 1, cnt + 1);
	}
}
int main() {
	
	while (true) {
		cin >> k;
		if (k == 0) return 0;
		for (int i = 0; i < k; i++) {
			cin >> S[i];
		}

		dfs(0, 0);
		cout << "\n";
		
	}
	return 0;
}