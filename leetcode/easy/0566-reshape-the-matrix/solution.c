
/**
 * Return an array of arrays.
 * The sizes of the returned array are returned in *returnSize and *returnColumnSizes.
 */
int** matrixReshape(int** mat, int matSize, int* matColSize,
                    int r, int c, int* returnSize,
                    int** returnColumnSizes) {

    int m = matSize;
    int n = matColSize[0];

    // Check whether reshaping is possible
    if (m * n != r * c) {
        *returnSize = m;
        *returnColumnSizes = (int*)malloc(m * sizeof(int));

        int** result = (int**)malloc(m * sizeof(int*));

        for (int i = 0; i < m; i++) {
            result[i] = mat[i];
            (*returnColumnSizes)[i] = n;
        }

        return result;
    }

    // Allocate the new matrix
    int** result = (int**)malloc(r * sizeof(int*));
    *returnColumnSizes = (int*)malloc(r * sizeof(int));

    for (int i = 0; i < r; i++) {
        result[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    // Copy elements in row-traversing order
    for (int i = 0; i < m * n; i++) {
        int oldRow = i / n;
        int oldCol = i % n;

        int newRow = i / c;
        int newCol = i % c;

        result[newRow][newCol] = mat[oldRow][oldCol];
    }

    *returnSize = r;

    return result;
}
