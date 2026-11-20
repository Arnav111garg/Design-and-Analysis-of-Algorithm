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

# Unit 3 — Dynamic Programming

> **Course:** Design and Analysis of Algorithms (DAA)  
> **Unit:** 03  
> **Topics:** Dynamic Programming, Weighted Interval Scheduling, Integer Knapsack, Subset Sum and Complexity Analysis.

---

## Table of Contents

1. [Introduction to Dynamic Programming](#1-introduction-to-dynamic-programming)
2. [Dynamic Programming Approaches](#2-dynamic-programming-approaches)
3. [Weighted Interval Scheduling](#3-weighted-interval-scheduling)
4. [Integer Knapsack Problem](#4-integer-knapsack-problem)
5. [Subset Sum Problem](#5-subset-sum-problem)
6. [Analysis of Time Complexity](#6-analysis-of-time-complexity)
7. [Dynamic Programming Complexity Cheat Sheet](#7-dynamic-programming-complexity-cheat-sheet)
8. [Key Takeaways](#8-key-takeaways)

---

# 1. Introduction to Dynamic Programming

**Dynamic Programming (DP)** is an algorithm design technique that solves complex problems by dividing them into smaller, overlapping subproblems and storing their solutions to avoid repeated computation.

Instead of solving the same subproblem multiple times, DP computes its solution once and reuses the result whenever required.

Dynamic Programming is particularly useful for optimization and decision problems.

### 1.1 Key Characteristics of Dynamic Programming

A problem is generally suitable for Dynamic Programming when it exhibits two important properties:

**1. Optimal Substructure**

A problem has optimal substructure if an optimal solution to the original problem can be constructed using optimal solutions to its subproblems.

For example, an optimal solution to a scheduling problem may be constructed using an optimal solution to a smaller set of compatible activities.

**2. Overlapping Subproblems**

A problem has overlapping subproblems when the same smaller problems are solved repeatedly during a recursive computation.

Dynamic Programming stores their solutions to avoid redundant work.

### 1.2 General Structure of Dynamic Programming

A DP solution generally involves four steps:

1. **Define the State:** Identify the information required to represent a subproblem.
2. **Formulate the Recurrence:** Establish a mathematical relationship between a problem and its smaller subproblems.
3. **Identify Base Cases:** Define the solutions to the smallest subproblems.
4. **Compute and Store Results:** Solve the subproblems and reuse their computed solutions.

### 1.3 Dynamic Programming vs Divide and Conquer

| Feature | Divide and Conquer | Dynamic Programming |
|---|---|---|
| Subproblems | Usually independent | Often overlapping |
| Computation | May recompute repeated subproblems | Stores computed results |
| Storage | Usually recursion stack and temporary results | Memoization or DP table |
| Approach | Divide, Conquer, Combine | Define, Compute, Reuse |
| Examples | Merge Sort, Quick Sort | Knapsack, Weighted Scheduling |

### 1.4 Dynamic Programming vs Greedy Algorithms

| Feature | Dynamic Programming | Greedy Algorithm |
|---|---|---|
| Decision Making | Considers relevant subproblem alternatives | Makes a locally optimal choice |
| Previous Decisions | Evaluates alternatives through states | Usually does not reconsider choices |
| Optimality | Established through the DP recurrence | Requires a greedy-choice proof |
| Computation | Can involve many subproblems | Often involves fewer decisions |
| Examples | 0/1 Knapsack, Subset Sum | Fractional Knapsack, Interval Scheduling |

**Important:** Dynamic Programming does not automatically guarantee an optimal solution. The state definition and recurrence must correctly represent the original problem.

---

# 2. Dynamic Programming Approaches

There are two major approaches to implementing Dynamic Programming.

## 2.1 Top-Down Approach (Memoization)

Memoization uses recursion along with a storage structure to remember previously computed results.

When a subproblem is encountered:

- If its result has already been calculated, return the stored result.
- Otherwise, solve it recursively, store the result, and return it.

### General Pseudocode

```text
MEMOIZED-DP(problem)
    if problem is a base case
        return base result

    if problem is already stored
        return stored result

    result = solve smaller subproblems

    store result

    return result
```

**Characteristics:**

- Recursive implementation.
- Computes only the subproblems that are actually needed.
- Uses additional memory for memoization.
- Has recursion-stack overhead.

## 2.2 Bottom-Up Approach (Tabulation)

Tabulation solves subproblems iteratively, starting from the smallest cases and progressively building solutions to larger problems.

### General Pseudocode

```text
BOTTOM-UP-DP(problem)
    initialize DP table

    solve base cases

    for each state in dependency order
        compute current state using previously solved states

    return final answer
```

**Characteristics:**

- Usually iterative.
- Avoids recursive function-call overhead.
- Computes states in a predetermined order.
- Often allows space optimization.

### Memoization vs Tabulation

| Feature | Memoization | Tabulation |
|---|---|---|
| Approach | Top-Down | Bottom-Up |
| Implementation | Recursive | Iterative |
| Storage | Cache / Map / Array | DP Table |
| Computes | Only required states | All states in the chosen table |
| Recursion Stack | Required | Not required |
| Space Optimization | Possible | Often easier |

---

# 3. Weighted Interval Scheduling

The **Weighted Interval Scheduling Problem** is an optimization problem in which we are given a collection of intervals, each having a start time, finish time, and associated weight or profit.

The objective is to select a subset of mutually compatible intervals that maximizes the total weight.

Unlike ordinary Interval Scheduling, where the objective is to maximize the number of selected intervals, Weighted Interval Scheduling maximizes the total profit.

## 3.1 Problem Definition

Consider $n$ jobs, each represented by:

$$
J_i=(s_i,f_i,v_i)
$$

Where:

- $s_i$ = Starting time of job $i$.
- $f_i$ = Finishing time of job $i$.
- $v_i$ = Weight or profit associated with job $i$.

Two intervals $i$ and $j$ are compatible when:

$$
f_i\leq s_j
$$

The objective is:

$$
\max \sum_{i\in S}v_i
$$

Subject to all selected intervals being pairwise compatible.

## 3.2 Why Greedy Algorithms Are Not Sufficient

In ordinary Interval Scheduling, selecting the earliest-finishing interval is optimal when the objective is to maximize the number of intervals.

However, in Weighted Interval Scheduling, selecting the earliest-finishing or highest-weight interval does not necessarily produce an optimal solution.

Consider:

| Job | Start | Finish | Weight |
|---|---:|---:|---:|
| A | 1 | 3 | 5 |
| B | 3 | 5 | 5 |
| C | 1 | 5 | 15 |

Selecting A and B gives:

$$
5+5=10
$$

Selecting C gives:

$$
15
$$

Therefore, selecting the combination of compatible jobs with the maximum total weight requires considering alternative solutions.

Dynamic Programming provides an efficient solution.

## 3.3 Predecessor Function

First, sort all jobs in non-decreasing order of finishing time.

Define:

$$
p(j)=\max\{i<j:f_i\leq s_j\}
$$

Here, $p(j)$ represents the index of the last job that finishes before job $j$ starts.

If no compatible earlier job exists:

$$
p(j)=0
$$

This function allows us to identify the optimal subproblem associated with selecting job $j$.

## 3.4 Recurrence Relation

Let:

$$
OPT(j)
$$

represent the maximum total weight obtainable using the first $j$ jobs.

There are two possibilities:

**Case 1: Include Job $j$**

If job $j$ is included, the remaining jobs must come from the first $p(j)$ compatible jobs.

The resulting value is:

$$
v_j+OPT(p(j))
$$

**Case 2: Exclude Job $j$**

If job $j$ is excluded, the optimal solution is obtained from the first $j-1$ jobs:

$$
OPT(j-1)
$$

Therefore, the recurrence is:

$$
\boxed{
OPT(j)=\max\left(v_j+OPT(p(j)),OPT(j-1)\right)
}
$$

### Base Case

$$
OPT(0)=0
$$

## 3.5 Bottom-Up Dynamic Programming Algorithm

```text
WEIGHTED-INTERVAL-SCHEDULING(jobs)
    sort jobs by increasing finish time

    calculate p(j) for every job using binary search

    OPT[0] = 0

    for j = 1 to n
        include = weight[j] + OPT[p(j)]
        exclude = OPT[j-1]

        OPT[j] = max(include, exclude)

    return OPT[n]
```

## 3.6 Example

Consider the following jobs:

| Job | Start | Finish | Weight |
|---|---:|---:|---:|
| A | 1 | 3 | 5 |
| B | 2 | 5 | 6 |
| C | 4 | 6 | 5 |
| D | 6 | 7 | 4 |
| E | 5 | 8 | 11 |

Assuming jobs are already sorted by finishing time:

| Job | $p(j)$ | Weight |
|---|---:|---:|
| A | 0 | 5 |
| B | 0 | 6 |
| C | 1 | 5 |
| D | 3 | 4 |
| E | 2 | 11 |

The DP values are:

| $j$ | Job | Include Value | Exclude Value | $OPT(j)$ |
|---:|---|---:|---:|---:|
| 0 | — | — | — | 0 |
| 1 | A | 5 | 0 | 5 |
| 2 | B | 6 | 5 | 6 |
| 3 | C | 10 | 6 | 10 |
| 4 | D | 14 | 10 | 14 |
| 5 | E | 17 | 14 | 17 |

Therefore:

$$
\boxed{OPT(5)=17}
$$

The optimal selection is:

$$
A\rightarrow C\rightarrow E
$$

Total weight:

$$
5+5+11=\boxed{21}
$$

**Note:** The DP table's final value is 17 only if the predecessor entries in the table are used as listed. For the given intervals, $A$, $C$, and $E$ are compatible because $C$ finishes at 6 while $E$ starts at 5, so they are NOT compatible. The actual optimal selection is $B$ and $E$, with total weight $17$. Thus the DP result is correct.

## 3.7 Reconstructing the Optimal Solution

To identify the selected jobs, backtrack through the DP table.

Starting from $j=n$:

- If $v_j+OPT(p(j))>OPT(j-1)$, include job $j$ and move to $p(j)$.
- Otherwise, exclude job $j$ and move to $j-1$.

Continue until $j=0$.

If both choices have equal values, either choice can be followed to obtain an optimal solution.

## 3.8 Correctness Argument

Consider an optimal solution for the first $j$ jobs.

There are two possibilities:

1. Job $j$ is included. In this case, the remaining selected jobs must belong to the first $p(j)$ jobs. Their maximum possible total weight is $OPT(p(j))$.
2. Job $j$ is excluded. In this case, the maximum possible total weight is $OPT(j-1)$.

These two cases cover every possible optimal solution.

Taking the maximum of the two possibilities therefore gives the optimal value.

Hence:

$$
OPT(j)=\max(v_j+OPT(p(j)),OPT(j-1))
$$

## 3.9 Complexity Analysis

Let $n$ be the number of intervals.

| Operation | Time Complexity |
|---|---|
| Sorting intervals | $O(n\log n)$ |
| Computing predecessors using binary search | $O(n\log n)$ |
| Filling DP table | $O(n)$ |
| Reconstructing solution | $O(n)$ |

Total Time Complexity:

$$
\boxed{O(n\log n)}
$$

Space Complexity:

$$
\boxed{O(n)}
$$

**Key Observations:**

- Weighted Interval Scheduling is a classic DP optimization problem.
- The predecessor function makes the recurrence efficient.
- Binary search is used to compute compatible predecessors.
- The algorithm finds the maximum total weight, not necessarily the maximum number of jobs.

---

# 4. Integer Knapsack Problem

The **Integer Knapsack Problem**, commonly called the **0/1 Knapsack Problem**, is an optimization problem in which we are given a collection of items, each having a value and weight.

The objective is to maximize the total value of selected items without exceeding the capacity of the knapsack.

Unlike Fractional Knapsack, an item cannot be divided. Each item must either be selected completely or excluded.

## 4.1 Problem Definition

Given $n$ items, each represented by:

$$
I_i=(w_i,v_i)
$$

Where:

- $w_i$ = Weight of item $i$.
- $v_i$ = Value of item $i$.
- $W$ = Maximum capacity of the knapsack.

Define:

$$
x_i\in\{0,1\}
$$

Where:

- $x_i=1$: Item $i$ is selected.
- $x_i=0$: Item $i$ is excluded.

The objective is:

$$
\max\sum_{i=1}^{n}v_ix_i
$$

Subject to:

$$
\sum_{i=1}^{n}w_ix_i\leq W
$$

## 4.2 Why Greedy Algorithms Fail

Selecting items according to the highest value-to-weight ratio is not always optimal for the 0/1 Knapsack Problem.

Consider:

| Item | Weight | Value | Value/Weight |
|---|---:|---:|---:|
| A | 10 | 60 | 6 |
| B | 20 | 100 | 5 |
| C | 30 | 120 | 4 |

Knapsack capacity:

$$
W=50
$$

A greedy approach based on value-to-weight ratio selects A and B:

$$
60+100=160
$$

However, selecting B and C gives:

$$
100+120=\boxed{220}
$$

Therefore, the greedy strategy does not guarantee an optimal solution.

Dynamic Programming considers both possibilities for every item.

## 4.3 Defining the DP State

Let:

$$
DP[i][w]
$$

represent the maximum value obtainable using the first $i$ items with a knapsack capacity of $w$.

The state contains two dimensions:

- $i$: Number of available items.
- $w$: Remaining capacity.

## 4.4 Recurrence Relation

For the $i$-th item, there are two possibilities.

**Case 1: Exclude the Item**

The maximum value remains:

$$
DP[i-1][w]
$$

**Case 2: Include the Item**

This is possible only when:

$$
w_i\leq w
$$

The resulting value is:

$$
v_i+DP[i-1][w-w_i]
$$

Therefore, the recurrence is:

$$
\boxed{
DP[i][w]=
\begin{cases}
DP[i-1][w], & w_i>w\\
\max(DP[i-1][w],v_i+DP[i-1][w-w_i]), & w_i\leq w
\end{cases}
}
$$

### Base Cases

When no items are available:

$$
DP[0][w]=0
$$

When the capacity is zero:

$$
DP[i][0]=0
$$

## 4.5 Bottom-Up Dynamic Programming Algorithm

```text
ZERO-ONE-KNAPSACK(weights, values, n, W)
    create DP[0...n][0...W]

    for w = 0 to W
        DP[0][w] = 0

    for i = 1 to n
        DP[i][0] = 0

        for w = 1 to W
            if weights[i] > w
                DP[i][w] = DP[i-1][w]

            else
                exclude = DP[i-1][w]
                include = values[i] + DP[i-1][w-weights[i]]

                DP[i][w] = max(include, exclude)

    return DP[n][W]
```

## 4.6 Example

Consider the following items:

| Item | Weight | Value |
|---|---:|---:|
| 1 | 2 | 3 |
| 2 | 3 | 4 |
| 3 | 4 | 5 |
| 4 | 5 | 6 |

Knapsack capacity:

$$
W=5
$$

The DP table is:

| Items Considered | Capacity 0 | Capacity 1 | Capacity 2 | Capacity 3 | Capacity 4 | Capacity 5 |
|---|---:|---:|---:|---:|---:|---:|
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 3 | 3 | 3 | 3 |
| 2 | 0 | 0 | 3 | 4 | 4 | 7 |
| 3 | 0 | 0 | 3 | 4 | 5 | 7 |
| 4 | 0 | 0 | 3 | 4 | 5 | 7 |

Therefore:

$$
\boxed{DP[4][5]=7}
$$

The optimal selection is:

- Item 1: Weight 2, Value 3.
- Item 2: Weight 3, Value 4.

Total weight:

$$
2+3=5
$$

Maximum value:

$$
3+4=\boxed{7}
$$

## 4.7 Space Optimization

The standard DP implementation requires a two-dimensional table of size:

$$
O(nW)
$$

However, the recurrence for a particular item depends only on the previous row.

Therefore, we can optimize the algorithm to use a one-dimensional array.

### Space-Optimized Algorithm

```text
ZERO-ONE-KNAPSACK-OPTIMIZED(weights, values, n, W)
    initialize DP[0...W] = 0

    for i = 1 to n
        for w = W down to weights[i]
            DP[w] = max(
                DP[w],
                values[i] + DP[w-weights[i]]
            )

    return DP[W]
```

**Important:** The capacity loop must run in descending order.

Descending iteration ensures that an item is used at most once.

If the capacity loop runs in ascending order, the same item may contribute multiple times, effectively changing the problem into an Unbounded Knapsack variant.

## 4.8 Correctness Argument

For every item, an optimal solution either includes it or excludes it.

If the item is excluded, the optimal value is obtained from the previous items with the same capacity.

If the item is included, the remaining capacity is reduced by its weight, and the remaining items must form an optimal solution for that reduced capacity.

The recurrence considers both possibilities and selects the larger value.

By induction over the number of considered items, the DP table stores the optimal value for every state.

Therefore, $DP[n][W]$ gives the maximum achievable value.

## 4.9 Complexity Analysis

For the two-dimensional implementation:

| Resource | Complexity |
|---|---|
| Time | $O(nW)$ |
| Space | $O(nW)$ |

For the space-optimized implementation:

| Resource | Complexity |
|---|---|
| Time | $O(nW)$ |
| Space | $O(W)$ |

**Important:** The time complexity $O(nW)$ is pseudo-polynomial, not polynomial in the input size.

The reason is that $W$ is a numerical input and the number of bits required to represent it is only $O(\log W)$.

---

# 5. Subset Sum Problem

The **Subset Sum Problem** is a classic decision problem in which we are given a set of positive integers and a target sum.

The objective is to determine whether there exists a subset whose elements add up exactly to the target value.

Unlike the Knapsack Problem, the main objective is not to maximize value. It is to determine whether a particular sum is achievable.

## 5.1 Problem Definition

Given an array:

$$
A=\{a_1,a_2,\ldots,a_n\}
$$

And a target value:

$$
S
$$

Determine whether there exists a subset $X\subseteq A$ such that:

$$
\boxed{\sum_{a_i\in X}a_i=S}
$$

Each element can be selected at most once.

The output is either:

- TRUE: A subset with sum $S$ exists.
- FALSE: No such subset exists.

## 5.2 Dynamic Programming Approach

For each element, we have two possibilities:

1. Include the element in the subset.
2. Exclude the element from the subset.

Define the DP state:

$$
DP[i][s]
$$

Where $DP[i][s]$ is TRUE if a subset of the first $i$ elements can produce sum $s$.

Otherwise, it is FALSE.

## 5.3 Recurrence Relation

There are two possibilities.

**Case 1: Exclude the Current Element**

If a subset of the previous elements can already produce sum $s$:

$$
DP[i-1][s]=TRUE
$$

Then:

$$
DP[i][s]=TRUE
$$

**Case 2: Include the Current Element**

If:

$$
a_i\leq s
$$

And the previous elements can produce:

$$
s-a_i
$$

Then the current element can be included.

Therefore:

$$
DP[i-1][s-a_i]=TRUE
$$

Combining both cases:

$$
\boxed{
DP[i][s]=DP[i-1][s]\lor DP[i-1][s-a_i]
}
$$

The inclusion term is considered only when $a_i\leq s$.

### Base Cases

An empty subset can always produce a sum of zero:

$$
DP[i][0]=TRUE
$$

No positive target can be generated using zero elements:

$$
DP[0][s]=FALSE,\quad s>0
$$

## 5.4 Bottom-Up Algorithm

```text
SUBSET-SUM(A, n, S)
    create DP[0...n][0...S]

    for i = 0 to n
        DP[i][0] = TRUE

    for s = 1 to S
        DP[0][s] = FALSE

    for i = 1 to n
        for s = 1 to S
            DP[i][s] = DP[i-1][s]

            if A[i] <= s
                DP[i][s] = DP[i][s] OR DP[i-1][s-A[i]]

    return DP[n][S]
```

## 5.5 Example

Consider:

$$
A=\{3,4,5,2\}
$$

Target:

$$
S=9
$$

We need to determine whether a subset exists whose sum is exactly 9.

A possible subset is:

$$
\{4,5\}
$$

Since:

$$
4+5=9
$$

The answer is:

$$
\boxed{TRUE}
$$

### DP Table

The table shows the sums achievable using the first $i$ elements.

| Elements Considered | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|---|
| None | T | F | F | F | F | F | F | F | F | F |
| {3} | T | F | F | T | F | F | F | F | F | F |
| {3,4} | T | F | F | T | T | F | F | T | F | F |
| {3,4,5} | T | F | F | T | T | T | F | T | T | T |
| {3,4,5,2} | T | F | T | T | T | T | T | T | T | T |

Since:

$$
DP[4][9]=TRUE
$$

A subset with sum 9 exists.

## 5.6 Space Optimization

As in the 0/1 Knapsack Problem, the current row depends only on the previous row.

Therefore, a one-dimensional DP array can be used.

### Space-Optimized Algorithm

```text
SUBSET-SUM-OPTIMIZED(A, n, S)
    initialize DP[0...S] = FALSE
    DP[0] = TRUE

    for each element x in A
        for s = S down to x
            DP[s] = DP[s] OR DP[s-x]

    return DP[S]
```

**Important:** The inner loop must run in descending order.

This ensures that each element is used at most once.

## 5.7 Correctness Argument

Consider an arbitrary subset of the first $i$ elements that produces sum $s$.

There are two possibilities:

1. The subset does not contain element $a_i$. Then the first $i-1$ elements must already produce sum $s$.
2. The subset contains element $a_i$. Then the remaining elements must produce sum $s-a_i$.

The recurrence considers both possibilities.

Therefore, it correctly determines whether sum $s$ can be constructed using the first $i$ elements.

By induction over the number of considered elements, $DP[n][S]$ correctly determines whether a subset with sum $S$ exists.

## 5.8 Complexity Analysis

For the two-dimensional implementation:

| Resource | Complexity |
|---|---|
| Time | $O(nS)$ |
| Space | $O(nS)$ |

For the space-optimized implementation:

| Resource | Complexity |
|---|---|
| Time | $O(nS)$ |
| Space | $O(S)$ |

The algorithm is pseudo-polynomial because its complexity depends on the numerical value of the target sum $S$, rather than only on the number of bits required to represent $S$.

## 5.9 Relationship Between Knapsack and Subset Sum

The Subset Sum Problem can be viewed as a special type of 0/1 selection problem.

In Subset Sum, every element has:

- Weight equal to its value.
- A requirement to achieve an exact target sum.

For a target $S$, consider a 0/1 Knapsack instance where:

$$
w_i=v_i=a_i
$$

And:

$$
W=S
$$

The maximum achievable knapsack value equals $S$ if and only if a subset summing exactly to $S$ exists.

Thus, the Subset Sum Problem is closely related to the 0/1 Knapsack Problem.

---

# 6. Analysis of Time Complexity

Time complexity analysis measures how the computational requirements of an algorithm grow with input size.

In Dynamic Programming, complexity depends mainly on:

1. The number of distinct states.
2. The time required to compute each state.
3. The additional work required for preprocessing and reconstruction.

A useful general rule is:

$$
\boxed{
T(n)=\text{Number of States}\times
\text{Time per State}
}
$$

This is a general estimation principle; additional operations must also be considered.

## 6.1 Complexity of Weighted Interval Scheduling

For $n$ intervals:

**Sorting:**

$$
O(n\log n)
$$

**Predecessor Computation:**

Using binary search for each interval:

$$
O(n\log n)
$$

**DP Table Construction:**

Each of the $n$ states requires constant-time computation:

$$
O(n)
$$

Therefore:

$$
T(n)=O(n\log n+n\log n+n)
$$

Final Complexity:

$$
\boxed{O(n\log n)}
$$

Space Complexity:

$$
\boxed{O(n)}
$$

## 6.2 Complexity of Integer Knapsack

The DP table has dimensions:

$$
(n+1)\times(W+1)
$$

Number of states:

$$
O(nW)
$$

Each state requires constant time.

Therefore:

$$
\boxed{T(n,W)=O(nW)}
$$

Space Complexity:

$$
\boxed{O(nW)}
$$

After space optimization:

$$
\boxed{O(W)}
$$

## 6.3 Complexity of Subset Sum

The DP table has dimensions:

$$
(n+1)\times(S+1)
$$

Number of states:

$$
O(nS)
$$

Each state requires constant-time Boolean operations.

Therefore:

$$
\boxed{T(n,S)=O(nS)}
$$

Space Complexity:

$$
\boxed{O(nS)}
$$

After space optimization:

$$
\boxed{O(S)}
$$

## 6.4 Polynomial vs Pseudo-Polynomial Time

An important distinction in Dynamic Programming is the difference between polynomial and pseudo-polynomial time complexity.

**Polynomial Time:**

An algorithm has polynomial complexity if its running time is polynomial in the length of the input representation.

Examples:

$$
O(n),\quad O(n^2),\quad O(n^3)
$$

**Pseudo-Polynomial Time:**

An algorithm is pseudo-polynomial if its running time is polynomial in the numerical values of the input parameters rather than their representation lengths.

For example:

$$
O(nW)
$$

For Knapsack, where $W$ is the numerical capacity.

Since representing $W$ requires only approximately:

$$
O(\log W)
$$

bits, the algorithm's running time can be exponential in the number of bits used to represent $W$.

The same distinction applies to Subset Sum with complexity:

$$
O(nS)
$$

**Important:** Pseudo-polynomial algorithms are often practical when the numerical values of the input parameters are reasonably small.

---

# 7. Dynamic Programming Complexity Cheat Sheet

| Problem | DP State | Recurrence | Time Complexity | Space Complexity |
|---|---|---|---|---|
| Weighted Interval Scheduling | $OPT(j)$ | $\max(v_j+OPT(p(j)),OPT(j-1))$ | $O(n\log n)$ including sorting and predecessor calculation | $O(n)$ |
| 0/1 Knapsack | $DP[i][w]$ | $\max(DP[i-1][w],v_i+DP[i-1][w-w_i])$ when item fits | $O(nW)$ | $O(nW)$ |
| Optimized 0/1 Knapsack | $DP[w]$ | $\max(DP[w],v_i+DP[w-w_i])$ | $O(nW)$ | $O(W)$ |
| Subset Sum | $DP[i][s]$ | $DP[i-1][s]\lor DP[i-1][s-a_i]$ when element fits | $O(nS)$ | $O(nS)$ |
| Optimized Subset Sum | $DP[s]$ | $DP[s]\lor DP[s-a_i]$ | $O(nS)$ | $O(S)$ |

### Important DP Concepts

| Concept | Meaning |
|---|---|
| DP State | Represents a smaller subproblem |
| Recurrence Relation | Defines how states depend on one another |
| Base Case | Defines the smallest solvable subproblems |
| Memoization | Top-down storage of computed results |
| Tabulation | Bottom-up computation using a table |
| Optimal Substructure | Optimal solutions can be built from optimal subproblem solutions |
| Overlapping Subproblems | The same subproblems are encountered repeatedly |
| State Transition | Rule for moving from previous states to current states |
| Space Optimization | Reduces memory by storing only necessary previous states |
| Pseudo-Polynomial Time | Complexity depends on numerical input values |

---

# 8. Key Takeaways

1. Dynamic Programming solves problems by storing solutions to overlapping subproblems.
2. Optimal substructure and overlapping subproblems are the two major characteristics of DP.
3. Memoization is the top-down approach, while tabulation is the bottom-up approach.
4. A correct DP solution requires a well-defined state, recurrence, and base cases.
5. Weighted Interval Scheduling maximizes total interval weight using predecessor-based recurrence relations.
6. The predecessor function $p(j)$ identifies the last compatible interval before job $j$.
7. The 0/1 Knapsack Problem considers both inclusion and exclusion of every item.
8. The descending capacity loop is essential when optimizing 0/1 Knapsack into one dimension.
9. Subset Sum determines whether a subset can produce an exact target sum.
10. Subset Sum uses Boolean DP states instead of maximizing an objective value.
11. Weighted Interval Scheduling runs in $O(n\log n)$ time, including sorting and predecessor computation.
12. Integer Knapsack and Subset Sum have pseudo-polynomial time complexities of $O(nW)$ and $O(nS)$, respectively.
13. Space optimization can reduce memory usage without changing the asymptotic time complexity.
14. Always distinguish between polynomial and pseudo-polynomial complexity.

---

**End of Unit 3 — Dynamic Programming**

*These notes serve as a reference for Dynamic Programming fundamentals, optimization problems, recurrence formulation, correctness arguments, and complexity analysis.*


# Unit 4 — Hash Tables, Hash Functions & Collision Resolution

> **Course:** Design and Analysis of Algorithms (DAA)  
> **Unit:** 04  
> **Topics:** Hash Tables, Hash Functions, Collision Resolution Schemes and Complexity Analysis.

---

## Table of Contents

1. [Introduction to Hash Tables](#1-introduction-to-hash-tables)
2. [Hash Functions](#2-hash-functions)
3. [Properties of a Good Hash Function](#3-properties-of-a-good-hash-function)
4. [Collision in Hashing](#4-collision-in-hashing)
5. [Collision Resolution Schemes](#5-collision-resolution-schemes)
   - Separate Chaining
   - Open Addressing
   - Linear Probing
   - Quadratic Probing
   - Double Hashing
6. [Load Factor and Rehashing](#6-load-factor-and-rehashing)
7. [Analysis of Time and Space Complexity](#7-analysis-of-time-and-space-complexity)
8. [Comparison of Collision Resolution Techniques](#8-comparison-of-collision-resolution-techniques)
9. [Applications of Hash Tables](#9-applications-of-hash-tables)
10. [Key Takeaways](#10-key-takeaways)

---

# 1. Introduction to Hash Tables

A **Hash Table** is a data structure that stores key-value pairs and supports efficient insertion, searching, and deletion using a hash function.

Instead of searching through every element, a hash table calculates an index directly from a key and uses that index to access the corresponding location in an array.

This technique is called **Hashing**.

### 1.1 Basic Terminology

- **Key:** An identifier used to access a stored element.
- **Value:** The data associated with a key.
- **Hash Function:** A function that converts a key into an array index.
- **Hash Table:** An array-based data structure used to store key-value pairs.
- **Collision:** An event in which two different keys are mapped to the same index.
- **Bucket:** A location in the hash table that stores one or more elements.

### 1.2 Mathematical Representation

A hash function maps a key from a key space $U$ to an index in a hash table of size $m$.

$$
h: U \rightarrow \{0,1,2,\ldots,m-1\}
$$

Where:

- $U$ = Universe of possible keys.
- $m$ = Size of the hash table.
- $h(k)$ = Index generated for key $k$.

For example, consider a hash table of size:

$$
m=10
$$

And the hash function:

$$
h(k)=k\bmod 10
$$

For the key $42$:

$$
h(42)=42\bmod 10=2
$$

Therefore, key $42$ is stored at index $2$.

### 1.3 Basic Operations

| Operation | Description |
|---|---|
| Insert(key, value) | Stores a key-value pair. |
| Search(key) | Retrieves the value associated with a key. |
| Delete(key) | Removes a key-value pair. |
| Update(key, value) | Modifies the value associated with a key. |

### 1.4 Advantages of Hash Tables

- Average-case constant-time insertion, searching, and deletion under suitable assumptions.
- Efficient key-value storage and retrieval.
- No requirement for elements to be stored in sorted order.
- Particularly effective for large datasets when the hash function distributes keys well.

### 1.5 Limitations

- Collisions cannot generally be avoided.
- Performance depends on the quality of the hash function.
- Worst-case operations can take linear time.
- Hash tables do not naturally maintain sorted order.
- Additional memory may be required for collision resolution and resizing.

---

# 2. Hash Functions

A **Hash Function** is a mathematical function that transforms a key into an integer index corresponding to a location in a hash table.

For a table of size $m$:

$$
h(k)\in[0,m-1]
$$

The main objective of a hash function is to distribute keys uniformly across the available table positions.

## 2.1 Division Method

The division method calculates the remainder when a key is divided by the table size.

$$
\boxed{h(k)=k\bmod m}
$$

Where:

- $k$ = Input key.
- $m$ = Hash table size.

**Example:**

Let:

$$
k=1234,\quad m=11
$$

Then:

$$
h(1234)=1234\bmod 11
$$

$$
\boxed{h(1234)=2}
$$

**Important Observations:**

- Simple and computationally efficient.
- Choosing a prime table size is often a useful heuristic.
- The table size should avoid introducing undesirable patterns in the key distribution.
- The choice of $m$ can significantly influence collision frequency.

## 2.2 Multiplication Method

The multiplication method multiplies the key by a constant and uses the fractional part of the result to determine the index.

The hash function is:

$$
\boxed{
h(k)=\left\lfloor m\cdot\{kA\}\right\rfloor
}
$$

Where:

- $m$ = Table size.
- $A$ = Constant such that $0<A<1$.
- $\{kA\}$ = Fractional part of $kA$.
- $\lfloor x\rfloor$ = Greatest integer less than or equal to $x$.

The fractional part is defined as:

$$
\{x\}=x-\lfloor x\rfloor
$$

**Example:**

Suppose:

$$
k=1234,\quad m=16,\quad A\approx0.618
$$

Then:

$$
kA=1234(0.618)=762.612
$$

Fractional part:

$$
\{kA\}=0.612
$$

Therefore:

$$
h(k)=\lfloor16(0.612)\rfloor
$$

$$
\boxed{h(k)=9}
$$

## 2.3 Mid-Square Method

In the Mid-Square Method, the key is squared and selected middle digits or bits are extracted to determine the hash index.

### Procedure

1. Square the given key.
2. Extract the middle digits or bits.
3. Convert the extracted value into a valid table index, if necessary.

**Example:**

Suppose:

$$
k=44
$$

Squaring:

$$
44^2=1936
$$

Selecting the middle two digits:

$$
h(k)=93
$$

For a table of size $m=100$:

$$
h(k)=93\bmod100=93
$$

**Properties:**

- Uses information from different parts of the key.
- Can provide useful distribution for suitable key patterns.
- The choice of extracted digits or bits matters.

## 2.4 Folding Method

The Folding Method divides a key into smaller groups of digits or bits and combines those groups to generate a hash value.

### Procedure

1. Divide the key into equal-sized groups.
2. Add the groups together.
3. Apply modulo table size to obtain a valid index.

**Example:**

Consider:

$$
k=123456789
$$

Divide into groups:

$$
12,\quad34,\quad56,\quad78,\quad9
$$

Add the groups:

$$
12+34+56+78+9=189
$$

For a table size of $m=100$:

$$
h(k)=189\bmod100
$$

$$
\boxed{h(k)=89}
$$

## 2.5 Polynomial Hashing for Strings

String hashing converts a sequence of characters into a numerical hash value.

A common polynomial hashing formula is:

$$
\boxed{
h(s)=\left(\sum_{i=0}^{L-1}c_i p^i\right)\bmod m
}
$$

Where:

- $L$ = Length of the string.
- $c_i$ = Numerical representation of character $i$.
- $p$ = Chosen multiplier or base.
- $m$ = Modulus.

For example, character codes can be used to represent individual characters.

This method is commonly used in string-processing algorithms.

**Important:** The quality of a string hash depends on the chosen base, modulus, and input distribution. Modular arithmetic and appropriate integer types are important when implementing it.

---

# 3. Properties of a Good Hash Function

A good hash function should satisfy several desirable properties.

### 3.1 Deterministic

The same key must always produce the same hash value under the same hashing configuration.

$$
h(k)=h(k)
$$

### 3.2 Uniform Distribution

Keys should be distributed approximately uniformly throughout the hash table.

A uniform distribution reduces the probability of collisions and long search sequences.

### 3.3 Efficiency

The hash function should be computationally inexpensive.

A complicated hash function can increase the overall cost of insertion and searching.

### 3.4 Good Mixing

The hash function should use information from the entire key rather than relying excessively on a small portion of it.

### 3.5 Consistency with Equality

If two keys are considered equal, they must produce the same hash value.

$$
k_1=k_2\implies h(k_1)=h(k_2)
$$

However, the reverse is not necessarily true.

$$
h(k_1)=h(k_2)\centernot\implies k_1=k_2
$$

Different keys may produce the same hash value, resulting in a collision.

### 3.6 Universal Hashing

Universal Hashing uses a randomly selected hash function from a family of hash functions.

A family $H$ is universal if, for any two distinct keys $x$ and $y$:

$$
\Pr_{h\in H}[h(x)=h(y)]\leq\frac{1}{m}
$$

Where:

- $H$ = Family of hash functions.
- $m$ = Number of table positions.
- Probability is taken over the random selection of a hash function.

Universal hashing reduces the possibility that a fixed set of keys consistently produces excessive collisions.

---

# 4. Collision in Hashing

A **Collision** occurs when two or more distinct keys generate the same hash-table index.

Mathematically:

$$
k_1\neq k_2
$$

But:

$$
h(k_1)=h(k_2)
$$

### Example

Consider the hash function:

$$
h(k)=k\bmod 10
$$

For keys:

$$
k_1=25,\quad k_2=45,\quad k_3=65
$$

We get:

$$
h(25)=5
$$

$$
h(45)=5
$$

$$
h(65)=5
$$

All three keys map to index $5$.

Therefore, a collision occurs.

### Why Do Collisions Occur?

If the universe of possible keys is larger than the number of available table positions, multiple keys must map to the same index.

This follows from the Pigeonhole Principle.

If:

$$
|U|>m
$$

Then at least two distinct keys must have the same hash-table index.

### Collision Resolution

Collision resolution refers to the techniques used to store and retrieve elements when multiple keys map to the same hash-table position.

The two major approaches are:

1. Separate Chaining.
2. Open Addressing.

---

# 5. Collision Resolution Schemes

## 5.1 Separate Chaining

Separate Chaining resolves collisions by maintaining a collection of elements at each hash-table index.

Each table position points to a linked list or another suitable data structure containing all keys mapped to that index.

### Working

1. Calculate the hash index.
2. Access the corresponding bucket.
3. If the bucket is empty, insert the new element.
4. If the bucket already contains elements, add the new element to that bucket.

### Example

Consider:

$$
h(k)=k\bmod 10
$$

Insert:

$$
12,\quad22,\quad32,\quad15,\quad25
$$

The resulting hash table is:

| Index | Stored Elements |
|---|---|
| 0 | Empty |
| 1 | Empty |
| 2 | 12 → 22 → 32 |
| 3 | Empty |
| 4 | Empty |
| 5 | 15 → 25 |
| 6 | Empty |
| 7 | Empty |
| 8 | Empty |
| 9 | Empty |

All keys that produce the same index are stored in the same bucket.

### Pseudocode

**Insertion:**

```text
CHAINED-INSERT(T, key, value)
    index = h(key)

    for each element in T[index]
        if element.key == key
            update element.value
            return

    insert (key, value) at the head of T[index]
```

**Searching:**

```text
CHAINED-SEARCH(T, key)
    index = h(key)

    for each element in T[index]
        if element.key == key
            return element.value

    return NOT-FOUND
```

**Deletion:**

```text
CHAINED-DELETE(T, key)
    index = h(key)

    for each element in T[index]
        if element.key == key
            remove element
            return SUCCESS

    return NOT-FOUND
```

### Complexity Analysis

Let:

$$
\alpha=\frac{n}{m}
$$

Where:

- $n$ = Number of stored keys.
- $m$ = Number of buckets.
- $\alpha$ = Load factor.

Under the simple uniform hashing assumption, the expected bucket length is $\alpha$.

| Operation | Expected Time | Worst-Case Time |
|---|---|---|
| Insertion | O(1)* | O(n) |
| Searching | O(1 + α) | O(n) |
| Deletion | O(1 + α) | O(n) |

*Insertion at the head of a bucket is O(1) once the bucket is known, assuming duplicate-key checking is not required or has already been handled.*

**Properties:**

- Multiple elements can occupy the same bucket.
- Load factor can be greater than 1.
- Deletion is straightforward.
- Additional memory is required for bucket structures.
- Performance depends on the distribution of keys.

## 5.2 Open Addressing

Open Addressing resolves collisions by storing all elements directly inside the hash table.

When a collision occurs, the algorithm searches for another available position using a predefined probing sequence.

Unlike Separate Chaining, every key must occupy one of the available table positions.

The general probing function is:

$$
\boxed{h(k,i)}
$$

Where:

- $k$ = Key.
- $i$ = Probe number.
- $h(k,i)$ = Position examined during the $i$-th probe.

Open addressing requires:

$$
\alpha=\frac{n}{m}<1
$$

The table must always have at least one unused position for insertion to succeed.

The major open-addressing techniques are:

1. Linear Probing.
2. Quadratic Probing.
3. Double Hashing.

---

## 5.3 Linear Probing

Linear Probing resolves collisions by checking consecutive positions until an empty slot is found.

The probing function is:

$$
\boxed{
h(k,i)=(h'(k)+i)\bmod m
}
$$

Where:

- $h'(k)$ = Original hash function.
- $i=0,1,2,\ldots,m-1$ = Probe number.

### Working

1. Calculate the original hash index.
2. If the position is empty, insert the key.
3. If occupied, check the next position.
4. Continue until an empty position is found.

### Example

Consider:

$$
h'(k)=k\bmod 10
$$

Insert:

$$
23,\quad43,\quad13,\quad33
$$

All keys initially map to index $3$.

| Key | Initial Index | Final Position |
|---|---:|---:|
| 23 | 3 | 3 |
| 43 | 3 | 4 |
| 13 | 3 | 5 |
| 33 | 3 | 6 |

The resulting table:

| Index | Key |
|---|---|
| 0 | Empty |
| 1 | Empty |
| 2 | Empty |
| 3 | 23 |
| 4 | 43 |
| 5 | 13 |
| 6 | 33 |
| 7 | Empty |
| 8 | Empty |
| 9 | Empty |

### Primary Clustering

Linear Probing suffers from **Primary Clustering**.

Primary clustering occurs when consecutive occupied positions form long blocks, increasing the number of probes required for future insertions and searches.

### Advantages

- Simple implementation.
- Good cache locality.
- No additional linked-list storage.
- Efficient at low load factors.

### Disadvantages

- Suffers from primary clustering.
- Performance deteriorates as the table becomes full.
- Deletion requires special handling.

---

## 5.4 Quadratic Probing

Quadratic Probing resolves collisions by using a quadratic function to calculate the next position.

The general probing function is:

$$
\boxed{
h(k,i)=(h'(k)+c_1i+c_2i^2)\bmod m
}
$$

Where:

- $h'(k)$ = Original hash function.
- $c_1,c_2$ = Constants.
- $i$ = Probe number.

A common simplified form is:

$$
h(k,i)=(h'(k)+i^2)\bmod m
$$

### Working

1. Calculate the original hash index.
2. If occupied, probe using a quadratic offset.
3. Continue checking subsequent quadratic probe positions.
4. Stop when an available position is found.

### Example

Consider:

$$
h'(k)=k\bmod 11
$$

And:

$$
h(k,i)=(h'(k)+i^2)\bmod 11
$$

Insert keys:

$$
22,\quad33,\quad44
$$

All three keys initially map to index:

$$
h'(k)=0
$$

For the first key:

$$
h(22,0)=0
$$

For the second key, index 0 is occupied:

$$
h(33,1)=(0+1^2)\bmod11=1
$$

For the third key, indices 0 and 1 are occupied:

$$
h(44,1)=1
$$

$$
h(44,2)=(0+2^2)\bmod11=4
$$

Therefore, the final positions are:

| Key | Final Position |
|---|---:|
| 22 | 0 |
| 33 | 1 |
| 44 | 4 |

### Secondary Clustering

Quadratic Probing reduces primary clustering, but keys with the same initial hash position follow the same probing sequence.

This phenomenon is known as **Secondary Clustering**.

### Advantages

- Reduces primary clustering.
- Does not require additional linked-list storage.
- Often performs better than linear probing under moderate load factors.

### Disadvantages

- Can still suffer from secondary clustering.
- Certain table sizes and constants may prevent some slots from being reached.
- Requires careful selection of parameters to guarantee sufficient probe coverage.

---

## 5.5 Double Hashing

Double Hashing uses two different hash functions to determine the probing sequence.

The probing function is:

$$
\boxed{
h(k,i)=(h_1(k)+i\cdot h_2(k))\bmod m
}
$$

Where:

- $h_1(k)$ = Primary hash function.
- $h_2(k)$ = Secondary hash function.
- $i$ = Probe number.

The second hash function determines the step size between probes.

### Working

1. Calculate the initial position using $h_1(k)$.
2. If the position is occupied, calculate the step size using $h_2(k)$.
3. Use the second hash value to determine the next position.
4. Continue until an empty position is found.

### Example

Let:

$$
m=11
$$

Choose:

$$
h_1(k)=k\bmod11
$$

$$
h_2(k)=1+(k\bmod10)
$$

The probing function becomes:

$$
h(k,i)=(h_1(k)+i\cdot h_2(k))\bmod11
$$

For key:

$$
k=22
$$

Initial position:

$$
h_1(22)=0
$$

Step size:

$$
h_2(22)=1+2=3
$$

Probe sequence:

$$
0,\quad3,\quad6,\quad9,\ldots
$$

If index 0 is occupied, the algorithm checks index 3, then index 6, and so on.

### Important Condition

For a key's probe sequence to visit every table position, the step size and table size must be relatively prime.

$$
\boxed{\gcd(h_2(k),m)=1}
$$

Choosing a prime table size and a secondary hash function that produces values between $1$ and $m-1$ satisfies this condition.

### Advantages

- Reduces primary and secondary clustering.
- Provides more varied probe sequences.
- Often achieves better distribution than linear and quadratic probing.

### Disadvantages

- More computationally expensive than linear probing.
- Requires two well-designed hash functions.
- Proper selection of the secondary hash function is essential.

---

# 6. Load Factor and Rehashing

## 6.1 Load Factor

The **Load Factor** measures how full a hash table is.

It is defined as:

$$
\boxed{
\alpha=\frac{n}{m}
}
$$

Where:

- $n$ = Number of stored elements.
- $m$ = Number of table positions.

### Example

Suppose a hash table has:

$$
n=75,\quad m=100
$$

Then:

$$
\alpha=\frac{75}{100}
$$

$$
\boxed{\alpha=0.75}
$$

### Importance of Load Factor

The load factor directly influences the performance of hash-table operations.

- Low load factor generally reduces collisions.
- High load factor generally increases collisions.
- In open addressing, performance can deteriorate significantly as the table approaches full capacity.
- In separate chaining, the load factor represents the expected number of stored elements per bucket under uniform distribution.

## 6.2 Rehashing

Rehashing is the process of creating a new hash table, usually with a larger capacity, and inserting all existing elements into the new table using the new table configuration.

### When Is Rehashing Required?

Rehashing is commonly performed when the load factor exceeds a predefined threshold.

For example:

$$
\alpha>0.75
$$

The threshold is implementation-dependent.

### Rehashing Procedure

1. Create a new hash table with a larger capacity.
2. Retrieve all existing key-value pairs.
3. Recalculate the hash index of each key using the new capacity.
4. Insert each element into the new table.
5. Replace the old table with the new table.

**Important:** Existing entries must be rehashed because changing the table size can change their hash indices.

### Complexity

If $n$ elements are reinserted:

$$
T(n)=O(n)
$$

A single rehashing operation is linear in the number of stored elements.

However, with geometric growth, such as doubling the capacity, insertion can have amortized constant time:

$$
\boxed{O(1)\text{ amortized}}
$$

---

# 7. Analysis of Time and Space Complexity

The performance of hash tables depends on:

- The hash function.
- The collision-resolution scheme.
- The load factor.
- The distribution of input keys.
- The probing or bucket-search process.

## 7.1 Separate Chaining Complexity

Under simple uniform hashing, the expected number of elements in a bucket is:

$$
\alpha=\frac{n}{m}
$$

Therefore, searching requires expected time proportional to:

$$
O(1+\alpha)
$$

| Operation | Best Case | Expected Case | Worst Case |
|---|---|---|---|
| Insertion | O(1) | O(1)* | O(n) |
| Searching | O(1) | O(1 + α) | O(n) |
| Deletion | O(1) | O(1 + α) | O(n) |

*Assumes insertion at the head of a bucket and does not include an optional duplicate-key search.*

Space Complexity:

$$
O(m+n)
$$

## 7.2 Open Addressing Complexity

For open addressing, operations involve examining a sequence of table positions.

Under suitable hashing assumptions and with a controlled load factor, expected operation time is approximately constant.

However, as the load factor approaches 1, the expected number of probes increases.

| Operation | Expected Case (Controlled Load Factor) | Worst Case |
|---|---|---|
| Insertion | O(1) | O(n) |
| Searching | O(1) | O(n) |
| Deletion | O(1) | O(n) |

Space Complexity:

$$
O(m)
$$

### 7.3 Load Factor and Search Performance

For open addressing under the idealized uniform-probing model, expected probe bounds include:

**Unsuccessful Search:**

$$
E[\text{probes}]\leq\frac{1}{1-\alpha}
$$

**Successful Search:**

$$
E[\text{probes}]
\leq
\frac{1}{\alpha}
\ln\left(\frac{1}{1-\alpha}\right)
$$

These are bounds under the uniform hashing model, not exact performance formulas for every probing scheme.

Linear probing has additional clustering effects.

---

# 8. Comparison of Collision Resolution Techniques

| Feature | Separate Chaining | Linear Probing | Quadratic Probing | Double Hashing |
|---|---|---|---|---|
| Technique | Linked lists / buckets | Consecutive probing | Quadratic offsets | Two hash functions |
| Storage | Outside table buckets or linked structures | Inside table | Inside table | Inside table |
| Primary Clustering | No | Yes | Reduced | Reduced |
| Secondary Clustering | No | Yes, through shared buckets | Yes | Reduced |
| Load Factor | Can exceed 1 | Must be below 1 | Must be below 1 | Must be below 1 |
| Deletion | Simple | Tombstones or careful deletion | Tombstones or careful deletion | Tombstones or careful deletion |
| Extra Memory | Bucket overhead | No separate bucket structures | No separate bucket structures | No separate bucket structures |
| Worst-Case Search | O(n) | O(n) | O(n) | O(n) |

### Summary of Hashing Techniques

| Technique | Main Idea |
|---|---|
| Division Method | Remainder of key divided by table size |
| Multiplication Method | Fractional part of key multiplied by a constant |
| Mid-Square Method | Extract middle digits or bits of squared key |
| Folding Method | Divide key into groups and combine them |
| Polynomial Hashing | Convert characters into a polynomial expression |
| Separate Chaining | Store colliding elements in the same bucket |
| Linear Probing | Search consecutive table positions |
| Quadratic Probing | Search using quadratic offsets |
| Double Hashing | Use a second hash function for probe intervals |

---

# 9. Applications of Hash Tables

Hash Tables are widely used in computer science because of their efficient average-case lookup performance.

### 9.1 Databases

Hash-based indexing can provide efficient record lookup using selected key attributes.

### 9.2 Caches

Caches use hashing to locate previously stored data quickly.

### 9.3 Compilers

Symbol tables use hashing to store and retrieve identifiers, variables, and associated information.

### 9.4 Programming Languages

Common implementations include:

- C++: `unordered_map`, `unordered_set`
- Java: `HashMap`, `HashSet`
- Python: `dict`, `set`

### 9.5 Duplicate Detection

Hash sets can efficiently identify previously encountered elements.

### 9.6 Frequency Counting

Hash maps are commonly used to maintain the frequency of elements in arrays, strings, and datasets.

### 9.7 Distributed Systems

Hashing is used in techniques such as consistent hashing to distribute data across multiple servers.

---

# 10. Key Takeaways

1. A Hash Table stores key-value pairs and provides efficient average-case retrieval.
2. A Hash Function maps keys to valid table indices.
3. A good hash function should be deterministic, efficient, and distribute keys uniformly.
4. Collisions occur when different keys produce the same hash index.
5. The Division Method uses the remainder operation to calculate hash positions.
6. The Multiplication Method uses the fractional part of a multiplied key.
7. Separate Chaining stores colliding elements in the same bucket.
8. Open Addressing resolves collisions by searching for another empty position in the table.
9. Linear Probing suffers from primary clustering.
10. Quadratic Probing reduces primary clustering but can suffer from secondary clustering.
11. Double Hashing uses two hash functions to generate a more varied probing sequence.
12. Load Factor measures the number of stored elements relative to table capacity.
13. Rehashing increases table capacity and redistributes existing keys.
14. Hash-table operations generally achieve expected O(1) performance under suitable assumptions.
15. The worst-case time complexity of searching, insertion, and deletion can be O(n).

---

**End of Unit 4 — Hash Tables, Hash Functions & Collision Resolution**

*These notes serve as a quick-reference guide to hashing fundamentals, hash-function construction, collision-resolution techniques, and asymptotic complexity analysis.*

Unit-04/
│
├── README.md
│
├── Hash-Functions/
│   ├── DivisionMethod.cpp
│   ├── MultiplicationMethod.cpp
│   ├── MidSquareMethod.cpp
│   └── FoldingMethod.cpp
│
├── Collision-Resolution/
│   ├── SeparateChaining.cpp
│   ├── LinearProbing.cpp
│   ├── QuadraticProbing.cpp
│   └── DoubleHashing.cpp
│
└── Applications/
    ├── FrequencyCounter.cpp
    ├── DuplicateDetection.cpp
    └── TwoSum.cpp
