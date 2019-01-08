/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    if (matrix == NULL || matrix[0] == NULL) {
        return NULL;
    }
    
    int *ans = malloc(sizeof(int) * matrixRowSize * matrixColSize);
    assert(ans != NULL);
    
    int top, bottom, left, right;
    top = left = 0;
    bottom = matrixRowSize - 1;
    right = matrixColSize - 1;
    
    int k = 0;
    while (top <= bottom && left <= right) {
        // move left
        for (int col=left; col<=right; col++) {
            ans[k++] = matrix[top][col];
        }
        top++;
        
        // move down
        for (int row=top; row<=bottom; row++) {
            ans[k++] = matrix[row][right];
        }
        right--;
        
        if (top > bottom || left > right) {
            // do not need to loop back
            break;
        }
        
        // move left
        for (int col=right; col>=left; col--) {
            ans[k++] = matrix[bottom][col];
        }
        bottom--;
        
        // move up
        for (int row=bottom; row>=top; row--) {
            ans[k++] = matrix[row][left];
        }
        left++;
    }
    
    return ans;
}
