#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> list[1001];
int queue[1001];
bool bfs_visit[1001], dfs_visit[1001];

void dfs(int now)
{
	dfs_visit[now] = true;
	printf("%d ", now);
	for (int i = 0; i < list[now].size(); i++) {
		int next = list[now][i];
		if (dfs_visit[next]) continue;
		dfs(next);
	}
}

void bfs(int start)
{
	int front, rear;
	front = rear = 0;
	bfs_visit[start] = true;
	queue[front] = start;
	while (front <= rear) {
		int now = queue[front];
		printf("%d ", now);
		for (int i = 0; i < list[now].size(); i++) {
			int next = list[now][i];
			if (bfs_visit[next]) continue;
			rear++;
			queue[rear] = next;
			bfs_visit[next] = true;
		}
		front++;
	}
}

int main(int argc, char* argv[])
{
	int n, m, v;
	scanf("%d%d%d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		list[v1].push_back(v2);
		list[v2].push_back(v1);
	}
	for (int i = 0; i < n; i++) sort(list[i].begin(), list[i].end());

	dfs(v); printf("\n");
	bfs(v); printf("\n");
	return 0;
}