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
		//��ĭ �ڷΰ��� ���
		if (curr - 1 >= 0 && visit[curr - 1] == 0) {
			q.push(curr - 1);
			visit[curr - 1] = visit[curr] + 1;
		}
		//��ĭ ������ ���� ���
		if (curr + 1 <= 100000 && visit[curr + 1] == 0) {
			q.push(curr + 1);
			visit[curr + 1] = visit[curr] + 1;
		}
		//����ĭ�� �ι�� �̵��ϴ� ���
		if (curr * 2 <= 100000 && visit[curr * 2] == 0) {
			q.push(curr * 2);
			visit[curr * 2] = visit[curr] + 1;
		}
	}
}

int main() {
	input();		//�Է��� ����
	findBrother();	//������ ã��
}