#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
bool VPS(string s) {
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else {
			if (st.empty()) {
				return false;
			}
			else {
				st.pop();
			}
		}
	}
	if (st.empty()) return true;
	else return false;
}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;
		bool check = VPS(str);
		if (check) cout << "YES" << '\n';
		else cout << "NO" << '\n';

	}
	return 0;
}
