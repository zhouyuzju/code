public class Solution {
    public int ladderLength(String start, String end, HashSet<String> dict) {
        // Start typing your Java solution below
        // DO NOT write main() function
        HashMap<String,Integer> map = new HashMap<String,Integer>();
        bfs(map,start,end,1,dict);
        return map.get(end);
    }
    
    private void bfs(HashMap<String,Integer> map, String start, String end, int depth, HashSet<String> dict){
        Queue<String> q = new LinkedList<String>();
        map.put(start,depth);
        q.offer(start);
        
        while(q.size() > 0){
            String tmp = q.poll();
            int level = map.get(tmp) + 1;
            for(int i = 0;i < tmp.length();i++)
                for(char j = 'a';j <= 'z';j++){
                    StringBuilder sb = new StringBuilder(tmp);
                    sb.setCharAt(i,j);
                    String newString = sb.toString();
                    if(dict.contains(newString)){
                        if(newString.equals(end)){
                            map.put(end,level);
                            return;
                        }
                        if(map.get(newString) == null){
                            map.put(newString,level);
                            q.offer(newString);
                        }
                    }
                }
        }
        if(map.get(end) == null)
            map.put(end,0);
    }

}

