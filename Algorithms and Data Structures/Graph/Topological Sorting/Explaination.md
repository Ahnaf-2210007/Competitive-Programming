# Topological Sorting in Graphs

## Introduction
Topological sorting is an ordering of the vertices in a **Directed Acyclic Graph (DAG)** such that for every directed edge `u -> v`, vertex `u` comes before vertex `v` in the ordering. This is useful in scheduling tasks, dependency resolution, and many applications in computer science.

Topological sorting can be performed using:
1. **Depth-First Search (DFS) based approach**
2. **Breadth-First Search (BFS) based approach (Kahn's Algorithm)**

## 1. Topological Sorting using DFS
The idea behind the DFS approach is to use recursion and a stack to store the order of completion of nodes.

### Algorithm:
1. **Initialize** a `visited` set to track visited nodes and a `stack` to store the topological order.
2. **Perform DFS** from each unvisited node:
   - Recursively visit all its unvisited adjacent nodes.
   - After visiting all adjacent nodes, push the current node onto the `stack`.
3. **Pop elements from the stack** to get the topological order.

### Implementation (C++):
```cpp
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSortDFS(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }
    vector<int> topoOrder;
    while (!st.empty()) {
        topoOrder.push_back(st.top());
        st.pop();
    }
    return topoOrder;
}
```

### Time Complexity:
- **O(V + E)** (as each node and edge is visited once)

### Space Complexity:
- **O(V + E)** (for adjacency list and recursion stack)

---

## 2. Topological Sorting using BFS (Kahn’s Algorithm)
Kahn’s Algorithm is an **indegree-based approach** using BFS.

### Algorithm:
1. **Compute the indegree** of each node.
2. **Push nodes with `indegree = 0`** into a queue (these have no dependencies).
3. **Process each node from the queue**:
   - Add it to the topological order.
   - Decrease the indegree of its adjacent nodes.
   - If any adjacent node’s indegree becomes 0, push it to the queue.
4. **Repeat until the queue is empty**.

### Implementation (C++):
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSortBFS(int V, vector<vector<int>> &adj) {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topoOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    return topoOrder;
}
```

### Time Complexity:
- **O(V + E)** (each edge and node is processed once)

### Space Complexity:
- **O(V + E)** (for adjacency list and queue)

---

## Comparison of DFS and BFS Approaches
| Method | Time Complexity | Space Complexity | Characteristics |
|--------|---------------|----------------|----------------|
| DFS-based | O(V + E) | O(V + E) | Uses recursion and stack |
| BFS-based | O(V + E) | O(V + E) | Uses queue and indegree array |

Both approaches give valid topological orderings, but DFS is more recursive, whereas BFS (Kahn’s Algorithm) is iterative.

---

## Applications of Topological Sorting
- Task scheduling and dependency resolution.
- Course prerequisite checking.
- Compilation order of code modules.
- Resolving symbol dependencies in linkers.

**Note:** Topological sorting is **only possible for DAGs**. If a cycle exists, no valid ordering can be found.

---

## Conclusion
Topological sorting is a fundamental graph algorithm used to determine the correct sequence of execution in dependency-based scenarios. DFS and BFS both provide efficient ways to achieve this, with DFS using recursion and BFS using an indegree-based approach.

