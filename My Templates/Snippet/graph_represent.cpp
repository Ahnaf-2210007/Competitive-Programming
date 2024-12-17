const int N = 1e5+7;
vi graph[N];
bool vis[N];


void solve()
{
    // Do your thing here :)
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
    	int v1, v2;
    	cin >> v1 >> v2;
    	graph[v1].push_back(v2);
    	graph[v2].push_back(v1);
    }

    dfs(1);
}
