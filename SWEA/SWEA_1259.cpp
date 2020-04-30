#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<pair<int, int> > v;
bool visited[21];
vector<int> ans;
void dfs(vector<int> vec) {
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			if (v[vec.back()].second == v[i].first) {
				visited[i] = true;
				vec.push_back(i);
				dfs(vec);
				vec.pop_back();
			}
		}
	}
	
	if (vec.size() > ans.size()) {
		ans.clear();
		for (int i = 0; i < vec.size(); i++) {
			ans.push_back(vec[i]);
			//cout << ans[i] << " ";
		}
		//cout << '\n';
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		v.clear();
		ans.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		
		}
		for (int i = 0; i < N; i++) {
			memset(visited, false, sizeof(visited));
			visited[i] = true;
			vector<int> vec;
			vec.push_back(i);
			dfs(vec);
		}
		cout << "#" << t << " ";
		for (int i = 0; i < ans.size(); i++) {
			cout << v[ans[i]].first << " " << v[ans[i]].second << " ";
		}
		cout << '\n';
	}
	
	return 0;
}