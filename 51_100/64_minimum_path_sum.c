#define MIN(x, y) ((x < y) ? x : y)

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    
    // for {(i, j) | i > 0 and j > 0}, minSum(A[i][j]) = 
    // min(A[i-1][j], A[i][j-1]) + A[i][j]
    
    for (int i=1; i<gridRowSize; i++) {
        grid[i][0] += grid[i-1][0];
    }
    
    for (int j=1; j<gridColSize; j++) {
        grid[0][j] += grid[0][j-1];
    }
    
    for (int i=1; i<gridRowSize; i++) {
        for (int j=1; j<gridColSize; j++) {
            grid[i][j] += MIN(grid[i-1][j], grid[i][j-1]);
        }
    }
    
    return grid[gridRowSize-1][gridColSize-1];
}
