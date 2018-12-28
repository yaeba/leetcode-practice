/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int *res = malloc(sizeof(int) * (*returnSize));
    
    res[0] = 1;
    // compute the next value iteratively
    for (int i=0; i<rowIndex; i++) {
        int nextVal = 1.0 * res[i] * (rowIndex - i) / (i + 1);
        res[i+1] = nextVal;
    }
    
    return res;
}
