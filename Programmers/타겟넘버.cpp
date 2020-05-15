#include <string>
#include <vector>

using namespace std;
int ans = 0;
void dfs(int idx, char op, int res, vector<int> numbers, int target){
    if(idx > numbers.size()){
        return;
    }
    switch(op){
        case '+':
            res += numbers[idx];
            break;
        case '-':
            res -= numbers[idx];
            break;
    }
    if(res == target && idx == numbers.size()-1){
        ans++;
        return;
    }
    dfs(idx+1, '+', res, numbers, target);
    dfs(idx+1, '-', res, numbers, target);
    
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(0, '+', 0, numbers, target);
    dfs(0, '-', 0, numbers, target);
    return ans;
}