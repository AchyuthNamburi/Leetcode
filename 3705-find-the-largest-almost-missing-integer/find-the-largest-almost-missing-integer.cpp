class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
       
        unordered_map<int,int> mp(n);
        int maxi=INT_MIN;
        vector<vector<int>> ans;

        for(int i=0;i<=n-k;i++){
            vector<int> temp;
            for(int j=i;j<i+k;j++){
                temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }

        for(auto it: ans){
            unordered_map<int,int> temp; // to count the freq of num
            // temp anedi ...total freq of elem ni store chestundi
            for (auto jt : it ){
                temp[jt]++;
            }

            for(auto &[key,val]:temp){ //idea ...temp map nunchi each elem teskuni ...inko map lo just add cheste saripotundi ga 
                mp[key]++; // ippud manaki unique occurrences of elem kavali
            }
        }

        int result = -1;
        for(auto &[key, val] : mp) {
            if(val == 1) {  // Check frequency = 1
                result = max(result, key);  // Track maximum directly
            }
        }
        return result;
    }
};

       