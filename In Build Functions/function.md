Here is an **extended list of all the commonly used built-in functions** available under `<bits/stdc++.h>`, including **math, I/O, and other utilities**. Each entry includes a **short description, syntax, and its purpose**.

---

### **Math Functions** (from `<cmath>`)
1. **`abs(x)`**: Returns the absolute value of `x`.  
   *Syntax:* `int abs(int x);`  

2. **`sqrt(x)`**: Returns the square root of `x`.  
   *Syntax:* `double sqrt(double x);`  

3. **`pow(x, y)`**: Returns `x` raised to the power `y`.  
   *Syntax:* `double pow(double x, double y);`  

4. **`ceil(x)`**: Rounds up `x` to the nearest integer.  
   *Syntax:* `double ceil(double x);`  

5. **`floor(x)`**: Rounds down `x` to the nearest integer.  
   *Syntax:* `double floor(double x);`  

6. **`round(x)`**: Rounds `x` to the nearest integer.  
   *Syntax:* `double round(double x);`  

7. **`log(x)`**: Returns the natural logarithm of `x`.  
   *Syntax:* `double log(double x);`  

8. **`log10(x)`**: Returns the base-10 logarithm of `x`.  
   *Syntax:* `double log10(double x);`  

9. **`exp(x)`**: Returns `e^x` (exponential of `x`).  
   *Syntax:* `double exp(double x);`  

10. **`sin(x), cos(x), tan(x)`**: Returns the sine, cosine, or tangent of `x` (angle in radians).  
   *Syntax:* `double sin(double x);`  

11. **`asin(x), acos(x), atan(x)`**: Returns the arcsine, arccosine, or arctangent of `x`.  
   *Syntax:* `double asin(double x);`  

12. **`hypot(x, y)`**: Returns the Euclidean distance (sqrt(x² + y²)).  
   *Syntax:* `double hypot(double x, double y);`  

13. **`fmod(x, y)`**: Returns the remainder of `x/y`.  
   *Syntax:* `double fmod(double x, double y);`  

14. **`gcd(a, b)`**: Returns the greatest common divisor of `a` and `b`.  
   *Syntax:* `int gcd(int a, int b);`  

15. **`lcm(a, b)`**: Returns the least common multiple of `a` and `b`.  
   *Syntax:* `int lcm(int a, int b);`  

16. **`isnan(x)`**: Checks if `x` is "Not-a-Number" (NaN).  
   *Syntax:* `bool isnan(double x);`  

---

### **I/O Formatting** (from `<iomanip>`)
1. **`setprecision(n)`**: Sets the number of decimal points in floating-point output.  
   *Syntax:* `cout << setprecision(n) << (print what you want to print) << fixed;`  

2. **`setw(n)`**: Sets the width for the next output field.  
   *Syntax:* `cout << setw(n);`  

3. **`setfill(c)`**: Fills unused spaces with character `c`.  
   *Syntax:* `cout << setfill(c);`  

4. **`left`/`right`**: Adjusts alignment of text to left or right.  
   *Syntax:* `cout << left;`  

5. **`boolalpha`/`noboolalpha`**: Toggles output of `true/false` vs. `1/0` for boolean values.  
   *Syntax:* `cout << boolalpha;`  

---

### **Algorithm Functions** (from `<algorithm>`)
1. **`sort(begin, end)`**: Sorts elements in ascending order.  
   *Syntax:* `void sort(Iterator first, Iterator last);`  

2. **`reverse(begin, end)`**: Reverses the range of elements.  
   *Syntax:* `void reverse(Iterator first, Iterator last);`  

3. **`max(a, b)`**: Returns the greater of two elements.  
   *Syntax:* `const T& max(const T& a, const T& b);`  

4. **`min(a, b)`**: Returns the lesser of two elements.  
   *Syntax:* `const T& min(const T& a, const T& b);`  

5. **`accumulate(begin, end, init)`**: Computes the sum of elements with an initial value.  
   *Syntax:* `T accumulate(Iterator first, Iterator last, T init);`  

6. **`binary_search(begin, end, x)`**: Checks if `x` exists in a sorted range.  
   *Syntax:* `bool binary_search(Iterator first, Iterator last, const T& value);`  

7. **`lower_bound(begin, end, x)`**: Returns the iterator to the first element not less than `x`.  
   *Syntax:* `Iterator lower_bound(Iterator first, Iterator last, const T& value);`  

8. **`upper_bound(begin, end, x)`**: Returns the iterator to the first element greater than `x`.  
   *Syntax:* `Iterator upper_bound(Iterator first, Iterator last, const T& value);`  

9. **`next_permutation(begin, end)`**: Moves to the next lexicographic permutation.  
   *Syntax:* `bool next_permutation(Iterator first, Iterator last);`  

10. **`prev_permutation(begin, end)`**: Moves to the previous lexicographic permutation.  
   *Syntax:* `bool prev_permutation(Iterator first, Iterator last);`  

---

Here is a **complete list of commonly used functions from the `<string>` library** in C++. This includes utilities for string manipulation, conversion, and inspection. Each function includes a brief description and syntax.

---

### **String Initialization and Modification**
1. **`std::string()`**: Creates an empty string or initializes a string with a given value.  
   *Syntax:*  
   - `std::string s;`  
   - `std::string s = "Hello";`  

2. **`assign(str)`**: Replaces the current string with `str`.  
   *Syntax:* `s.assign(str);`  

3. **`append(str)`**: Appends `str` to the end of the string.  
   *Syntax:* `s.append(str);`  

4. **`insert(pos, str)`**: Inserts `str` at position `pos`.  
   *Syntax:* `s.insert(size_t pos, const std::string& str);`  

5. **`erase(pos, len)`**: Erases `len` characters starting at `pos`.  
   *Syntax:* `s.erase(size_t pos, size_t len);`  

6. **`replace(pos, len, str)`**: Replaces `len` characters at `pos` with `str`.  
   *Syntax:* `s.replace(size_t pos, size_t len, const std::string& str);`  

---

### **String Inspection**
1. **`length()` / `size()`**: Returns the length of the string.  
   *Syntax:* `size_t length() const;`  

2. **`empty()`**: Checks if the string is empty.  
   *Syntax:* `bool empty() const;`  

3. **`at(pos)`**: Returns the character at position `pos`.  
   *Syntax:* `char& at(size_t pos);`  

4. **`front()`**: Returns the first character in the string.  
   *Syntax:* `char& front();`  

5. **`back()`**: Returns the last character in the string.  
   *Syntax:* `char& back();`  

---

### **String Comparison**
1. **`compare(str)`**: Compares the string with `str`.  
   *Syntax:* `int compare(const std::string& str) const;`  
   - Returns `0` if equal, negative if this string is less, positive if greater.  

2. **`find(str)`**: Finds the first occurrence of `str` in the string.  
   *Syntax:* `size_t find(const std::string& str) const;`  

3. **`rfind(str)`**: Finds the last occurrence of `str`.  
   *Syntax:* `size_t rfind(const std::string& str) const;`  

4. **`find_first_of(chars)`**: Finds the first occurrence of any character in `chars`.  
   *Syntax:* `size_t find_first_of(const std::string& chars) const;`  

5. **`find_last_of(chars)`**: Finds the last occurrence of any character in `chars`.  
   *Syntax:* `size_t find_last_of(const std::string& chars) const;`  

6. **`find_first_not_of(chars)`**: Finds the first character not in `chars`.  
   *Syntax:* `size_t find_first_not_of(const std::string& chars) const;`  

7. **`find_last_not_of(chars)`**: Finds the last character not in `chars`.  
   *Syntax:* `size_t find_last_not_of(const std::string& chars) const;`  

---

### **String Substrings and Access**
1. **`substr(pos, len)`**: Returns a substring starting at `pos` with `len` characters.  
   *Syntax:* `std::string substr(size_t pos = 0, size_t len = npos) const;`  

---

### **String Conversion**
1. **`std::to_string(val)`**: Converts numeric values (`int`, `float`, `double`, etc.) to strings.  
   *Syntax:* `std::string to_string(int val);`  

2. **`std::stoi(str)`**: Converts a string to an integer.  
   *Syntax:* `int stoi(const std::string& str);`
   *Syntax:* `int a = stoi(s, nullptr, 2);` 

4. **`std::stol(str)`**: Converts a string to a `long`.  
   *Syntax:* `long stol(const std::string& str);`  

5. **`std::stoll(str)`**: Converts a string to a `long long`.  
   *Syntax:* `long long stoll(const std::string& str);`  

6. **`std::stof(str)`**: Converts a string to a `float`.  
   *Syntax:* `float stof(const std::string& str);`  

7. **`std::stod(str)`**: Converts a string to a `double`.  
   *Syntax:* `double stod(const std::string& str);`  

8. **`std::stold(str)`**: Converts a string to a `long double`.  
   *Syntax:* `long double stold(const std::string& str);`  

9. **`std::bitset<N>(str)`**: Converts a binary string to a `bitset`.  
   *Syntax:* `std::bitset<N>(const std::string& str);`  

---

### **String Trimming and Case Conversion** (Custom Implementations Required)
The standard `<string>` library does not have built-in functions for trimming or case conversion. These must be implemented manually or using external libraries like Boost.

---

### **Other Utilities**
1. **`c_str()`**: Returns a pointer to a null-terminated C-string.  
   *Syntax:* `const char* c_str() const;`  

2. **`data()`**: Returns a pointer to the internal data of the string (like `c_str` but not null-terminated).  
   *Syntax:* `const char* data() const;`  

3. **`resize(n)`**: Resizes the string to contain `n` characters.  
   *Syntax:* `void resize(size_t n);`  

4. **`swap(s)`**: Swaps the contents of two strings.  
   *Syntax:* `void swap(std::string& s);`  

5. **`copy(buffer, len, pos)`**: Copies `len` characters from the string starting at `pos` into `buffer`.  
   *Syntax:* `size_t copy(char* buffer, size_t len, size_t pos = 0) const;`  

</br>


This list includes almost every function from the `<string>` library. If you need examples for any of them or want to explore advanced usage (e.g., using iterators), let me know!

---

Here’s a detailed list of commonly used **built-in STL (Standard Template Library) functions** in C++ for containers like **pair**, **map**, **set**, **stack**, and **queue**, along with their **purpose** and **syntax**.

---

## **1. Pair**
A `pair` is a container for two values of possibly different types.

### Common Functions
1. **`std::make_pair(a, b)`**  
   Creates a `pair` object containing `a` and `b`.  
   *Syntax:* `std::pair<T1, T2> p = std::make_pair(a, b);`

2. **`p.first`**  
   Accesses the first element of the pair.  
   *Syntax:* `T1 first;`

3. **`p.second`**  
   Accesses the second element of the pair.  
   *Syntax:* `T2 second;`

---

## **2. Map (Associative Container)**
A `map` stores key-value pairs in sorted order by key.

### Common Functions
1. **`m[key]`**  
   Accesses the value associated with `key` (inserts if key does not exist).  
   *Syntax:* `T& operator[](const Key& key);`

2. **`m.at(key)`**  
   Accesses the value associated with `key` (throws if key does not exist).  
   *Syntax:* `T& at(const Key& key);`

3. **`m.insert({key, value})`**  
   Inserts a key-value pair into the map.  
   *Syntax:* `void insert(const std::pair<Key, T>&);`

4. **`m.erase(key)`**  
   Removes an element by key.  
   *Syntax:* `size_t erase(const Key& key);`

5. **`m.find(key)`**  
   Returns an iterator to the element with the given key (or `m.end()` if not found).  
   *Syntax:* `Iterator find(const Key& key);`

6. **`m.count(key)`**  
   Checks if a key exists (`1` if exists, otherwise `0`).  
   *Syntax:* `size_t count(const Key& key);`

7. **`m.clear()`**  
   Removes all elements.  
   *Syntax:* `void clear();`

8. **`m.empty()`**  
   Checks if the map is empty.  
   *Syntax:* `bool empty() const;`

9. **`m.size()`**  
   Returns the number of elements in the map.  
   *Syntax:* `size_t size() const;`

10. **`m.lower_bound(key)`**  
    Returns an iterator to the first element not less than `key`.  
    *Syntax:* `Iterator lower_bound(const Key& key);`

11. **`m.upper_bound(key)`**  
    Returns an iterator to the first element greater than `key`.  
    *Syntax:* `Iterator upper_bound(const Key& key);`

---

## **3. Set**
A `set` is an ordered collection of unique elements.

### Common Functions
1. **`s.insert(x)`**  
   Inserts the element `x` into the set.  
   *Syntax:* `void insert(const T& x);`

2. **`s.erase(x)`**  
   Removes the element `x` from the set.  
   *Syntax:* `size_t erase(const T& x);`

3. **`s.find(x)`**  
   Returns an iterator to the element `x` (or `s.end()` if not found).  
   *Syntax:* `Iterator find(const T& x);`

4. **`s.count(x)`**  
   Checks if the element `x` exists (`1` if exists, otherwise `0`).  
   *Syntax:* `size_t count(const T& x);`

5. **`s.lower_bound(x)`**  
   Returns an iterator to the first element not less than `x`.  
   *Syntax:* `Iterator lower_bound(const T& x);`

6. **`s.upper_bound(x)`**  
   Returns an iterator to the first element greater than `x`.  
   *Syntax:* `Iterator upper_bound(const T& x);`

7. **`s.empty()`**  
   Checks if the set is empty.  
   *Syntax:* `bool empty() const;`

8. **`s.size()`**  
   Returns the number of elements in the set.  
   *Syntax:* `size_t size() const;`

9. **`s.clear()`**  
   Removes all elements from the set.  
   *Syntax:* `void clear();`

---

## **4. Stack**
A `stack` is a last-in, first-out (LIFO) container.

### Common Functions
1. **`st.push(x)`**  
   Adds `x` to the top of the stack.  
   *Syntax:* `void push(const T& x);`

2. **`st.pop()`**  
   Removes the top element of the stack.  
   *Syntax:* `void pop();`

3. **`st.top()`**  
   Returns the top element of the stack.  
   *Syntax:* `T& top();`

4. **`st.empty()`**  
   Checks if the stack is empty.  
   *Syntax:* `bool empty() const;`

5. **`st.size()`**  
   Returns the number of elements in the stack.  
   *Syntax:* `size_t size() const;`

---

## **5. Queue**
A `queue` is a first-in, first-out (FIFO) container.

### Common Functions
1. **`q.push(x)`**  
   Adds `x` to the end of the queue.  
   *Syntax:* `void push(const T& x);`

2. **`q.pop()`**  
   Removes the element at the front of the queue.  
   *Syntax:* `void pop();`

3. **`q.front()`**  
   Returns the element at the front of the queue.  
   *Syntax:* `T& front();`

4. **`q.back()`**  
   Returns the element at the back of the queue.  
   *Syntax:* `T& back();`

5. **`q.empty()`**  
   Checks if the queue is empty.  
   *Syntax:* `bool empty() const;`

6. **`q.size()`**  
   Returns the number of elements in the queue.  
   *Syntax:* `size_t size() const;`

---

## **6. Priority Queue**
A `priority_queue` is a max-heap by default.

### Common Functions
1. **`pq.push(x)`**  
   Adds `x` to the priority queue.  
   *Syntax:* `void push(const T& x);`

2. **`pq.pop()`**  
   Removes the largest element.  
   *Syntax:* `void pop();`

3. **`pq.top()`**  
   Returns the largest element.  
   *Syntax:* `const T& top();`

4. **`pq.empty()`**  
   Checks if the priority queue is empty.  
   *Syntax:* `bool empty() const;`

5. **`pq.size()`**  
   Returns the number of elements.  
   *Syntax:* `size_t size() const;`

---

This list covers all the common functions of STL containers. Let me know if you need examples or specific use cases!
