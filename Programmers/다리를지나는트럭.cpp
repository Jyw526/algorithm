#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total = 0;
    queue<int> q;
    for(int i=0;i<truck_weights.size();i++){
        int truck = truck_weights[i];
        while(1){
            answer ++;
            if(q.size()==bridge_length){
                total -= q.front();
                q.pop();
            }
            if(q.empty()){
                q.push(truck);
                total += truck;
                break;
            }
            else{
                if(total + truck <= weight){
                    q.push(truck);
                    total += truck;
                    break;
                }
                else{
                    q.push(0);
                }
            }
        }
    }
    answer += bridge_length;
    return answer;
}