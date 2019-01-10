class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 ||
           matrix[0] == null || matrix[0].length == 0) {
            return false;
        }
        
        // O(log(m*n)) time, O(1) space
        int nRow = matrix.length, nCol = matrix[0].length;
        int left = 0, right = nRow * nCol - 1;
        
        while (left <= right) {
            // use binary search
            int mid = (left + right) / 2;
            int val = matrix[mid/nCol][mid%nCol];
            
            if (target == val) {
                return true;
            } else if (target <= val) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
}
