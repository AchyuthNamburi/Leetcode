class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        // think ...x and y as nodes ...we have to reach from x to y 
        // we has many options to go in a single level 
        // so traverse level by level
        // and then calc the no of levels( steps) it took to reach y

        queue<pair<int,int>> q;
        vector<bool> visited(100000,false);

        q.push({x,0});
        visited[x]=true; // dont forget to mark

        while(!q.empty()){
            auto [val,steps]=q.front();
            q.pop();
            if(val == y) return steps; // base case

            if(val%11==0 && !visited[val/11]){
                visited[val/11]=true;
                q.push({val/11,steps+1});
            }
            if(val%5==0 && !visited[val/5]){
                visited[val/5]=true;
                q.push({val/5,steps+1});
            }
            if(val-1>=0 && !visited[val-1]){
                visited[val-1]=true;
                q.push({val-1,steps+1});
            }
            if(!visited[val+1]){
                visited[val+1]=true;
                q.push({val+1,steps+1});
            }
        }

        return -1;
    }
};