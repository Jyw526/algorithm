#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int L, C;
char a[16];

void Code(int x, int cnt, int j, int m, vector<char> pw) {
	
	if (cnt == L && j >= 2 && m>=1) {
		for (int i = 0; i < L; i++) {
			cout << pw[i];
		}
		cout << '\n';
	}

	for (int i = x; i < C; i++) {
		pw.push_back(a[i]);
		//모음인경우
		if (a[i] == 'a' || a[i] == 'e' ||
			a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
			Code(i+1, cnt + 1, j, m + 1, pw);
		}
		else {
			Code(i+1, cnt + 1, j + 1, m, pw);
		}
		pw.pop_back();
	}
}
int main() {
	vector<char> pw;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> a[i];
	}
	sort(a,a+C);
	Code(0, 0, 0, 0, pw);
}