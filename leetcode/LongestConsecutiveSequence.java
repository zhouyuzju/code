public class Solution {
    public int longestConsecutive(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        int max = 1;
        for(int i : num){
            if(map.containsKey(i))
                continue;
            map.put(i,1);
            if(map.containsKey(i - 1)){
                max = Math.max(max,merge(map,i - 1,i));
            }
            if(map.containsKey(i + 1)){
                max = Math.max(max,merge(map,i,i + 1));
            }
        }
        return max;
    }
    private int merge(HashMap<Integer,Integer> map,int left,int right){
        int upper = right + map.get(right) - 1;
        int low = left - map.get(left) + 1;
        int len = upper - low + 1;
        map.put(low,len);
        map.put(upper,len);
        return len;
    }
}

