class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        
        for (int i=0; i<numRows; i++) {
            ArrayList<Integer> tmp = new ArrayList<>();
            
            if (i > 0) {
                List<Integer> prevList = res.get(i-1);
                // add first element
                tmp.add(1);
                
                // add previous two elements
                for (int j=1; j<i; j++) {
                    tmp.add(prevList.get(j-1) + prevList.get(j));
                }
            }

            // add last one
            tmp.add(1);
            res.add(tmp);
        }
        return res;
    }
}
