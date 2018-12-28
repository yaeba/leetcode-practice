class Solution {
    public List<Integer> getRow(int rowIndex) {
        ArrayList<Integer> res = new ArrayList<>(rowIndex + 1);
        
        for (int i=0; i<rowIndex+1; i++) {
            // add 1 at the end
            res.add(1);
            
            for (int j=i-1; j>0; j--) {
                // sum numbers from right to left
                res.set(j, res.get(j) + res.get(j-1));
            }
        }
        
        return res;
    }
}
