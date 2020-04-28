#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int K;
string str;
void solution() {
	vector<string> v;
	for (int i = 0; i < str.length(); i++) {
		string s = str.substr(i, str.length());
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << v[K - 1] << '\n';
}
int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> K;
		cin >> str;
        cout << "#" << i << " " ;
		solution();
	}
	return 0;
}