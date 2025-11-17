# Algorithm – Complete Implementation

A collection of classical algorithms implemented in C++, including Graph Algorithms, Greedy Algorithms, and Dynamic Programming.  
All programs take user input and follow clean, professional coding standards.  
This repository is ideal for university lab submissions and learning purposes.

---

## 🚀 Algorithms Included

### 1. BFS (Breadth-First Search)
- Traverses graph level-by-level  
- Finds shortest path in unweighted graph  
- Time Complexity: O(V + E)  
File: Graph Algorithms/bfs.cpp

---

### 2. DFS (Depth-First Search)
- Traverses graph deeply  
- Ideal for cycle detection and components  
- Time Complexity: O(V + E)  
File: Graph Algorithms/dfs.cpp

---

### 3. Dijkstra’s Algorithm
- Shortest path for weighted graphs  
- Works only with non-negative weights  
- Time Complexity: O(E log V)  
File: Graph Algorithms/dijkstra.cpp

---

### 4. Bellman-Ford Algorithm
- Handles negative weight edges  
- Detects negative cycles  
- Time Complexity: O(V × E)  
File: Graph Algorithms/bellman_ford.cpp

---

### 5. Activity Selection (Greedy)
- Maximum non-overlapping activities  
- Sort by finish time  
- Time Complexity: O(n log n)  
File: Greedy Algorithms/activity_selection.cpp

---

### 6. Fractional Knapsack (Greedy)
- Items can be split into fractions  
- Sorted by value/weight ratio  
- Time Complexity: O(n log n)  
File: Greedy Algorithms/fractional_knapsack.cpp

---

### 7. 0/1 Knapsack (Dynamic Programming)
- Items cannot be divided  
- Uses DP table  
- Time Complexity: O(nW)  
File: Dynamic Programming/zero_one_knapsack.cpp

---

## 🧪 How to Run the Programs

Using g++ compiler:

g++ bfs.cpp -o bfs
./bfs

Example for other programs:

g++ dijkstra.cpp -o dijkstra
./dijkstra

---

## 📥 Sample Input Formats

### BFS Example:
Number of nodes and edges: 5 4
Edges:
0 1
1 2
2 3
3 4
Starting node: 0


### Dijkstra Example:
Number of nodes and edges: 5 6
Edges (u v w):
0 1 2
0 2 5
1 3 1
2 3 2
1 4 7
3 4 3
Starting node: 0

### Activity Selection Input:
Number of activities: 6
Start Finish times:
1 2
3 4
0 6
5 7
5 9
8 9

---

## 👨‍💻 Author

Shaikh Arefin Zaman  
Department of Computer Science  
Bangladesh University of Business and Technology

GitHub username : ArefinZaman-dev

---

## ⭐ Contribution

Contributions, issues, and feature requests are welcome!  
Feel free to improve or add new algorithms.

---

## 📝 License

This project is open-source and free to use under the MIT License.

