# Unit 1 — Algorithm Analysis, Searching & Sorting

> **Course:** Design and Analysis of Algorithms (DAA)  
> **Unit:** 01  
> **Topics:** Searching, Sorting, Algorithm Analysis, Divide and Conquer

---

## Table of Contents

1. [Introduction to Algorithm Analysis](#1-introduction-to-algorithm-analysis)
2. [Running Time Analysis and Correctness](#2-running-time-analysis-and-correctness)
3. [Searching Algorithms](#3-searching-algorithms)
   - Linear Search
   - Binary Search
4. [Elementary Sorting Algorithms](#4-elementary-sorting-algorithms)
   - Insertion Sort
   - Selection Sort
   - Bubble Sort
5. [Heapsort](#5-heapsort)
6. [Linear-Time Sorting](#6-linear-time-sorting)
7. [Divide and Conquer](#7-introduction-to-divide-and-conquer)
8. [Merge Sort](#8-merge-sort)
9. [Quick Sort](#9-quick-sort)
10. [Randomized Quick Sort](#10-randomized-quick-sort)
11. [Maximum Subarray Problem](#11-maximum-subarray-problem)
12. [Strassen's Matrix Multiplication](#12-strassens-matrix-multiplication)
13. [Algorithm Complexity Cheat Sheet](#13-algorithm-complexity-cheat-sheet)

---

# 1. Introduction to Algorithm Analysis

An **algorithm** is a finite sequence of well-defined instructions designed to solve a computational problem.

Algorithm analysis evaluates the efficiency of an algorithm primarily in terms of:

- **Time Complexity:** Amount of computational time required as a function of input size.
- **Space Complexity:** Amount of additional memory required as a function of input size.
- **Correctness:** Whether the algorithm produces the expected output for every valid input.

### Asymptotic Notations

Asymptotic notation describes how an algorithm's resource requirements grow as the input size approaches infinity.

| Notation | Meaning | Interpretation |
|---|---|---|
| Big-O | $O(g(n))$ | Asymptotic upper bound |
| Big-Omega | $\Omega(g(n))$ | Asymptotic lower bound |
| Big-Theta | $\Theta(g(n))$ | Tight asymptotic bound |
| Little-o | $o(g(n))$ | Strict asymptotic upper bound |
| Little-omega | $\omega(g(n))$ | Strict asymptotic lower bound |

### Common Growth Rates

Ordered approximately from slowest to fastest growth:

$$
O(1) < O(\log n) < O(n) < O(n\log n)
$$

$$
< O(n^2) < O(n^3) < O(2^n) < O(n!)
$$

---

# 2. Running Time Analysis and Correctness

## Running Time Analysis

Running time is expressed as a function of input size \(n\).

Three common cases:

- **Best Case:** Minimum time required for any input of size \(n\).
- **Average Case:** Expected running time over a specified input distribution.
- **Worst Case:** Maximum time required for any input of size \(n\).

### Important Rules

1. Sequential statements: Add their running times.
2. Nested loops: Multiply iteration counts when appropriate.
3. Conditional statements: Consider the cost of the condition and the executed branch.
4. Recursive algorithms: Form and solve recurrence relations.
5. Ignore constant factors and lower-order terms in asymptotic analysis.

## Algorithm Correctness

An algorithm is correct if it produces the required output for every valid input and terminates.

### Loop Invariants

A loop invariant is a property that remains true before and after every iteration of a loop.

Three steps establish correctness using a loop invariant:

1. **Initialization:** The invariant holds before the first iteration.
2. **Maintenance:** If it holds before an iteration, it remains true afterward.
3. **Termination:** When the loop terminates, the invariant establishes the algorithm's correctness.

---

# 3. Searching Algorithms

## 3.1 Linear Search

Linear Search sequentially examines each element until the target is found or the array ends.

**Algorithm:**
```text
LINEAR-SEARCH(A, n, key)
    for i = 0 to n-1
        if A[i] == key
            return i
    return -1
```

**Complexity Analysis:**

| Case | Time Complexity |
|---|---|
| Best | O(1) |
| Average | O(n) |
| Worst | O(n) |
| Space | O(1) |

**Properties:**
- Works on both sorted and unsorted arrays.
- Simple to implement.
- No preprocessing required.
- Inefficient for large datasets.

## 3.2 Binary Search

Binary Search repeatedly divides the search interval into two halves.

**Prerequisite:** The input array must be sorted.

**Algorithm:**
```text
BINARY-SEARCH(A, low, high, key)
    while low <= high
        mid = low + (high - low) / 2

        if A[mid] == key
            return mid

        else if A[mid] < key
            low = mid + 1

        else
            high = mid - 1

    return -1
```

**Complexity Analysis:**

| Case | Time Complexity |
|---|---|
| Best | O(1) |
| Average | O(log n) |
| Worst | O(log n) |
| Space (Iterative) | O(1) |
| Space (Recursive) | O(log n) |

**Properties:**
- Requires sorted data.
- Uses divide and conquer.
- Much faster than linear search for large sorted arrays.
- The midpoint calculation avoids potential integer overflow.

---

# 4. Elementary Sorting Algorithms

## 4.1 Insertion Sort

Insertion Sort builds a sorted portion of the array one element at a time.

Each new element is inserted into its correct position within the already sorted portion.

**Algorithm:**
```text
INSERTION-SORT(A, n)
    for i = 1 to n-1
        key = A[i]
        j = i - 1

        while j >= 0 and A[j] > key
            A[j+1] = A[j]
            j = j - 1

        A[j+1] = key
```

**Complexity Analysis:**

| Case | Time Complexity |
|---|---|
| Best | O(n) |
| Average | O(n²) |
| Worst | O(n²) |
| Space | O(1) |

**Properties:**
- Stable sorting algorithm.
- In-place sorting.
- Adaptive: Performs efficiently on nearly sorted arrays.
- Suitable for small datasets.

## 4.2 Selection Sort

Selection Sort repeatedly selects the minimum element from the unsorted portion and places it at the beginning.

**Algorithm:**
```text
SELECTION-SORT(A, n)
    for i = 0 to n-2
        minIndex = i

        for j = i+1 to n-1
            if A[j] < A[minIndex]
                minIndex = j

        swap A[i] and A[minIndex]
```

**Complexity Analysis:**

| Case | Time Complexity |
|---|---|
| Best | O(n²) |
| Average | O(n²) |
| Worst | O(n²) |
| Space | O(1) |

**Properties:**
- Standard implementation is not stable.
- In-place sorting algorithm.
- Performs at most $\(n-1\)$ swaps.
- Not adaptive to nearly sorted data.

## 4.3 Bubble Sort

Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.

After each pass, the largest unsorted element moves to its correct position.

**Algorithm:**
```text
BUBBLE-SORT(A, n)
    for i = 0 to n-2
        swapped = false

        for j = 0 to n-i-2
            if A[j] > A[j+1]
                swap A[j], A[j+1]
                swapped = true

        if swapped == false
            break
```

**Complexity Analysis:**

| Case | Time Complexity |
|---|---|
| Best | O(n) |
| Average | O(n²) |
| Worst | O(n²) |
| Space | O(1) |

**Properties:**
- Stable sorting algorithm.
- In-place sorting.
- Optimized version is adaptive.
- Inefficient for large datasets.

---

# 5. Heapsort

Heapsort is a comparison-based sorting algorithm that uses a Binary Heap data structure.

### Binary Heap

A Binary Heap is a complete binary tree satisfying the heap property.

**Max Heap:** Every parent node is greater than or equal to its children.

**Min Heap:** Every parent node is less than or equal to its children.

For an array representation using 0-based indexing:

| Relationship | Index |
|---|---|
| Parent | $\lfloor(i-1)/2\rfloor$ |
| Left Child | $\2i+1\$ |
| Right Child | $\(2i+2\$ |

### Heap Operations

- **MAX-HEAPIFY:** Restores the max-heap property at a node.
- **BUILD-MAX-HEAP:** Constructs a max heap from an unordered array.
- **HEAPSORT:** Repeatedly extracts the maximum element and places it at the end.

### Algorithm

```text
HEAPSORT(A, n)
    BUILD-MAX-HEAP(A)

    for i = n-1 down to 1
        swap A[0], A[i]
        heapSize = heapSize - 1
        MAX-HEAPIFY(A, 0)
```

### Complexity Analysis

| Operation | Time Complexity |
|---|---|
| MAX-HEAPIFY | O(log n) |
| BUILD-MAX-HEAP | O(n) |
| Extract Maximum | O(log n) |
| Heapsort | O(n log n) |

**Properties:**
- Best, average and worst-case time: \(O(n\log n)\).
- In-place sorting algorithm.
- Standard implementation is not stable.
- Provides guaranteed worst-case performance.

---

# 6. Linear-Time Sorting

Comparison-based sorting algorithms have a worst-case lower bound of:

$$
\Omega(n\log n)
$$

However, algorithms that exploit properties of the input can achieve linear-time sorting under suitable assumptions.

### 6.1 Counting Sort

Counting Sort sorts elements by counting the frequency of each distinct key.

**Working:**
1. Find the range of input values.
2. Count the occurrences of each value.
3. Compute cumulative frequencies.
4. Place elements in their correct output positions.

**Complexity:**

$$
T(n,k)=O(n+k)
$$

Where:
- $\(n$ = Number of elements.
- $\(k$ = Range of possible keys.

**Properties:**
- Non-comparison-based sorting.
- Stable when implemented using cumulative counts and reverse traversal.
- Requires additional memory.
- Effective when the key range is not excessively large.

### 6.2 Radix Sort

Radix Sort processes numbers digit by digit, typically from the least significant digit to the most significant digit.

It uses a stable sorting algorithm, commonly Counting Sort, at each digit position.

**Complexity:**

$$
T(n)=O(d(n+k))
$$

Where:
- $\d\)$ = Number of digit positions.
- $(k\)$ = Range of each digit.

### 6.3 Bucket Sort

Bucket Sort distributes elements into multiple buckets, sorts individual buckets, and concatenates the results.

**Expected Complexity:**

$$
O(n)
$$

Under suitable distribution assumptions.

**Comparison:**

| Algorithm | Time Complexity | Additional Space |
|---|---|---|
| Counting Sort | O(n+k) | O(n+k) |
| Radix Sort | O(d(n+k)) | O(n+k) |
| Bucket Sort | Expected O(n) | O(n+k) |

---

# 7. Introduction to Divide and Conquer

Divide and Conquer is an algorithm design paradigm that solves a problem by breaking it into smaller subproblems.

### Three Fundamental Steps

1. **Divide:** Break the original problem into smaller subproblems.
2. **Conquer:** Solve the subproblems recursively.
3. **Combine:** Merge the solutions to obtain the final result.

### General Structure

```text
DIVIDE-AND-CONQUER(problem)
    if problem is small
        solve directly

    divide problem into subproblems

    solve each subproblem recursively

    combine their solutions

    return final result
```

### Recurrence Relations

A common recurrence for divide-and-conquer algorithms is:

$$
T(n)=aT(n/b)+f(n)
$$

Where:
- $\(a\$ = Number of subproblems.
- $\(n/b\$ = Size of each subproblem.
- $\(f(n)\$ = Division and combination cost.

### Master Theorem

For:

$$
T(n)=aT(n/b)+f(n)
$$

Let:

$$
c=\log_b a
$$

**Case 1:**

If $\(f(n)=O(n^{c-\epsilon})\)$, then:

$$
T(n)=\Theta(n^c)
$$

**Case 2:**

If $\(f(n)=\Theta(n^c\log^k n)\)$, then:

$$
T(n)=\Theta(n^c\log^{k+1}n)
$$

**Case 3:**

If $\(f(n)=\Omega(n^{c+\epsilon})\)$, and the regularity condition holds, then:

$$
T(n)=\Theta(f(n))
$$

---

# 8. Merge Sort

Merge Sort is a stable comparison-based sorting algorithm based on divide and conquer.

### Working

1. Divide the array into two halves.
2. Recursively sort both halves.
3. Merge the two sorted halves into a single sorted array.

### Algorithm

```text
MERGE-SORT(A, low, high)
    if low < high
        mid = floor((low + high) / 2)

        MERGE-SORT(A, low, mid)
        MERGE-SORT(A, mid+1, high)

        MERGE(A, low, mid, high)
```

### Recurrence Relation

$$
T(n)=2T(n/2)+O(n)
$$

Using the Master Theorem:

$$
\boxed{T(n)=\Theta(n\log n)}
$$

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n log n) |
| Auxiliary Space | O(n) |

**Properties:**
- Stable sorting algorithm.
- Not in-place in its standard array implementation.
- Predictable performance.
- Particularly useful for linked lists and external sorting.

---

# 9. Quick Sort

Quick Sort is a divide-and-conquer sorting algorithm that partitions an array around a selected pivot.

### Working

1. Select a pivot element.
2. Partition the array so that elements smaller than or equal to the pivot appear before it, and larger elements appear after it.
3. Recursively sort the two partitions.

### Algorithm

```text
QUICK-SORT(A, low, high)
    if low < high
        p = PARTITION(A, low, high)

        QUICK-SORT(A, low, p-1)
        QUICK-SORT(A, p+1, high)
```

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n²) |
| Auxiliary Space | O(log n) average |

**Properties:**
- Usually in-place apart from recursion stack.
- Standard implementation is not stable.
- Excellent practical performance.
- Worst case occurs when partitions are highly unbalanced.

### Partitioning

Partitioning rearranges elements around the pivot and returns its final position.

# Unit 2 — Graph Algorithms & Greedy Algorithms

> **Course:** Design and Analysis of Algorithms (DAA)  
> **Unit:** 02  
> **Topics:** Graph Traversals, Connectivity, Bipartiteness, DAGs, Greedy Algorithms, Minimum Spanning Trees, Shortest Paths and Optimization Problems.

---

## Table of Contents

1. [Introduction to Graphs](#1-introduction-to-graphs)
2. [Graph Traversals](#2-review-of-graph-traversals)
   - Breadth-First Search (BFS)
   - Depth-First Search (DFS)
3. [Graph Connectivity](#3-graph-connectivity)
4. [Testing Bipartiteness](#4-testing-bipartiteness)
5. [Directed Acyclic Graphs and Topological Ordering](#5-directed-acyclic-graphs-and-topological-ordering)
6. [Introduction to Greedy Algorithms](#6-introduction-to-the-greedy-algorithm-design-approach)
7. [Minimum Spanning Trees](#7-minimum-spanning-trees)
   - Kruskal's Algorithm
   - Prim's Algorithm
8. [Shortest Path Problems](#8-shortest-path-problems)
   - BFS for Unweighted Graphs
   - Dijkstra's Algorithm
   - Bellman-Ford Algorithm
   - Shortest Paths in DAGs
9. [Interval Scheduling](#9-interval-scheduling)
10. [Fractional Knapsack Problem](#10-fractional-knapsack-problem)
11. [Analysis of Time Complexity](#11-analysis-of-time-complexity)
12. [Algorithm Complexity Cheat Sheet](#12-algorithm-complexity-cheat-sheet)

---

# 1. Introduction to Graphs

A **graph** is a mathematical structure consisting of a set of vertices (nodes) and a set of edges connecting pairs of vertices.

A graph is represented as:

\[
G=(V,E)
\]

Where:

- \(V\) = Set of vertices.
- \(E\) = Set of edges.

### Types of Graphs

| Graph Type | Description |
|---|---|
| Undirected Graph | Edges have no direction. |
| Directed Graph | Edges have a specified direction. |
| Weighted Graph | Edges have associated weights or costs. |
| Unweighted Graph | Edges have no explicitly assigned weights. |
| Connected Graph | Every pair of vertices has a path between them. |
| Complete Graph | Every pair of distinct vertices is connected by an edge. |
| Bipartite Graph | Vertices can be divided into two independent sets. |
| Cyclic Graph | Contains at least one cycle. |
| Acyclic Graph | Contains no cycles. |

### Graph Representation

Graphs are commonly represented using two approaches.

**1. Adjacency Matrix**

A two-dimensional matrix where:

\[
A[i][j]=
\begin{cases}
1 & \text{if edge }(i,j)\text{ exists}\\
0 & \text{otherwise}
\end{cases}
\]

For weighted graphs, the matrix stores edge weights instead of simply 0 and 1.

- Space Complexity: \(O(V^2)\)
- Checking whether an edge exists: \(O(1)\)
- Iterating over all neighbours: \(O(V)\)

**2. Adjacency List**

Each vertex maintains a list of its neighbouring vertices.

- Space Complexity: \(O(V+E)\)
- Checking for an edge: \(O(\deg(v))\)
- Iterating over neighbours: \(O(\deg(v))\)

**Comparison:**

| Feature | Adjacency Matrix | Adjacency List |
|---|---|---|
| Space | O(V²) | O(V+E) |
| Edge Lookup | O(1) | O(degree) |
| Neighbour Traversal | O(V) | O(degree) |
| Suitable For | Dense graphs | Sparse graphs |

---

# 2. Review of Graph Traversals

Graph traversal refers to systematically visiting the vertices of a graph.

Two fundamental traversal algorithms are:

1. Breadth-First Search (BFS)
2. Depth-First Search (DFS)

## 2.1 Breadth-First Search (BFS)

BFS explores a graph level by level, visiting all immediate neighbours before moving to the next level.

It uses a **Queue (FIFO)** data structure.

### Algorithm

```text
BFS(G, source)
    create an empty queue Q

    mark source as visited
    distance[source] = 0
    enqueue(Q, source)

    while Q is not empty
        u = dequeue(Q)

        for each neighbour v of u
            if v is not visited
                mark v as visited
                distance[v] = distance[u] + 1
                parent[v] = u
                enqueue(Q, v)
```

### Working

1. Start from a source vertex.
2. Mark it as visited and insert it into the queue.
3. Remove the front vertex from the queue.
4. Visit all its unvisited neighbours.
5. Insert the newly discovered vertices into the queue.
6. Repeat until the queue becomes empty.

### Complexity Analysis

| Representation | Time Complexity |
|---|---|
| Adjacency List | O(V + E) |
| Adjacency Matrix | O(V²) |
| Auxiliary Space | O(V) |

### Applications

- Finding shortest paths in unweighted graphs.
- Finding connected components.
- Testing graph bipartiteness.
- Level-order traversal of trees.
- Finding minimum number of edges between two vertices.

**Important:** BFS finds shortest paths in terms of the number of edges in an unweighted graph. It does not generally find minimum-weight paths in weighted graphs.

## 2.2 Depth-First Search (DFS)

DFS explores as far as possible along one path before backtracking.

It uses a **Stack (LIFO)**, either explicitly or through recursion.

### Algorithm

```text
DFS(G, u)
    mark u as visited

    for each neighbour v of u
        if v is not visited
            DFS(G, v)
```

For a disconnected graph, DFS must be initiated from every unvisited vertex:

```text
DFS-TRAVERSAL(G)
    for each vertex u in V
        if u is not visited
            DFS(G, u)
```

### Working

1. Start from a vertex.
2. Mark it as visited.
3. Visit an unvisited neighbour recursively.
4. Continue exploring deeper until no unvisited neighbour remains.
5. Backtrack and explore remaining neighbours.

### Complexity Analysis

| Representation | Time Complexity |
|---|---|
| Adjacency List | O(V + E) |
| Adjacency Matrix | O(V²) |
| Auxiliary Space | O(V) |

### Applications

- Cycle detection.
- Finding connected components.
- Topological sorting.
- Testing graph connectivity.
- Finding strongly connected components.
- Detecting paths between vertices.

### BFS vs DFS

| Feature | BFS | DFS |
|---|---|---|
| Data Structure | Queue | Stack / Recursion |
| Exploration | Level by level | Depth first |
| Shortest Path | Yes, unweighted graphs | Not guaranteed |
| Cycle Detection | Possible | Possible |
| Topological Sorting | Not standard | Yes |
| Time Complexity | O(V + E) | O(V + E) |

---

# 3. Graph Connectivity

Connectivity describes whether vertices in a graph are reachable from one another.

## 3.1 Connected Graph

An undirected graph is connected if there exists a path between every pair of vertices.

If some vertices cannot be reached from others, the graph is disconnected.

### Connected Components

A connected component is a maximal connected subgraph.

**Finding Connected Components Using DFS:**

```text
CONNECTED-COMPONENTS(G)
    count = 0

    for each vertex u in V
        if u is not visited
            count = count + 1
            DFS(G, u)

    return count
```

Each new DFS traversal identifies another connected component.

**Complexity:**

\[
O(V+E)
\]

## 3.2 Connectivity in Directed Graphs

Directed graphs have different notions of connectivity.

**Strongly Connected Graph:**

A directed graph is strongly connected if every vertex is reachable from every other vertex following edge directions.

**Weakly Connected Graph:**

A directed graph is weakly connected if replacing its directed edges with undirected edges makes it connected.

### Strongly Connected Components (SCCs)

A Strongly Connected Component is a maximal subset of vertices in which every vertex is reachable from every other vertex.

Kosaraju's algorithm finds SCCs using two DFS passes:

1. Perform DFS on the original graph and record vertices in finishing-time order.
2. Reverse every edge to construct the transpose graph.
3. Process vertices in decreasing order of finishing time, performing DFS on the transpose graph.
4. Each DFS identifies one SCC.

**Complexity:**

\[
O(V+E)
\]

---

# 4. Testing Bipartiteness

A graph is **bipartite** if its vertices can be divided into two disjoint sets such that no edge connects two vertices belonging to the same set.

Let the two sets be:

\[
V=V_1\cup V_2
\]

Where:

\[
V_1\cap V_2=\emptyset
\]

Every edge must connect a vertex in \(V_1\) to one in \(V_2\).

### Important Theorem

An undirected graph is bipartite if and only if it contains no odd-length cycle.

Examples:

- A tree is always bipartite.
- A graph containing a triangle is not bipartite.
- A graph containing an even-length cycle can be bipartite.

### BFS-Based Bipartiteness Test

The algorithm assigns one of two colours to each vertex.

Adjacent vertices must always have different colours.

```text
IS-BIPARTITE(G)
    initialize color[v] = UNCOLORED for all vertices

    for each vertex s in V
        if color[s] == UNCOLORED
            color[s] = 0
            enqueue(Q, s)

            while Q is not empty
                u = dequeue(Q)

                for each neighbour v of u
                    if color[v] == UNCOLORED
                        color[v] = 1 - color[u]
                        enqueue(Q, v)

                    else if color[v] == color[u]
                        return FALSE

    return TRUE
```

### Complexity Analysis

- Time Complexity: \(O(V+E)\)
- Space Complexity: \(O(V)\)

### Key Observations

- BFS or DFS can be used for bipartiteness testing.
- Disconnected graphs require checking every component.
- A self-loop immediately makes a graph non-bipartite.
- Any odd-length cycle makes a graph non-bipartite.

---

# 5. Directed Acyclic Graphs and Topological Ordering

## 5.1 Directed Acyclic Graph (DAG)

A Directed Acyclic Graph is a directed graph that contains no directed cycles.

DAGs are particularly useful for representing dependencies and sequential tasks.

### Applications

- Course prerequisite scheduling.
- Build systems and task dependencies.
- Project scheduling.
- Dependency resolution.
- Ordering of computational operations.

## 5.2 Topological Ordering

A topological ordering of a DAG is a linear ordering of its vertices such that for every directed edge:

\[
u\rightarrow v
\]

Vertex \(u\) appears before vertex \(v\).

**Important:** A directed graph has a topological ordering if and only if it is acyclic.

A DAG may have multiple valid topological orderings.

### Method 1: DFS-Based Topological Sorting

The algorithm uses DFS finishing times.

```text
TOPOLOGICAL-SORT(G)
    create an empty stack S

    for each vertex u in V
        if u is not visited
            DFS-TOPOLOGICAL(u)

    return S

DFS-TOPOLOGICAL(u)
    mark u as visited

    for each neighbour v of u
        if v is not visited
            DFS-TOPOLOGICAL(v)

    push u onto S
```

Vertices are pushed after all their outgoing neighbours have been explored.

The resulting stack order is a topological ordering.

To detect cycles during DFS, maintain three states:

- WHITE: Unvisited.
- GRAY: Currently being explored.
- BLACK: Fully processed.

An edge to a GRAY vertex indicates a directed cycle.

### Method 2: Kahn's Algorithm

Kahn's algorithm uses the indegree of each vertex.

Indegree is the number of incoming edges to a vertex.

```text
KAHN-TOPOLOGICAL-SORT(G)
    calculate indegree of every vertex

    enqueue all vertices with indegree 0
    result = empty list

    while Q is not empty
        u = dequeue(Q)
        add u to result

        for each neighbour v of u
            indegree[v] = indegree[v] - 1

            if indegree[v] == 0
                enqueue(Q, v)

    if size(result) != V
        report cycle

    return result
```

### Complexity Analysis

| Approach | Time Complexity | Space Complexity |
|---|---|---|
| DFS-Based | O(V + E) | O(V) |
| Kahn's Algorithm | O(V + E) | O(V) |

---

# 6. Introduction to the Greedy Algorithm Design Approach

A **Greedy Algorithm** is an algorithm design technique that constructs a solution by repeatedly making locally optimal choices.

At each step, the algorithm selects the best available option according to a particular criterion, with the goal of obtaining a globally optimal solution.

### General Greedy Structure

```text
GREEDY-ALGORITHM(problem)
    solution = empty

    while solution is not complete
        select the best available candidate

        if candidate is feasible
            add candidate to solution

    return solution
```

### Characteristics of Greedy Algorithms

1. Makes locally optimal decisions.
2. Builds the solution incrementally.
3. Usually does not reconsider previous decisions.
4. Often offers efficient implementations.
5. Does not guarantee optimal solutions for every optimization problem.

## 6.1 Greedy Choice Property

A problem satisfies the greedy choice property if a globally optimal solution can be constructed by making a locally optimal choice at each step.

## 6.2 Optimal Substructure

A problem has optimal substructure if an optimal solution contains optimal solutions to its subproblems.

These two properties are important when establishing that a greedy algorithm is correct.

### Greedy vs Dynamic Programming

| Feature | Greedy | Dynamic Programming |
|---|---|---|
| Decision | Local optimum | Compares subproblem solutions |
| Previous Decisions | Usually irreversible | Uses stored results |
| Subproblems | May not explore alternatives | Systematically solves overlapping subproblems |
| Efficiency | Often simpler and faster | May require more memory |
| Optimality | Requires proof | Depends on recurrence and state formulation |

### Correctness Techniques for Greedy Algorithms

**1. Exchange Argument**

Show that an optimal solution can be transformed into one containing the greedy choice without making the solution worse.

**2. Stays-Ahead Argument**

Show that after every step, the greedy solution is at least as good as any competing solution according to a suitable measure.

**3. Cut Property**

Used in Minimum Spanning Tree algorithms to prove that selecting a minimum-weight edge crossing a suitable cut is safe.

**Important:** A locally optimal choice is not automatically globally optimal. Greedy algorithms require a correctness proof.

---

# 7. Minimum Spanning Trees

A **Spanning Tree** of a connected, undirected graph is a subgraph that:

- Contains every vertex.
- Is connected.
- Contains no cycles.

For a graph with \(V\) vertices, every spanning tree contains exactly:

\[
V-1 \text{ edges}
\]

## Minimum Spanning Tree (MST)

A Minimum Spanning Tree is a spanning tree having the minimum possible sum of edge weights.

The total weight is:

\[
W(T)=\sum_{e\in T}w(e)
\]

### Important Properties

- An MST contains exactly \(V-1\) edges.
- It does not contain cycles.
- It connects all vertices with minimum total edge weight.
- A connected graph can have multiple MSTs.
- If all edge weights are distinct, the MST is unique.

Two major algorithms are used to find MSTs:

1. Kruskal's Algorithm.
2. Prim's Algorithm.

## 7.1 Kruskal's Algorithm

Kruskal's algorithm constructs an MST by repeatedly selecting the minimum-weight edge that does not form a cycle.

It uses the **Disjoint Set Union (DSU)** or Union-Find data structure.

### DSU Operations

- **MAKE-SET(x):** Creates a separate set containing \(x\).
- **FIND(x):** Finds the representative of the set containing \(x\).
- **UNION(x,y):** Merges the sets containing \(x\) and \(y\).

Path compression and union by rank/size make DSU operations extremely efficient.

### Algorithm

```text
KRUSKAL(G)
    MST = empty set

    sort all edges in non-decreasing order of weight

    for each vertex v
        MAKE-SET(v)

    for each edge (u, v) in sorted order
        if FIND(u) != FIND(v)
            add (u, v) to MST
            UNION(u, v)

    return MST
```

### Complexity Analysis

Sorting the edges dominates the running time:

\[
O(E\log E)
\]

DSU operations contribute an almost-linear additional cost:

\[
O(E\alpha(V))
\]

Therefore:

\[
\boxed{O(E\log E)}
\]

Where \(\alpha(V)\) is the inverse Ackermann function, which grows extremely slowly.

**Properties:**
- Edge-based greedy algorithm.
- Uses Union-Find to detect cycles.
- Works particularly well for sparse graphs.
- For disconnected graphs, it produces a minimum spanning forest rather than a spanning tree.

## 7.2 Prim's Algorithm

Prim's algorithm constructs an MST by starting from an arbitrary vertex and repeatedly adding the minimum-weight edge connecting the current tree to a vertex outside it.

### Algorithm

```text
PRIM(G, source)
    key[v] = INFINITY for every vertex
    parent[v] = NIL for every vertex

    key[source] = 0
    insert all vertices into a min-priority queue

    while priority queue is not empty
        u = EXTRACT-MIN()

        for each neighbour v of u
            if v is still in queue and weight(u,v) < key[v]
                parent[v] = u
                key[v] = weight(u,v)
                DECREASE-KEY(v, key[v])

    return parent
```

### Complexity Analysis

| Implementation | Time Complexity |
|---|---|
| Adjacency Matrix | O(V²) |
| Adjacency List + Binary Heap | O((V + E) log V) |
| Adjacency List + Fibonacci Heap | O(E + V log V) |

**Properties:**
- Vertex-based greedy algorithm.
- Maintains one growing MST.
- Uses a minimum-priority queue in efficient implementations.
- Particularly useful for dense graphs with matrix implementation.

### Kruskal vs Prim

| Feature | Kruskal | Prim |
|---|---|---|
| Approach | Selects minimum edges globally | Grows one tree |
| Data Structure | DSU | Priority Queue |
| Main Operation | Union-Find | Extract-Min / Decrease-Key |
| Complexity | O(E log E) | O((V+E) log V) with binary heap |
| Suitable For | Sparse graphs | Often effective for dense graphs |

### Important MST Properties

**Cut Property:**

For a cut of a connected weighted graph, a minimum-weight edge crossing that cut is safe to include in some MST.

**Cycle Property:**

If an edge is the unique maximum-weight edge in a cycle, it cannot belong to any MST.

---

# 8. Shortest Path Problems

A Shortest Path Problem asks us to find a path between two vertices such that the sum of edge weights along the path is minimized.

For a path \(P\):

\[
w(P)=\sum_{e\in P}w(e)
\]

### Types of Shortest Path Problems

1. Single-Source Shortest Path: Shortest paths from one source to all other vertices.
2. Single-Pair Shortest Path: Shortest path between two specified vertices.
3. All-Pairs Shortest Path: Shortest paths between every pair of vertices.

Different algorithms are suitable for different graph conditions.

## 8.1 BFS for Unweighted Graphs

For an unweighted graph, BFS finds the shortest path in terms of the number of edges.

**Complexity:**

- Time: \(O(V+E)\)
- Space: \(O(V)\)

## 8.2 Dijkstra's Algorithm

Dijkstra's algorithm finds shortest paths from a single source to all other vertices in a graph with **non-negative edge weights**.

It uses a greedy approach and a minimum-priority queue.

### Relaxation

Relaxation is the process of checking whether a shorter path to a vertex can be found through another vertex.

For an edge \(u\rightarrow v\):

\[
\text{if }d[u]+w(u,v)<d[v]
\]

Update:

\[
d[v]=d[u]+w(u,v)
\]

### Algorithm

```text
DIJKSTRA(G, source)
    dist[v] = INFINITY for all vertices
    dist[source] = 0

    insert source into a min-priority queue

    while priority queue is not empty
        u = EXTRACT-MIN()

        for each edge (u, v) with weight w
            if dist[u] + w < dist[v]
                dist[v] = dist[u] + w
                parent[v] = u
                update priority queue

    return dist
```

### Complexity Analysis

| Implementation | Time Complexity |
|---|---|
| Array / Adjacency Matrix | O(V²) |
| Binary Heap + Adjacency List | O((V + E) log V) |
| Fibonacci Heap | O(E + V log V) |

**Properties:**
- Greedy algorithm.
- Requires non-negative edge weights.
- Does not work correctly in general when negative-weight edges are present.
- Can reconstruct shortest paths using parent pointers.

## 8.3 Bellman-Ford Algorithm

Bellman-Ford computes single-source shortest paths and supports negative edge weights.

It can also detect reachable negative-weight cycles.

### Main Idea

A shortest simple path contains at most \(V-1\) edges.

Therefore, repeatedly relaxing every edge \(V-1\) times is sufficient to find shortest distances when no relevant negative cycle exists.

### Algorithm

```text
BELLMAN-FORD(G, source)
    dist[v] = INFINITY for all vertices
    dist[source] = 0

    repeat V-1 times
        for each edge (u, v) with weight w
            if dist[u] != INFINITY
               and dist[u] + w < dist[v]
                dist[v] = dist[u] + w
                parent[v] = u

    for each edge (u, v) with weight w
        if dist[u] != INFINITY
           and dist[u] + w < dist[v]
            report reachable negative-weight cycle

    return dist
```

### Complexity Analysis

- Time: \(O(VE)\)
- Space: \(O(V)\), excluding graph storage.

**Properties:**
- Handles negative edge weights.
- Detects reachable negative-weight cycles.
- Slower than Dijkstra's algorithm in typical implementations.
- A negative cycle makes shortest-path distances undefined for vertices reachable from that cycle.

## 8.4 Shortest Paths in DAGs

A DAG permits efficient shortest-path computation even when some edge weights are negative.

### Approach

1. Find a topological ordering of the DAG.
2. Initialize the source distance to zero and all other distances to infinity.
3. Process vertices in topological order.
4. Relax all outgoing edges of each vertex.

### Complexity

\[
\boxed{O(V+E)}
\]

This is often more efficient than Bellman-Ford when the graph is acyclic.

### Algorithm Comparison

| Algorithm | Negative Edges | Negative Cycle Detection | Time Complexity |
|---|---|---|---|
| BFS | Not applicable to weighted edges | No | O(V+E) |
| Dijkstra | No | No | O((V+E) log V) |
| Bellman-Ford | Yes | Yes | O(VE) |
| DAG Shortest Path | Yes | Not required for a DAG | O(V+E) |

---

# 9. Interval Scheduling

The Interval Scheduling Problem involves selecting the maximum number of mutually compatible activities from a given set of intervals.

Each interval has:

- Start time \(s_i\)
- Finish time \(f_i\)

Two intervals are compatible if they do not overlap.

For intervals where one ends exactly when another begins, compatibility is usually defined as:

\[
f_i\leq s_j
\]

### Greedy Strategy: Earliest Finish Time

The optimal greedy strategy is to repeatedly select the compatible interval that finishes earliest.

### Algorithm

```text
INTERVAL-SCHEDULING(intervals)
    sort intervals by increasing finish time

    selected = empty list
    lastFinish = -INFINITY

    for each interval i
        if start[i] >= lastFinish
            add interval i to selected
            lastFinish = finish[i]

    return selected
```

### Example

Consider these intervals:

| Interval | Start | Finish |
|---|---:|---:|
| A | 1 | 4 |
| B | 3 | 5 |
| C | 0 | 6 |
| D | 5 | 7 |
| E | 8 | 9 |

Sorting by finish time and applying the greedy strategy selects:

\[
A\rightarrow D\rightarrow E
\]

The maximum number of compatible intervals is 3.

### Complexity Analysis

Sorting:

\[
O(n\log n)
\]

Selection:

\[
O(n)
\]

Total:

\[
\boxed{O(n\log n)}
\]

If the intervals are already sorted by finishing time:

\[
O(n)
\]

### Correctness: Exchange Argument

Consider an optimal solution whose first selected interval is not the earliest-finishing interval.

Replace its first interval with the earliest-finishing interval.

Since the greedy interval finishes no later than the original first interval, all subsequent compatible intervals remain feasible.

Thus, there exists an optimal solution containing the greedy choice.

Repeating the argument establishes optimality.

**Important:** Sorting by earliest starting time or shortest interval length is not generally optimal for this problem.

---

# 10. Fractional Knapsack Problem

The Fractional Knapsack Problem involves selecting items with different values and weights to maximize total value without exceeding a given capacity.

Unlike the 0/1 Knapsack Problem, items can be divided into fractions.

### Given

For each item \(i\):

- Value: \(v_i\)
- Weight: \(w_i\)
- Knapsack capacity: \(W\)

The objective is:

\[
\max\sum_{i=1}^{n}v_ix_i
\]

Subject to:

\[
\sum_{i=1}^{n}w_ix_i\leq W
\]

Where:

\[
0\leq x_i\leq 1
\]

### Greedy Strategy

Select items in decreasing order of their value-to-weight ratio.

\[
r_i=\frac{v_i}{w_i}
\]

The item with the highest value per unit weight is selected first.

### Algorithm

```text
FRACTIONAL-KNAPSACK(items, W)
    sort items by decreasing value/weight ratio

    totalValue = 0

    for each item i
        if weight[i] <= W
            take the entire item
            W = W - weight[i]
            totalValue = totalValue + value[i]

        else
            fraction = W / weight[i]
            totalValue = totalValue + fraction * value[i]
            break

    return totalValue
```

### Example

Suppose the knapsack capacity is 50 units.

| Item | Value | Weight | Value/Weight |
|---|---:|---:|---:|
| A | 60 | 10 | 6 |
| B | 100 | 20 | 5 |
| C | 120 | 30 | 4 |

Selection:

- Take all of A: Weight = 10, Value = 60.
- Take all of B: Weight = 20, Value = 100.
- Remaining capacity = 20.
- Take \(20/30\) of C: Value = 80.

Total value:

\[
60+100+80=\boxed{240}
\]

### Complexity Analysis

Sorting:

\[
O(n\log n)
\]

Selecting items:

\[
O(n)
\]

Total:

\[
\boxed{O(n\log n)}
\]

### Fractional vs 0/1 Knapsack

| Feature | Fractional Knapsack | 0/1 Knapsack |
|---|---|---|
| Items Divisible? | Yes | No |
| Greedy by Value/Weight | Optimal | Not generally optimal |
| Common Approach | Greedy | Dynamic Programming |
| Typical DP Complexity | Not required | O(nW) |
| Nature | Continuous choices | Discrete choices |

**Important:** The value-to-weight greedy strategy is optimal for Fractional Knapsack, but it does not always produce an optimal solution for 0/1 Knapsack.

---

# 11. Analysis of Time Complexity

Time complexity measures how an algorithm's running time grows with input size.

The main purpose is to understand the scalability of an algorithm.

## 11.1 Graph Algorithm Complexity

For adjacency-list representations:

| Algorithm | Time Complexity |
|---|---|
| BFS | O(V + E) |
| DFS | O(V + E) |
| Connected Components | O(V + E) |
| Bipartiteness Testing | O(V + E) |
| Topological Sorting | O(V + E) |
| Kosaraju's SCC Algorithm | O(V + E) |
| Kruskal's MST | O(E log E) |
| Prim's MST (Binary Heap) | O((V + E) log V) |
| Dijkstra (Binary Heap) | O((V + E) log V) |
| Bellman-Ford | O(VE) |
| DAG Shortest Path | O(V + E) |

## 11.2 Greedy Algorithm Complexity

| Problem | Main Operation | Time Complexity |
|---|---|---|
| Interval Scheduling | Sorting by finish time | O(n log n) |
| Fractional Knapsack | Sorting by value/weight ratio | O(n log n) |
| Kruskal's MST | Sorting edges | O(E log E) |
| Prim's MST | Priority queue operations | O((V + E) log V) |
| Dijkstra's Algorithm | Priority queue operations | O((V + E) log V) |

## 11.3 Important Complexity Analysis Rules

**1. Sequential Operations**

For two sequential operations:

\[
T(n)=O(f(n))+O(g(n))
\]

The dominant term determines the asymptotic complexity.

**2. Nested Loops**

If two loops each execute \(n\) times:

\[
T(n)=O(n^2)
\]

**3. Sorting-Based Algorithms**

When an algorithm sorts its input before processing:

\[
T(n)=O(n\log n)+O(n)
\]

Therefore:

\[
T(n)=O(n\log n)
\]

**4. Graph Traversal**

With adjacency lists, every vertex is processed once and every edge is examined a constant number of times.

\[
T(V,E)=O(V+E)
\]

**5. Priority Queue Operations**

For a binary heap:

- Insert: \(O(\log n)\)
- Extract-Min: \(O(\log n)\)
- Decrease-Key: \(O(\log n)\)
- Peek-Min: \(O(1)\)

---

# 12. Algorithm Complexity Cheat Sheet

## Graph Traversal and Connectivity

| Algorithm | Time | Auxiliary Space |
|---|---|---|
| BFS | O(V + E) | O(V) |
| DFS | O(V + E) | O(V) |
| Connected Components | O(V + E) | O(V) |
| Bipartiteness Test | O(V + E) | O(V) |
| Topological Sort | O(V + E) | O(V) |
| Kosaraju's Algorithm | O(V + E) | O(V) |

## Minimum Spanning Tree

| Algorithm | Time Complexity | Main Data Structure |
|---|---|---|
| Kruskal | O(E log E) | Disjoint Set Union |
| Prim (Matrix) | O(V²) | Array / Matrix |
| Prim (Binary Heap) | O((V + E) log V) | Priority Queue |

## Shortest Path

| Algorithm | Time Complexity | Main Constraint |
|---|---|---|
| BFS | O(V + E) | Unweighted graph |
| Dijkstra | O((V + E) log V) | Non-negative weights |
| Bellman-Ford | O(VE) | Handles negative weights |
| DAG Shortest Path | O(V + E) | Directed acyclic graph |

## Greedy Optimization Problems

| Problem | Greedy Strategy | Time Complexity |
|---|---|---|
| Interval Scheduling | Earliest finishing time | O(n log n) |
| Fractional Knapsack | Highest value/weight ratio | O(n log n) |
| Kruskal's MST | Minimum safe edge | O(E log E) |
| Prim's MST | Minimum edge crossing the current tree cut | O((V + E) log V) |

---

## Key Takeaways

1. BFS explores graphs level by level using a queue.
2. DFS explores deeply using recursion or an explicit stack.
3. BFS and DFS both run in \(O(V+E)\) time with adjacency lists.
4. A connected component is a maximal connected subgraph.
5. An undirected graph is bipartite if and only if it has no odd-length cycle.
6. Every DAG has at least one topological ordering.
7. Greedy algorithms make locally optimal choices and require correctness proofs.
8. Kruskal's and Prim's algorithms solve the Minimum Spanning Tree problem.
9. Dijkstra's algorithm requires non-negative edge weights.
10. Bellman-Ford supports negative edges and detects reachable negative-weight cycles.
11. Shortest paths in a DAG can be found in linear time.
12. Interval Scheduling uses the earliest-finish-time strategy.
13. Fractional Knapsack uses the maximum value-to-weight ratio.
14. Greedy strategies are not universally optimal; Fractional and 0/1 Knapsack illustrate this distinction.
15. Always derive time complexity by examining the dominant operations and chosen data structures.

---

**End of Unit 2 — Graph Algorithms & Greedy Algorithms**

*These notes serve as a quick-reference guide for graph theory, traversal algorithms, greedy optimization, correctness arguments, and asymptotic complexity analysis.*

Two commonly studied schemes:

- **Lomuto Partition:** Typically uses the last element as pivot.
- **Hoare Partition:** Uses two pointers moving inward from opposite ends.

---

# 10. Randomized Quick Sort

Randomized Quick Sort improves Quick Sort by selecting the pivot randomly rather than deterministically.

### Working

1. Randomly select a pivot from the current subarray.
2. Exchange it with the chosen pivot position.
3. Partition the array.
4. Recursively sort the resulting partitions.

### Complexity Analysis

| Case | Time Complexity |
|---|---|
| Expected | O(n log n) |
| Worst | O(n²) |
| Expected Auxiliary Space | O(log n) |

### Key Observations

- Random pivot selection reduces dependence on the original input arrangement.
- Expected running time is \(O(n\log n)\).
- Worst-case running time remains \(O(n^2)\).
- Randomization provides expected performance, not a guaranteed worst-case bound.

---

# 11. Maximum Subarray Problem

The Maximum Subarray Problem asks us to find a contiguous subarray with the maximum possible sum.

Given an array:

$$
A=[-2,1,-3,4,-1,2,1,-5,4]
$$

The maximum-sum contiguous subarray is:

$$
[4,-1,2,1]
$$

Its sum is:

$$
4-1+2+1=6
$$

### Divide-and-Conquer Approach

The maximum subarray must belong to one of three categories:

1. Entirely in the left half.
2. Entirely in the right half.
3. Crossing the midpoint.

Therefore:

$$
MAXIMUM-SUBARRAY =
\max(L,R,C)
$$

Where:
- $\(L\)$ = Maximum subarray sum in the left half.
- $\(R\)$ = Maximum subarray sum in the right half.
- $\(C\)$ = Maximum crossing subarray sum.

### Recurrence Relation

$$
T(n)=2T(n/2)+O(n)
$$

Therefore:

$$
\boxed{T(n)=O(n\log n)}
$$

### Kadane's Algorithm

An alternative linear-time approach maintains the best subarray ending at the current position.

$$
currentMax_i=\max(A_i,currentMax_{i-1}+A_i)
$$

$$
globalMax_i=\max(globalMax_{i-1},currentMax_i)
$$

**Complexity:**

| Approach | Time Complexity |
|---|---|
| Brute Force | O(n²) or O(n³), depending on implementation |
| Divide and Conquer | O(n log n) |
| Kadane's Algorithm | O(n) |

**Important:** Kadane's algorithm also handles arrays containing entirely negative values when initialized correctly.

---

# 12. Strassen's Matrix Multiplication

Strassen's Algorithm is a divide-and-conquer algorithm that multiplies two matrices using seven recursive multiplications instead of the conventional eight.

### Conventional Matrix Multiplication

For two $$\(n \times n\)$$ matrices:

$$
T(n)=8T(n/2)+O(n^2)
$$

Therefore:

$$
T(n)=O(n^3)
$$

### Strassen's Approach

Divide matrices \(A\) and \(B\) into four submatrices:

$$
A=
\begin{bmatrix}
A_{11}&A_{12}\\
A_{21}&A_{22}
\end{bmatrix}
$$

$$
B=
\begin{bmatrix}
B_{11}&B_{12}\\
B_{21}&B_{22}
\end{bmatrix}
$$

Compute seven products:

$$
M_1=(A_{11}+A_{22})(B_{11}+B_{22})
$$

$$
M_2=(A_{21}+A_{22})B_{11}
$$

$$
M_3=A_{11}(B_{12}-B_{22})
$$

$$
M_4=A_{22}(B_{21}-B_{11})
$$

$$
M_5=(A_{11}+A_{12})B_{22}
$$

$$
M_6=(A_{21}-A_{11})(B_{11}+B_{12})
$$

$$
M_7=(A_{12}-A_{22})(B_{21}+B_{22})
$$

### Construct the Result

$$
C_{11}=M_1+M_4-M_5+M_7
$$

$$
C_{12}=M_3+M_5
$$

$$
C_{21}=M_2+M_4
$$

$$
C_{22}=M_1-M_2+M_3+M_6
$$

### Complexity Analysis

The recurrence is:

\[
T(n)=7T(n/2)+O(n^2)
\]

Applying the Master Theorem:

\[
\boxed{T(n)=O(n^{\log_2 7})}
\]

\[
\boxed{T(n)\approx O(n^{2.8074})}
\]

**Properties:**
- Uses seven recursive multiplications.
- Asymptotically faster than conventional matrix multiplication.
- Requires additional additions and subtractions.
- Often beneficial for sufficiently large matrices.
- Practical performance depends on implementation and matrix size.

---

# 13. Algorithm Complexity Cheat Sheet

## Searching Algorithms

| Algorithm | Best | Average | Worst | Space |
|---|---|---|---|---|
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) iterative |

## Sorting Algorithms

| Algorithm | Best | Average | Worst | Stable? | In-Place? |
|---|---|---|---|---|---|
| Insertion Sort | O(n) | O(n²) | O(n²) | Yes | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | No | Yes |
| Bubble Sort | O(n) | O(n²) | O(n²) | Yes | Yes |
| Heapsort | O(n log n) | O(n log n) | O(n log n) | No | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | Yes | No (array version) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | No | Usually |
| Counting Sort | O(n+k) | O(n+k) | O(n+k) | Yes* | No |
| Radix Sort | O(d(n+k)) | O(d(n+k)) | O(d(n+k)) | Yes* | No |

*Stability of Counting Sort and Radix Sort depends on the implementation and the sorting procedure used at each digit.*

## Important Divide-and-Conquer Recurrences

| Algorithm | Recurrence | Complexity |
|---|---|---|
| Binary Search | T(n) = T(n/2) + O(1) | O(log n) |
| Merge Sort | T(n) = 2T(n/2) + O(n) | O(n log n) |
| Quick Sort (Balanced) | T(n) = 2T(n/2) + O(n) | O(n log n) |
| Quick Sort (Worst) | T(n) = T(n-1) + O(n) | O(n²) |
| Maximum Subarray | T(n) = 2T(n/2) + O(n) | O(n log n) |
| Strassen's Algorithm | T(n) = 7T(n/2) + O(n²) | O(n^2.807) |

---

## Key Takeaways

1. Always distinguish between best, average, and worst-case complexity.
2. Binary Search requires sorted data.
3. Insertion Sort is particularly efficient for small or nearly sorted arrays.
4. Selection Sort minimizes the number of swaps among elementary comparison sorts.
5. Heapsort guarantees \(O(n\log n)\) worst-case performance.
6. Linear-time sorting algorithms rely on assumptions about input keys or distributions.
7. Divide and Conquer follows the Divide → Conquer → Combine paradigm.
8. Merge Sort guarantees \(O(n\log n)\) time and is stable.
9. Quick Sort offers excellent expected performance but has an \(O(n^2)\) worst case.
10. Randomization improves expected Quick Sort performance.
11. Kadane's Algorithm solves the Maximum Subarray Problem in linear time.
12. Strassen's Algorithm reduces matrix multiplication from eight recursive multiplications to seven.

---

**End of Unit 1 — Design and Analysis of Algorithms**

*These notes serve as a quick-reference guide for algorithm design, implementation, correctness proofs, and asymptotic complexity analysis.*
