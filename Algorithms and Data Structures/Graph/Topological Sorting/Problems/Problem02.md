## Problem Link:
### https://vjudge.net/problem/Gym-105677I
### Code:
```cpp
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
const int N = 1e5+7;
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
    int n, cnt = 0;
    cin >> n;
    
    map<int, int> mp;
    for(int i=1; i<=n; i++) {
    	int m;
    	cin >> m;
        
        if(m==0) {
            cnt++;
        }
    	while(m--) {
    		int x;
    		cin >> x;
    		graph[i].push_back(x);
            mp[x]++;
    	}
    }

    if(cnt==0 || cnt>1) {
        cout << 0 << endl;
        return;
    }

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    vi res(n+1);
    int i=n;
    while(!s.empty()) {
        res[i] = s.top();
        i--;
        s.pop();
    }    
    // for(auto x: res) {
    //     cout << x << " ";
    // }
    // cout << endl;

    for(int i=1; i<=n; i++) {
        sort(all(graph[i]));
    }
    for(int i=1; i<n; i++) {
        int x = res[i+1];
        if(binary_search(all(graph[x]), res[i])==0) {
            cout << 0 << endl;
            //cout << res[i] << x << endl;
            return;
        }
    }
    cout << 1 << endl;
}

int main()
{

    _fastio;
    solve();
}
```
