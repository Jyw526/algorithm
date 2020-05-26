#include <string>
#include <vector>
#include <queue>
#include <list>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    priority_queue<int> pq;
    list<int> lt;
    for(int i=0;i<priorities.size();i++){
        q.push(i);
        pq.push(priorities[i]);
    }
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        if(pq.top()>priorities[idx]){
            q.push(idx);
        }
        else{
            pq.pop();
            answer++;
            if(idx == location){
                break;
            }
        }
    }
    return answer;
}