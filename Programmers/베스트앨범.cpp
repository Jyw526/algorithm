#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}
bool cmp2(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second)
        return p1.first < p2.first;
    else
        return p1.second > p2.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> sum;
    vector<pair<string, int> > vec;
    //장르별 재생수 합 구하기
    for (int i = 0; i < genres.size(); i++) {
        sum[genres[i]] += plays[i];
    }
    for (auto it = sum.begin(); it != sum.end(); it++) {
        vec.push_back({ it->first, it->second });
    }
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < vec.size(); i++) {
        vector<pair<int, int> > v;
        for (int j = 0; j < genres.size(); j++) {
            if (genres[j] == vec[i].first) {
                v.push_back({ j,plays[j] });
            }
        }
        sort(v.begin(), v.end(), cmp2);
        for (int j = 0; j < 2; j++) {
            if (j < v.size()) answer.push_back(v[j].first);
        }
    }
    return answer;
}