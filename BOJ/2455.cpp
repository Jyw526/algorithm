
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int ans;
    int train[4][2];
    for (int i = 0; i < 4; i++) {
        cin >> train[i][0] >> train[i][1];
    }
    int people = train[0][1];
    ans = people;
    for (int i = 1; i < 4; i++) {
        people = people - train[i][0] + train[i][1];
        ans = max(ans, people);
    }
    cout << ans << '\n';
    return 0;
}
