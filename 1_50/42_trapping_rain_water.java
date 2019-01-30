class Solution {
//     public int trap(int[] height) {
//         // brute force
//         // O(n^2) time, O(1) space
        
//         // At each point, water trapped (above point)
//         // is [min(max(left), max(right)) - point]
        
//         int total = 0;
        
//         for (int i=1; i<height.length-1; i++) {
//             int maxLeft = 0, maxRight = 0;
//             for (int j=0; j<=i; j++) {
//                 // find left max
//                 maxLeft = Math.max(maxLeft, height[j]);
//             }
//             for (int j=i; j<height.length; j++) {
//                 // find right max
//                 maxRight = Math.max(maxRight, height[j]);
//             }
//             total += Math.min(maxLeft, maxRight) - height[i]; 
//         }
//         return total;
//     }
    
    public int trap(int[] height) {
        // Using two pointers
        // O(n) time, O(1) space
        
        int total, maxLeft, maxRight;
        total = maxLeft = maxRight = 0;
        
        int left = 0;
        int right = height.length - 1;
        
        while (left < right) {
            if (height[left] < height[right]) {
                // water will be bounded by >= height[right]
                // height[left] is limiting total
                if (height[left] > maxLeft) {
                    // update seen maxLeft
                    maxLeft = height[left];
                } else {
                    // water is trapped above this point
                    total += maxLeft - height[left];
                }
                left++;
            } else {
                // water will be bounded by >= height[left]
                // height[right] is limiting total
                if (height[right] > maxRight) {
                    // update seen maxRight
                    maxRight = height[right];
                } else {
                    // water is trapped above this point
                    total += maxRight - height[right];
                }
                right--;
            }
        }
        
        return total;
    }
}
