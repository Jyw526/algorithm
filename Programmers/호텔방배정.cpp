#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> room;
long long findRoom(long long n) {
	if (room[n] == 0) return n;
	return room[n] = findRoom(room[n]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	for (long long i = 0; i < room_number.size(); i++) {
		long long r = findRoom(room_number[i]);
		answer.push_back(r);
		room[r] = r + 1;
	}
	return answer;
}
