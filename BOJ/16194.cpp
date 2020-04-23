#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <memory.h>
using namespace std;
int N;
int P[10001];
int m[10001];

int card() {
	m[1] = P[1];
	
	for (int i = 2; i <= N; i++) {
		for (int j = i / 2; j < i; j++) {
			int sum = m[j] + m[i - j];
			m[i] = min(sum, m[i]);
		}
	}
	
	return m[N];
}
int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> P[i];
		m[i] = P[i];
	}

	cout << card() << '\n';

	return 0;
}