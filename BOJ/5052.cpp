#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        bool ans = true;
        string phone[10001];
        for (int i = 0; i < N; i++) {
            cin >> phone[i];
        }
        sort(phone, phone + N);
        for (int i = 0; i < N - 1; i++) {
            bool check = true;
            for (int j = 0; j < phone[i].length(); j++) {
                if (phone[i][j] != phone[i + 1][j]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                ans = false;
            }
        }
        ans ? cout << "YES" << '\n' : cout << "NO" << '\n';
    }
    return 0;
}
