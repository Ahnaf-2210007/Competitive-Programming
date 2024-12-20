int level[N];

void bfs(int source) {
	queue<int> q;
	q.push(source);
	vis[source] = 1;

	while(!q.empty()) {
		int curVer = q.front();
		cout << curVer << " ";		//the path
		q.pop();
		for(int child: graph[curVer]) {
			if(!vis[child]) {
				q.push(child);
				vis[child] = 1;
				level[child] = level[curVer]+1;
			}
		}
	}
	cout << endl;
}
