#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size());
    answer[0] = 0;
    for(int i=heights.size()-1;i>0;i--){
        int rec = -1;
        for(int j=i-1;j>=0;j--){
            if(heights[i]<heights[j]){
                rec = j;
                break;
            }
        }
        answer[i]=rec+1;
    }
    return answer;
}