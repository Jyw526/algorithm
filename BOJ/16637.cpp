#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
using namespace std;
int N;
string str;
bool check[10] = { false, };
int ans;
long long cal(long long a, long long b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    }
}
int calculate() {
    string tmp = "";
    long long res = str[0] - '0';
    int i = 1;
    while (i < N - 1) {
        int b;
        if (check[(i + 1) / 2]) {
            b = cal(str[i+1] - '0', str[i + 3] - '0', str[i + 2]);
            res = cal(res, b, str[i]);
            i += 4;
        }
        else {
            b = str[i + 1] - '0';
            res = cal(res, b, str[i]);
            i += 2;
        }
    }
    return res;
}
void dfs(int idx, int cnt, int t) {
    if (cnt == t) {
        ans = max(ans, calculate());
        return;
    }
    if (idx >= N / 2) return;
    if (!check[idx - 1]) {
        check[idx] = true;
        dfs(idx + 1, cnt + 1, t);
    }
    check[idx] = false;
    dfs(idx + 1, cnt, t);
    
}
int main() {
    cin >> N;
    cin >> str;
    memset(check, false, sizeof(check));
    ans = calculate();
    for (int i = 1; i <= (N/2 + 1)/2; i ++) {
        memset(check, false, sizeof(check));
        dfs(0, 0, i);
    }
    cout << ans << '\n';
    return 0;
}
