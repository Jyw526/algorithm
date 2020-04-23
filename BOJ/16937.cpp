#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int H, W, N;
#define MIN -987654321;
vector<pair<int, int> > sticker;
int ans = MIN;
int d[4][2] = { {0,0} ,{1,0}, {1,1}, {0,1} };

int put(int idx, int idx2, int dir, int dir2) {
	int r1 = sticker[idx].first;
	int c1 = sticker[idx].second;
	int r2 = sticker[idx2].first;
	int c2 = sticker[idx2].second;
	if (dir == 1) swap(r1, c1);
	if (dir2 == 1) swap(r2, c2);
	
	if (W >= r1 && H >= c1) {
		//첫번째 조각 오른쪽
		int area = r1 * c1 + r2 * c2;
		if (r2 <= W - r1 && c2 <= H) {
			return area;
		}
		//첫번째 조각 아래
		else if (r2 <= W && c2 <= H - c1) {
			return area;
		}
		return -1;
	}

	return -1;
}

void stickerArea() {

	//2개 고르기
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int m = 0; m < 4; m++) {
				int res = put(i, j, d[m][0], d[m][1]);
				if (res != -1) {
					ans = max(ans, res);
					break;
				}
			}
		}
	}
}
int main() {
	cin >> H >> W;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;
		sticker.push_back(make_pair(r, c));
	}
	
	stickerArea();
	if (ans == -987654321) cout << 0 << '\n';
	else cout << ans << '\n';

	
	return 0;
}