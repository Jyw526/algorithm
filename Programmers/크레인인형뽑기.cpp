#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    for (int i = 0; i < moves.size(); i++) {
        int n = moves[i] - 1;
        int moved = -1;
        for (int j = 0; j < board.size(); j++) {
            if (board[j][n] > 0) {
                moved = board[j][n];
                board[j][n] = 0;
                break;
            }
        }
        if (moved != -1) {
            
            if (!st.empty() && moved == st.top()) {
                st.pop();
                answer += 2;
            }
            else {
                st.push(moved);
            }
        }
    }
    return answer;
}