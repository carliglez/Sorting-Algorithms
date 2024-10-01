# Internal Sorting Algorithms in C++

## Overview

This project focuses on implementing various internal sorting algorithms using C++ function templates. The program allows the user to choose between multiple sorting methods, input sequence sizes, and data input options.

### Implemented Sorting Algorithms

The following sorting algorithms are implemented in the program:

- **Quadratic Sorting Algorithms:**
  - Insertion Sort
  - Selection Sort
- **Log-Linear Sorting Algorithms:**
  - HeapSort
  - QuickSort
  - MergeSort
- **Others:**
  - Shell Sort (Diminishing Increment Sort)
  - RadixSort

## Program Functionality

The program operates as follows:

1. The sorting methods are executed using the `Key = long` data type.
2. The user is prompted to select the sorting algorithm to execute and the size of the sequence (N).
3. The user can choose between entering the N values manually or generating them randomly.
   - Randomly generated numbers will be in the range from 1000 to 9999.
4. The program displays the trace of the sorting process, showing at least the sequence after each iteration of the algorithm.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
