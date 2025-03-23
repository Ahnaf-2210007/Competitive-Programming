```cpp
#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9
#define _fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int N = 1e3+7;
int n, m;
char s[N][N];
vvi res; // Now it's a global variable

vector<vector<int>> bfs(vector<pii> src) {
    vector<vi> d(n, vi(m, INF));
    queue<pii> q;

    for(auto x: src) {
        q.push({x.first, x.second});
        d[x.first][x.second] = 0;
    }
    
    int dr[] = {0, 0, -1, 1};
    int dc[] = {1, -1, 0, 0};

    while (!q.empty()) {
        pii cell = q.front();
        q.pop();
        int r = cell.first, c = cell.second;
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (s[nr][nc] != '#' && d[r][c] + 1 < d[nr][nc]) {
                    d[nr][nc] = d[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    return d;
}

void escape_bfs(int start_r, int start_c) {
    queue<pii> q;
    map<pii, pii> parent;
    map<pii, char> move;
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    q.push({start_r, start_c});
    vis[start_r][start_c] = true;

    int dr[] = {0, 0, -1, 1};
    int dc[] = {1, -1, 0, 0};
    char dir[] = {'R', 'L', 'U', 'D'};

    while (!q.empty()) {
        pii cell = q.front();
        q.pop();
        int r = cell.first, c = cell.second;

        if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
            cout << "YES\n";
            vector<char> path;
            pii cur = {r, c};
            while (parent.count(cur)) {
                path.push_back(move[cur]);
                cur = parent[cur];
            }
            reverse(path.begin(), path.end());
            cout << path.size() << '\n';
            for (char d : path) cout << d;
            cout << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && res[nr][nc] == 1 && !vis[nr][nc]) {
                vis[nr][nc] = true;
                parent[{nr, nc}] = {r, c};
                move[{nr, nc}] = dir[i];
                q.push({nr, nc});
            }
        }
    }

    cout << "NO\n";
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> s[i][j];
        }
    }

    vector<pii> src, multi_src;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                src.push_back({i, j});
            }
        }
    }

    auto res1 = bfs(src);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (s[i][j] == 'M') {
                multi_src.push_back({i, j});
            }
        }
    }

    auto res2 = bfs(multi_src);

    res.assign(n, vi(m, 0));
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = (s[i][j] != '#') && (res1[i][j] < res2[i][j]);
        }
    }

    int r = src[0].first, c = src[0].second;
    escape_bfs(r, c);
}

int main() {
    _fastio;
    solve();
}
```
