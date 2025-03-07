#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define yes cout << "YES" << endl 
#define no cout << "NO" << endl 
#define pb push_back
#define l_b lower_bound
#define u_b upper_bound
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define _fastio  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef unordered_map<int, int> umap_ii;
typedef unordered_map<string, int> umap_si;


/**
 * Limits in C++ for reference
 * _____________________________________________________________________________________
 * |Sr| Macro Name | Description                     | Value
 * |No|____________|_________________________________|__________________________________
 * |1.| ULLONG_MAX | Maximum value unsigned long long| 18,446,744,073,709,551,615 (10^20)
 * |2.| LLONG_MAX  | Maximum value long long         | 9,223,372,036,854,775,807 (10^19)
 * |3.| LLONG_MIN  | Minimum value long long         |-9,223,372,036,854,775,808 -1*(10^19)
 * |4.| INT_MAX    | Maximum value int               | 2,147,483,647 (10^10)
 * |5.| INT_MIN    | Minimum value int               |-2,147,483,648 (10^10)
*/

//Write the code  here
const int N = 2e5+7;
vi graph[N];
bool vis[N];
stack<int> s;

//Write the code  here
void dfs(int vertex) {
	//Take action on vertex after entering the vertex
	vis[vertex] = true;
	for(int child: graph[vertex]) {
		//Take action on child before entering the child node
		if(vis[child]) continue;
		dfs(child);
		// Take action on child before exiting  the child node
	}
	// Take action on vertex after exiting the vertex 
	s.push(vertex);
}
//O(V+E)
void solve()
{
    // Do your thing here :)
    int n, k;
    cin >> n >> k;
	vector<vector<int>> a(k, vector<int>(n));
	for(int i=0; i<k; i++) {
		for(int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}

	for(int i=1; i<=n; i++) {
		vis[i] = false;
		graph[i].clear();
	}
	while(!s.empty()) s.pop(); 

	for(int i=0; i<k; i++) {
		for(int j=1; j<n-1; j++) {
			graph[a[i][j]].push_back(a[i][j+1]);
		}
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			dfs(i);
		}
	}
	vi res;
	while(!s.empty()) {
		res.push_back(s.top());
		s.pop();
	}
	
    unordered_map<int, int> pos;
    for (int i=0; i<res.size(); i++) {
        pos[res[i]] = i;
    }

    for (int i=1; i<=n; i++) {
        for (int x : graph[i]) {
            if (pos[i]>pos[x]) { 
                no;
                return;
            }
        }
    }
    yes;
}

int main()
{

    _fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
