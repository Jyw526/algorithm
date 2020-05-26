#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <set>
using namespace std;
bool visited[8];
char num[8];
set<int> ansSet;
void dfs(string s, string numbers){
    bool check = true;
    for(int i=0;i<numbers.size();i++){
        if(!visited[i]){
            check = false;
            break;
        }
    }
    if(check){
        int num = atoi(s.c_str());
        if(num!=1){
            for(int i=2;i<num;i++){
                if(num%i==0){
                    return;
                }
            }
            ansSet.insert(num);
        }
    }
    for(int i=0;i<numbers.length();i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(s+num[i], numbers);
            dfs(s,numbers);
            visited[i] = false;
        }
    }
}
int solution(string numbers) {
   
    int answer = 0;
    for(int i=0;i<numbers.length();i++){
        num[i] = numbers[i];
    }
    for(int i=0;i<numbers.length();i++){
        if(numbers[i]!='0'){
            memset(visited,false,sizeof(visited));
            string s = "";
            s+=num[i];
            visited[i] = true;
            dfs(s, numbers);
        }
    }
    answer = ansSet.size();
    return answer;
}