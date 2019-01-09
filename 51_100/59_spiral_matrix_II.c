/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int **ans = malloc(sizeof(int*) * n);
    
    for (int i=0; i<n; i++) ans[i] = malloc(sizeof(int) * n);
    
    int top, bottom, left, right;
    top = left = 0;
    bottom = right = n - 1;
    
    int k = 1;
    
    while (top <= bottom && left <= right) {
        // move left
        for (int col=left; col<=right; col++) {
            ans[top][col] = k++;
        }
        top++;
        
        // move down
        for (int row=top; row<=bottom; row++) {
            ans[row][right] = k++;
        }
        right--;
        
        if (top > bottom || left > right) {
            // do not need to loop back
            break;
        }
        
        // move left
        for (int col=right; col>=left; col--) {
            ans[bottom][col] = k++;
        }
        bottom--;
        
        // move up
        for (int row=bottom; row>=top; row--) {
            ans[row][left] = k++;
        }
        left++;
    }
    
    return ans;
}
