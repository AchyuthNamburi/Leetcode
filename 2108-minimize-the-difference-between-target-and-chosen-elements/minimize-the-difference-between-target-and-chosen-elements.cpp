class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        //rule is 
        //for every row...u have to take exactly one element
        //so this is not a standard pick/notpick case
        //this is multiple-choice knapsack

        int m=mat.size();
        int n=mat[0].size();

        int maxSum=70*70;

        vector<int> canMake(maxSum+1,0);
        canMake[0]=1;

        for(int row=0;row<m;row++){
            vector<int> newCanMake(maxSum+1,0);

            for(int oldsum=0;oldsum<=maxSum;oldsum++){
                if(canMake[oldsum]==0) continue;

                for(int item=0;item<n;item++){
                    int newsum=oldsum+mat[row][item];
                    if(newsum <= maxSum){
                        newCanMake[newsum]=1;
                    }
                }
            }
            canMake=newCanMake;

        }

        int smallestDiff=INT_MAX;
        for(int i=0;i<maxSum;i++){
            if(canMake[i]==1){
                int diff=abs(i-target);
                if(diff < smallestDiff){
                    smallestDiff=diff;
                }
            }
        }

        return smallestDiff;

    }
};