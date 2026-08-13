class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;

        vector<vector<int>> mp(n);
        for(auto it:prerequisites){
            int a=it[1];
            int b=it[0];

            mp[a].push_back(b);
        }

        //so we have to find the cycle ...if cycle exists return false
        //use toposort to count the no of nodes we can visit...if we are not able to visit all the nodes then cycle

        vector<int> indegree(n,0);

        for(int i=0;i<n;i++){
            for(auto jt:mp[i]){
                indegree[jt]++;
            }
        }

        //push all nodes which has indegree==0 
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int visited=0;
        vector<int> topo;

        while(!q.empty()){
            int top=q.front();
            topo.push_back(top); // push into ans
            visited++;
            q.pop();

            for(auto neigh:mp[top]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }

        if(topo.size()==n) return topo;

        return {};
    }
};