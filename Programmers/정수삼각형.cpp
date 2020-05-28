#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int solution(vector<vector<int>> triangle) {
    int answer = -1;
    int dist[501][502];
    memset(dist,-1,sizeof(dist));
    queue<pair<int, int> > q;
    q.push({0,0});
    dist[0][0] = triangle[0][0];
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(i+1 < triangle.size()){
            if(dist[i+1][j] < dist[i][j] + triangle[i+1][j]){
                dist[i+1][j] = dist[i][j] + triangle[i+1][j];
                q.push({i+1,j});
            }
            if(dist[i+1][j+1] < dist[i][j] + triangle[i+1][j+1]){
                dist[i+1][j+1] = dist[i][j] + triangle[i+1][j+1];
                q.push({i+1,j+1});
            }
        }
        
    }
    for(int i=0;i<=triangle.size()+1;i++){
        answer = max(answer,dist[triangle.size()-1][i]);
    }
    return answer;
}