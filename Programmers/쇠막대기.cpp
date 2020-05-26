#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> st;
    for(int i=0;i<arrangement.length();i++){
        char ch = arrangement[i];
        if(ch=='('){
            st.push(ch);
        }
        else{
            if(arrangement[i-1]=='('){
                st.pop();
                answer+=st.size();
            }
            else{
                answer++;
                st.pop();
            }
            
        }
    }
    return answer;
}