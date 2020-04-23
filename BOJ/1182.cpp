#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int arr[21];
int ans = 0;
int N, S;
void Subsequence(int x, int sum) {
	sum += arr[x];
	if (x >= N)
		return;
	if (sum == S) {
		ans++;
	}
	//해당 숫자를 더하지 않은 경우
	Subsequence(x + 1, sum - arr[x]);
    //해당 숫자를 더한 경우
	Subsequence(x + 1, sum);

}
int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	Subsequence(0, 0);
	cout << ans << '\n';
}