#include <iostream>
#include <algorithm>
using namespace std;
int N;
int x[11];
int m[11];

void balance() {
	for (int i = 0; i < N-1;i++) {
		double t;
		double left = x[i];
		double right = x[i+1];
		int cnt = 0;
		while (true) {
			cout << fixed;
			cout.precision(10);
			t = (left + right) / 2;
			double f1 = 0;
			double f2 = 0;
			for (int j = 0; j <= i; j++) {
				f1 += m[j] / ((t - x[j]) * (t - x[j]));
			}
			for (int j = i + 1; j < N; j++) {
				f2 += m[j] / ((x[j] - t) * (x[j] - t));
			}
			if (f1 == f2 || cnt > 50) {
				cout << t << " ";
				break;
			}
			if (f1 > f2) {
				left = t;
			}
			else {
				right = t;
			}
			cnt++;
		}
	}
	cout << '\n';

}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		
		for (int i = 0; i < N; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> m[i];
		}
		cout << "#" << t + 1 << " ";
		balance();
	
	}
	

	return 0;
}