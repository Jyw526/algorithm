#include <iostream>
#include <algorithm>
using namespace std;
int N, B, C;
const int MAX = 1000001;
int A[MAX];
void solution() {
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		int res = A[i] - B;
		int total = 1;
		if (res > 0) {
			total += res / C;
			if (res % C != 0) total++;
		}
		ans += total;
	}
	
	cout << ans << '\n';
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	solution();
	return 0;
}