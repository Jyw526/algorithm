#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> height;
int totalSum = 0;
void FindDwarf() {
	bool checked = false;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (totalSum - height[i] - height[j] == 100) {
				height[i] = height[j] = -1;
				checked = true;
				break;
			}
		}
		if (checked)
			break;
	}

	sort(height.begin(), height.end());
	for (int i = 2; i < 9; i++) {
		if(height[i]!=-1)
			cout << height[i] << '\n';
	}

}

int main() {
	
	for (int i = 0; i < 9; i++) {
		int n;
		cin >> n;
		height.push_back(n);
		totalSum += n;
	}

	FindDwarf();
}
