Here’s a list of **important custom functions** that are frequently needed in **competitive programming** but are **not built into STL**. These include recursive, mathematical, and algorithmic functions.

---

## **1. Factorial (Recursive)**  
Calculates the factorial of a number.

### Code
```cpp
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}
```

---

## **2. Power with Modulo (Recursive or Iterative)**  
Calculates `(base^exp) % mod` efficiently using **modular exponentiation**.

### Code
```cpp
long long powerMod(long long base, long long exp, long long mod) {
    if (exp == 0) return 1;
    long long half = powerMod(base, exp / 2, mod);
    half = (half * half) % mod;
    return (exp % 2 == 0) ? half : (half * base) % mod;
}
```

---

## **3. Greatest Common Divisor (GCD)**  
Finds the greatest common divisor using Euclid's algorithm.

### Code
```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

---

## **4. Least Common Multiple (LCM)**  
Calculates the least common multiple using GCD.

### Code
```cpp
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
```

---

## **5. Sieve of Eratosthenes**  
Finds all prime numbers up to a given limit efficiently.

### Code
```cpp
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
```

---

## **6. Extended Euclid's Algorithm**  
Calculates GCD and also finds coefficients `x` and `y` for the equation:  
`ax + by = gcd(a, b)`.

### Code
```cpp
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}
```

---

## **7. Binary Search (Custom)**  
Performs binary search on a sorted array.

### Code
```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Element not found
}
```

---

## **8. Fibonacci (Recursive and Iterative)**  
Generates the Fibonacci sequence. For large values, use **matrix exponentiation**.

### Recursive Code
```cpp
long long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### Iterative Code (More Efficient)
```cpp
long long fibonacci(int n) {
    if (n <= 1) return n;
    long long prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        long long temp = curr;
        curr += prev;
        prev = temp;
    }
    return curr;
}
```

---

## **9. Modular Inverse**  
Calculates the modular multiplicative inverse of `a` under modulo `m`.

### Code (Using Extended GCD)
```cpp
int modInverse(int a, int m) {
    int x, y;
    int g = extendedGCD(a, m, x, y);
    if (g != 1) return -1; // Inverse does not exist
    return (x % m + m) % m;
}
```

---

## **10. Combination Formula**  
Computes \( C(n, r) \), the number of combinations, efficiently.

### Code
```cpp
long long combination(int n, int r, long long mod) {
    vector<long long> fact(n + 1, 1);
    for (int i = 2; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    return (fact[n] * modInverse(fact[r], mod) % mod * modInverse(fact[n - r], mod) % mod) % mod;
}
```

---

## **11. Fast Input/Output for Large Data**  
Custom functions to handle large input and output efficiently.

### Code
```cpp
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
```

---

## **12. Custom Comparator for Sorting**  
Sorts based on custom rules.

### Code
```cpp
bool customComparator(pair<int, int>& a, pair<int, int>& b) {
    if (a.second != b.second)
        return a.second > b.second; // Sort by second element in descending order
    return a.first < b.first;      // If tie, sort by first in ascending order
}
```

Usage:
```cpp
sort(v.begin(), v.end(), customComparator);
```

---

## **13. Subset Generation (Backtracking)**  
Generates all subsets of a set.

### Code
```cpp
void generateSubsets(vector<int>& nums, vector<int>& subset, int index) {
    if (index == nums.size()) {
        for (int x : subset) cout << x << " ";
        cout << endl;
        return;
    }
    generateSubsets(nums, subset, index + 1); // Exclude
    subset.push_back(nums[index]);            // Include
    generateSubsets(nums, subset, index + 1);
    subset.pop_back();
}
```

---

Here’s an extended list of **custom functions** that are useful in competitive programming, covering diverse topics like geometry, graph algorithms, and advanced mathematical techniques. These functions are not directly available as built-in functions but are commonly required in contests.

---

## **14. Prefix Sum**
Calculates prefix sums of an array for quick range sum queries.

### Code
```cpp
vector<int> prefixSum(const vector<int>& arr) {
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++)
        prefix[i] = prefix[i - 1] + arr[i];
    return prefix;
}
```

---

## **15. Prime Factorization**
Finds the prime factors of a number.

### Code
```cpp
vector<pair<int, int>> primeFactorization(int n) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            factors.push_back({i, count});
        }
    }
    if (n > 1)
        factors.push_back({n, 1});
    return factors;
}
```

---

## **16. Compute Divisors**
Generates all divisors of a number.

### Code
```cpp
vector<int> divisors(int n) {
    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i)
                divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}
```

---

## **17. 2D Grid Traversal**
Helper function to traverse a grid with 4-directional or 8-directional movement.

### Code
```cpp
const int dx[4] = {-1, 0, 1, 0}; // Up, Right, Down, Left
const int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}
```

---

## **18. Fast Matrix Exponentiation**
Efficiently computes powers of matrices for problems involving recurrence relations.

### Code
```cpp
vector<vector<long long>> multiply(vector<vector<long long>>& a, vector<vector<long long>>& b, int mod) {
    int n = a.size();
    vector<vector<long long>> result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % mod;
    return result;
}

vector<vector<long long>> matrixExpo(vector<vector<long long>>& base, int exp, int mod) {
    int n = base.size();
    vector<vector<long long>> result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) result[i][i] = 1; // Identity matrix
    while (exp) {
        if (exp % 2)
            result = multiply(result, base, mod);
        base = multiply(base, base, mod);
        exp /= 2;
    }
    return result;
}
```

---

## **19. Topological Sort (Graph)**
Performs a topological sort on a directed acyclic graph (DAG).

### Code
```cpp
void topologicalSort(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& stk) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            topologicalSort(neighbor, adj, visited, stk);
    }
    stk.push(node);
}
```

---

## **20. Depth-First Search (DFS)**
Basic DFS implementation for graph traversal.

### Code
```cpp
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}
```

---

## **21. Breadth-First Search (BFS)**
Basic BFS implementation for shortest paths or level-order traversal.

### Code
```cpp
void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

---

## **22. Modular Arithmetic Utilities**
Precomputes modular factorials or calculates modular addition/multiplication.

### Code
```cpp
long long modAdd(long long a, long long b, long long mod) {
    return (a + b) % mod;
}

long long modMul(long long a, long long b, long long mod) {
    return (a * b) % mod;
}

long long modSub(long long a, long long b, long long mod) {
    return ((a - b) % mod + mod) % mod;
}
```

---

## **23. Longest Common Subsequence (LCS)**
Dynamic programming implementation to find LCS between two strings.

### Code
```cpp
int LCS(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
```

---

## **24. Binary Lifting (for LCA)**
Efficient way to find the Lowest Common Ancestor (LCA) in a tree.

### Code (Initialization Only)
```cpp
void binaryLifting(int node, int parent, vector<vector<int>>& up, vector<int> adj[]) {
    up[node][0] = parent;
    for (int i = 1; i < up[0].size(); i++) {
        if (up[node][i - 1] != -1)
            up[node][i] = up[up[node][i - 1]][i - 1];
    }
    for (int neighbor : adj[node]) {
        if (neighbor != parent)
            binaryLifting(neighbor, node, up, adj);
    }
}
```

---

## **25. Knapsack Problem (Dynamic Programming)**  
Solves the 0/1 knapsack problem.

### Code
```cpp
int knapsack(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}
```

---
