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


class Solution {
    vector<string> vdict;
    vector<vector<int> > adj;

    void build(unordered_set<string> &dict){
        int i, j;
        vdict.clear();
        unordered_map<string, int> ids;
        for(auto it=dict.begin(); it != dict.end(); it++){
            ids[*it] = vdict.size();
            vdict.push_back(*it);

        }
        adj.clear();
        adj.resize(vdict.size());
        for(int i = 0; i < vdict.size(); i++){
            string w = vdict[i];
            for(int j = 0; j < vdict[i].size(); j++){
                for(char c = 'a'; c <= 'z'; c++)
                    if(c != vdict[i][j]){
                        w[j] = c;
                        if(ids.count(w)){
                            adj[i].push_back(ids[w]);
                        }
                        w[j] = vdict[i][j];
                    }
            }
        }
    }

    void gen(int v1, int v2, vector<vector<int> >& prev, vector<int>& path, vector<vector<string> >&ans){
        path.push_back(v2);
        if(v2 == v1 and path.size() > 1){
            ans.push_back(vector<string>());
            for(auto rit = path.rbegin(); rit != path.rend(); rit++){
                ans.back().push_back(vdict[*rit]);
            }
        }else{
            int i;
            for(i = 0; i < prev[v2].size(); i++){
                gen(v1, prev[v2][i], prev, path, ans);
            }
        }
        path.pop_back();
    }
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dict.insert(start);
        dict.insert(end);
        build(dict);
        queue<int> que;
        vector<vector<int> > prev(vdict.size());
        vector<int> distance(vdict.size());

        int v, v1, v2;
        for(v1 = 0; vdict[v1] != start; v1++);
        for(v2 = 0; vdict[v2] != end; v2++);
        for(int i = 0; i < adj[v1].size(); i++){
            v = adj[v1][i];
            que.push(v);
            prev[v].push_back(v1);
            distance[v] = 1;
        }
        while(not que.empty()){
            int v1 = que.front(); que.pop();
            if(v1 == v2) break;
            int d = distance[v1] + 1;
            for(int i = 0; i < adj[v1].size(); i++){
                v = adj[v1][i];
                if(prev[v].size() == 0){
                    prev[v].clear();
                    prev[v].push_back(v1);
                    distance[v] = d;
                    que.push(v);
                }else if(distance[v] == d){
                    prev[v].push_back(v1);
                }
            }
        }

        vector<vector<string> > ans;

        vector<int> path;
        gen(v1, v2, prev, path, ans);

        return ans;
    }
};

