#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1;i*i<=yellow;i++){
        if(yellow%i==0){
            int y = i; int x = yellow/i;
            if((x+2)*(y+2) - x*y == brown){
                answer.push_back(x+2);
                answer.push_back(y+2);
                break;
            }
        }
    }
    return answer;
}