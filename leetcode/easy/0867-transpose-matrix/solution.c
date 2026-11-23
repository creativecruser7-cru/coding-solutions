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