/**
 * Hadn't pass the large case, cause of time limit exceeded
 */
public class Solution {
    public ArrayList<ArrayList<String>> findLadders(String start, String end, HashSet<String> dict) {
        HashMap<String,Integer> map = new HashMap<String,Integer>();
        bfs(map,start,end,1,dict);
        int len = map.get(end);
        HashMap<String,Boolean> visit = new HashMap<String,Boolean>();
        for(String str : dict)
            visit.put(str,false);
        ArrayList<ArrayList<String>> result = new ArrayList<ArrayList<String>>();
        LinkedList<String> path = new LinkedList<String>();
        visit.put(start,true);
        path.add(start);
        dfs(result,visit,path,start,end,1,len);
        return result;
    }
    
    private void dfs(ArrayList<ArrayList<String>> result, HashMap<String,Boolean> visit, LinkedList<String> path, String start, String end, int l, int length){
        if(l == length && start.equals(end)){
            ArrayList<String> newList = new ArrayList<String>();
            for(String s : path)
                newList.add(s);
            result.add(newList);
        }
        else if(l == length && !start.equals(end))
            return;
        for(int i = 0;i < start.length();i++)
            for(char c = 'a'; c <= 'z'; c++){
                StringBuilder sb = new StringBuilder(start);
                sb.setCharAt(i,c);
                String newString = sb.toString();
                if(visit.get(newString) != null && visit.get(newString).equals(false)){
                    visit.put(newString,true);
                    path.add(newString);
                    dfs(result,visit,path,newString,end,l + 1,length);
                    visit.put(newString,false);
                    path.removeLast();
                }
            }
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

