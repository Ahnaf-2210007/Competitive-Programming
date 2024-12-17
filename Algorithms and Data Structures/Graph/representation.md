## **Basic Information about Graphs**

A **graph** is a fundamental data structure used to model relationships between objects. It consists of:

1. **Vertices (Nodes)**: Represent the entities (points in the graph).  
2. **Edges**: Represent the relationships (connections) between the vertices.

### **Key Terms**
- **Vertices (V)**: Set of nodes in the graph.
- **Edges (E)**: Set of connections between nodes.
- **Directed Graph (Digraph)**: Edges have a direction, from one vertex to another (A → B).
- **Undirected Graph**: Edges do not have a direction (A — B).
- **Weighted Graph**: Edges have weights (cost, time, or distance).
- **Unweighted Graph**: Edges do not have weights.
- **Cycle**: A path where the start and end vertices are the same.
- **Path**: A sequence of vertices connected by edges.
- **Connected Graph**: Every vertex is reachable from every other vertex.
- **Disconnected Graph**: At least one pair of vertices is not connected.
- **Adjacency**: Two vertices are adjacent if they share an edge.

---

## **Types of Graphs**

1. **Directed Graph**:  
   - Edges have a direction (arrows).  
   - Example: One-way roads, dependency graphs.

2. **Undirected Graph**:  
   - Edges have no direction.  
   - Example: Two-way roads, social networks.

3. **Weighted Graph**:  
   - Each edge has a weight or cost.  
   - Example: Maps with distances, networks with latency.

4. **Unweighted Graph**:  
   - All edges have equal weights or no weights.

5. **Cyclic Graph**:  
   - Contains at least one cycle.

6. **Acyclic Graph**:  
   - No cycles exist.

7. **Tree**:  
   - A special type of acyclic, connected graph with \( V-1 \) edges.

8. **Bipartite Graph**:  
   - The vertices can be divided into two disjoint sets, where every edge connects vertices from different sets.

---

## **Graph Representation**

There are **3 main ways** to represent graphs in programming:

### **1. Adjacency Matrix**
- Uses a 2D matrix \( adj[N][N] \) where \( N \) is the number of vertices.
- **`adj[i][j] = 1`** if there is an edge between vertex \( i \) and \( j \), otherwise 0.

#### **Example of Adjacency Matrix**:
For a graph with \( 4 \) vertices and edges \( (0-1), (1-2), (2-3), (3-0) \):

|   | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| 0 | 0 | 1 | 0 | 1 |
| 1 | 1 | 0 | 1 | 0 |
| 2 | 0 | 1 | 0 | 1 |
| 3 | 1 | 0 | 1 | 0 |

**Code Implementation (C++):**
```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 4; // Number of vertices
    int adj[4][4] = {0};

    // Add edges
    adj[0][1] = adj[1][0] = 1; // Edge 0-1
    adj[1][2] = adj[2][1] = 1; // Edge 1-2
    adj[2][3] = adj[3][2] = 1; // Edge 2-3
    adj[3][0] = adj[0][3] = 1; // Edge 3-0

    // Print Adjacency Matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

- **Space Complexity**: \( O(V^2) \) (not efficient for sparse graphs).  
- **Best For**: Dense graphs.

---

### **2. Adjacency List**
- Uses an array of lists (or vectors).  
- Each vertex stores a list of its neighbors (connected vertices).

#### **Example of Adjacency List**:
For the same graph as above:
```
0 → [1, 3]
1 → [0, 2]
2 → [1, 3]
3 → [0, 2]
```

**Code Implementation (C++):**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4; // Number of vertices
    vector<int> adj[4]; // Adjacency List

    // Add edges
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(0);
    adj[3].push_back(2);

    // Print Adjacency List
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    return 0;
}
```

- **Space Complexity**: \( O(V + E) \).  
- **Best For**: Sparse graphs.

---

### **3. Edge List**
- Stores all edges as a list of pairs \( (u, v) \), where \( u \) and \( v \) are vertices connected by an edge.

#### **Example of Edge List**:
For the graph above:
```
Edges: (0, 1), (0, 3), (1, 2), (2, 3)
```

**Code Implementation (C++):**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int>> edges;

    // Add edges
    edges.push_back({0, 1});
    edges.push_back({0, 3});
    edges.push_back({1, 2});
    edges.push_back({2, 3});

    // Print Edge List
    cout << "Edge List:" << endl;
    for (auto edge : edges) {
        cout << edge.first << " - " << edge.second << endl;
    }
    return 0;
}
```

- **Space Complexity**: \( O(E) \).  
- **Best For**: Simple graph manipulation.

---

## **Comparison of Representations**

| **Representation**  | **Space Complexity** | **Advantages**                | **Disadvantages**           |
|----------------------|----------------------|--------------------------------|-----------------------------|
| Adjacency Matrix     | \( O(V^2) \)         | Simple, quick edge lookup      | Inefficient for sparse graphs |
| Adjacency List       | \( O(V + E) \)       | Space-efficient for sparse graphs | Slower edge lookup         |
| Edge List            | \( O(E) \)           | Compact, easy to manipulate   | Not suitable for edge queries |

---

## **Conclusion**
1. **Adjacency Matrix** is best for dense graphs or when edge lookups are frequent.
2. **Adjacency List** is the most common representation for general graphs.
3. **Edge List** is simple and works well for specific algorithms like Kruskal's MST.

Understanding these representations is crucial for solving graph-based problems in competitive programming and development. Let me know if you need further clarification! 🚀
