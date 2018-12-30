int maxArea(int* height, int heightSize) {
    // using two pointers on both ends
    int left = 0, right = heightSize - 1;
    int maxArea = 0;
    
    while (left < right) {
        // calculate area
        int minHeight = height[left] < height[right] ?
                        height[left] : height[right];
        int area = minHeight * (right - left);
        maxArea = area > maxArea ? area : maxArea;
        
        if (height[right] == minHeight) {
            // right pointer is limitting area, move right to 
            // taller point
            for (;left < right && height[right] <= minHeight; right--);
        } 
        if (height[left] == minHeight){
            // left pointer is limitting area, move left to
            // taller point
            for (;left < right && height[left] <= minHeight; left++);
        }
    }
    
    return maxArea;
}
