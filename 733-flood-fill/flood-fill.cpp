class Solution {
public:
    vector<vector<int>> dir={{1,0},{-1,0},{0,-1},{0,1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();

        queue<vector<int>> q;
        q.push({sr,sc});
        int original=image[sr][sc];
        if(image[sr][sc]!=color){
            image[sr][sc]=color;
        }

        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int x=curr[0];
            int y=curr[1];
            

            for(int i=0;i<4;i++){
                int new_x=x+dir[i][0];
                int new_y=y+dir[i][1];

                if(original==color){
                    return image;
                }

                if(new_x>=0 && new_x<m && new_y<n && new_y>=0 && image[new_x][new_y]==original){
                    q.push({new_x,new_y});
                    image[new_x][new_y]=color;
                }
            }
        }

        return image;
    }
};