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
