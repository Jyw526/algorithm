#include <string>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
bool visited[10];
int answer = 0;
void dfs(string s, vector<vector<int>> baseball){
    if(s.length()==3){
        for(int i=0;i<baseball.size();i++){
            string n = to_string(baseball[i][0]);
            int strike = 0;
            int ball = 0;
            for(int i=0;i<3;i++){
                if(n[i]==s[i]){
                    strike++;
                }
                else{
                    for(int j=0;j<3;j++){
                        if(i!=j && s[j]==n[i]){
                            ball++;
                        }
                    }
                }
            }
            if(strike != baseball[i][1] || ball != baseball[i][2]){
                return;
            }
        }
        answer++;
    }
    for(int i=1;i<10;i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(s + to_string(i), baseball);
            visited[i] = false;
        }
    }
}
int solution(vector<vector<int>> baseball) {
    
    for(int i=1;i<10;i++){
        visited[i] = true;
        dfs(to_string(i), baseball);
        visited[i] = false;
    }
    return answer;
}