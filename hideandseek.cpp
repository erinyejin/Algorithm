#include <iostream>
#include <queue>
using namespace std;

int subin, brother;
int visit[100001];
queue<int> q;

void input() {
	ios_base::sync_with_stdio(false);
	cin >> subin >> brother;
}

void findBrother() {
	int curr = subin;
	visit[curr] = 1;
	q.push(curr);

	while (!q.empty()) {
		curr = q.front();
		q.pop();

		if (curr == brother) {
			cout << visit[curr] - 1 << "\n";
			break;
		}
		//한칸 뒤로가는 경우
		if (curr - 1 >= 0 && visit[curr - 1] == 0) {
			q.push(curr - 1);
			visit[curr - 1] = visit[curr] + 1;
		}
		//한칸 앞으로 가는 경우
		if (curr + 1 <= 100000 && visit[curr + 1] == 0) {
			q.push(curr + 1);
			visit[curr + 1] = visit[curr] + 1;
		}
		//현재칸의 두배로 이동하는 경우
		if (curr * 2 <= 100000 && visit[curr * 2] == 0) {
			q.push(curr * 2);
			visit[curr * 2] = visit[curr] + 1;
		}
	}
}

int main() {
	input();		//입력을 받음
	findBrother();	//동생을 찾음
}