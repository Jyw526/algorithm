#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int E, S, M;
	cin >> E >> S >> M;
	int year = 1;
	while (true) {
		if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0) {
			break;
		}
		year++;
	}

	cout << year << "\n";
	return 0;
}