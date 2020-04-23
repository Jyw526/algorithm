#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int N;
int T[17];
int P[17];
int ans = -1;
void Consult(int day, int sum) {

	if (day == N + 1) {
		ans = max(ans, sum);
		return;
	}
	//상담을 하지 않는 경우 
	Consult(day + 1, sum);
	
	//상담을 할 수 있고, 하는 경우
	if (day + T[day] <= N + 1) {
		Consult(day + T[day], sum + P[day]);
	}

}

int main() {
	cin >> N;
	for (int i = 1; i < N + 1; i++) {
		cin >> T[i] >> P[i];
	}
	Consult(1, 0);
	cout << ans << '\n';
	return 0;
}