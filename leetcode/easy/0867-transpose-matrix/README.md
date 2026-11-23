# Transpose Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a 2D integer array `matrix`, return  *the  **transpose**  of*  `matrix`.

The  **transpose**  of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

 

Original
C
 **Example 1:** 

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

```

 **Example 2:** 

```
Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

```

 

 **Constraints:** 

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 1000
- 1 <= m * n <= 105
- -109 <= matrix[i][j] <= 109

## Solution

**Language:** C  
**Runtime:** 1 ms (beats 8.72%)  
**Memory:** 15.9 MB (beats 65.76%)  
**Submitted:** 2026-11-23T17:22:40.089Z  

```c
/**
 * Return an array of arrays.
 * The sizes of the arrays are returned through returnSize and returnColumnSizes.
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize,
                int* returnSize, int** returnColumnSizes) {

    int m = matrixSize;
    int n = matrixColSize[0];

    // Allocate memory for transposed matrix
    int** result = (int**)malloc(n * sizeof(int*));

    *returnColumnSizes = (int*)malloc(n * sizeof(int));

    *returnSize = n;

    for (int i = 0; i < n; i++) {
        result[i] = (int*)malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;
    }

    // Transpose the matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}
```

---

[View on LeetCode](https://leetcode.com/problems/transpose-matrix/)