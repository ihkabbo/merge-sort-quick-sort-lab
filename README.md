# Comparison of Merge Sort and Quick Sort with Batch Insertion

A C-based project that implements and compares **Merge Sort** and **Quick Sort** by counting their element comparisons. It also demonstrates how to merge a new sorted batch of numbers with an already sorted array without sorting the entire array again.

## Project Overview

This project is developed using the C programming language as part of the **Algorithm Lab (CSE-208)** course.

The program performs three main tasks:

1. Sorts the original array using Merge Sort.
2. Sorts another copy of the same array using Quick Sort.
3. Merges a new already-sorted batch of numbers with the sorted array to create an updated sorted array.

It also counts the number of comparisons made by Merge Sort and Quick Sort so their performance can be observed and compared.

## Objectives

- Implement Merge Sort and Quick Sort using C.
- Count and compare the number of element comparisons made by both algorithms.
- Merge a new sorted batch with an already sorted array.
- Understand the performance and efficiency of different sorting techniques.

## Algorithms Used

### 1. Merge Sort

Merge Sort divides the array into smaller parts until each part contains one element. It then combines those parts in sorted order.

### 2. Quick Sort

Quick Sort uses the last element as the pivot. It places the pivot in its correct position and sorts the elements on its left and right sides.

### 3. Batch Merging

After sorting the original array, the program merges it with a new already-sorted batch. It compares elements from both arrays and places the smaller value into the updated array.

This avoids sorting the entire array again.

## Features

- Reads input from a text file named `input.txt`.
- Sorts the original data using two different algorithms.
- Counts comparisons made by Merge Sort and Quick Sort.
- Uses the last element as the Quick Sort pivot.
- Merges new sorted data without sorting the entire array again.
- Displays both sorted arrays and the final updated array.

## Input Format

The program reads data from `input.txt`.

The input format is:

```text
n m
original elements
sorted batch elements
```

Where:
- `n` is the number of original elements.
- `m` is the number of new batch elements.
- The original elements can be in any order.
- The new batch elements must already be sorted in ascending order.

## Sample Input

```text
6 3
45 12 30 8 20 15
10 25 40
```

## Time Complexity

| Algorithm | Time Complexity |
|---|---|
| Merge Sort | O(n log n) |
| Quick Sort (Average Case) | O(n log n) |
| Quick Sort (Worst Case) | O(n²) |
| Batch Merging | O(n + m) |

## Space Complexity

- **Merge Sort:** O(n) extra space for temporary arrays.
- **Quick Sort:** O(log n) average recursion space and O(n) in the worst case.
- **Updated Array:** O(n + m) space.

Here, `n` represents the number of original elements and `m` represents the number of new batch elements.

## How to Run

1. Make sure a C compiler, such as GCC, is installed.
2. Download or clone this repository.
3. Keep `input.txt` in the same folder as the C source file.
4. Compile the program:

```bash
gcc "YOUR_SOURCE_FILE.c" -o sorting
```

Replace `YOUR_SOURCE_FILE.c` with the actual name of the uploaded C file.

5. Run the program:

```bash
./sorting
```

On Windows, run:

```bash
sorting.exe
```

## Project Files

- [C Source Code](./YOUR_SOURCE_FILE.c)
- [Input File](./input.txt)

*Replace `YOUR_SOURCE_FILE.c` with the exact uploaded C filename.*

## Programming Language

- C

## Course Information

- **Course Title:** Algorithm Lab
- **Course Code:** CSE-208
- **Lab Report No.:** 02
- **Experiment:** Comparison of Merge Sort and Quick Sort with Batch Insertion
- **Department:** Computer Science and Engineering (CSE)
- **University:** Green University of Bangladesh

## Author

**Md. Imran Hossen**  
CSE Student  
Green University of Bangladesh

**GitHub:** [ihkabbo](https://github.com/ihkabbo)
