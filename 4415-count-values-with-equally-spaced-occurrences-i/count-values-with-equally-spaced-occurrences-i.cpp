class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        

        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        int cnt=0;
        for(auto &[key,val]:m){
            
            if(val==3){
                int k=key;
                vector<int> temp;
                for(int i=0;i<n;i++){
                    if(nums[i]==k){
                        temp.push_back(i);
                    }
                }

                if(temp[1]-temp[0]==temp[2]-temp[1]) cnt++;

            }
        }

        return cnt;
    }
};