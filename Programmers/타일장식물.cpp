#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long len[81];
    len[1] = 1;
    len[2] = 1;
    
    for(int i=3;i<=N;i++){
        len[i] = len[i-1] + len[i-2];
    }
    
    answer = (len[N] + (len[N] + len[N-1])) * 2;;
    return answer;
}