void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    // use first cell of row and col as flag to indicate if
    // matrix[row][col] should be zero
    int firstRowZero = 0;
    int firstColZero = 0;
    int i, j;
    
    // check if first row should be zeros
    for (j=0; j<matrixColSize; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }
    
    // check if first col should be zeros
    for (i=0; i<matrixRowSize; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }
    
    // find zeros and set matrix[0][col] and matrix[row][0]
    for (i=1; i<matrixRowSize; i++) {
        for (j=1; j<matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // set cells to zeros according to flags
    for (i=1; i<matrixRowSize; i++) {
        for (j=1; j<matrixColSize; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // set first row / first col to zeros if needed
    if (firstRowZero) {
        for (j=0; j<matrixColSize; j++) {
            matrix[0][j] = 0;
        }
    }
    if (firstColZero) {
        for (i=0; i<matrixRowSize; i++) {
            matrix[i][0] = 0;
        }
    }
}
