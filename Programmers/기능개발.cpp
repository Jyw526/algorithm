#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = progresses.size();
    int day = (100-progresses[0])/speeds[0];
    int release = 1;
    if((100-progresses[0])%speeds[0]!=0)
        day ++;
    for(int i=1;i<size;i++){
        int needs = (100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i]!=0)
            needs ++;
        if(day < needs){
            day = needs;
            answer.push_back(release);
            release = 1;
        }
        else{
            release ++;
        }
    }
    answer.push_back(release);
    return answer;
}