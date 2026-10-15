class Solution {
public:
    int sumCounts(vector<int>& nums) {
        vector<vector<int>> v;

        int n=nums.size();

        for(int i=0;i<n;i++){       // for start index
            for(int j=i;j<n;j++){      //for end index
                vector<int> temp;
                for(int k=i;k<=j;k++){ // for generating the values
                    temp.push_back(nums[k]);
                } 
                v.push_back(temp);
            }
            
        }

        int total=0;

        for(auto &vec : v){
            unordered_map<int,int> m;
            for(auto it:vec){
                m[it]++;
            }
            total+=m.size()*m.size();   
        }
           
        return total;

    
    }
};