class Solution {
public:
    static bool comp(pair<pair<int,int>,int>& a,pair<pair<int,int>,int>& b){
        if(a.first.first != b.first.first){
            return a.first.first < b.first.first;
        }
        return a.first.second < b.first.second;
        
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        //{sum_of_digits,num}{index}
        vector<pair<pair<int,int>,int>> v;
        //idea is we are sorting based on the digitsum...and then counting the no of swaps using cycle_size-1 ( first we are finding the cycle)

        for(int i=0;i<n;i++){
            int sum=0;
            int curr=nums[i];
            while(curr){
                sum+=curr%10;
                curr/=10;
            }
            v.push_back({{sum,nums[i]},i});
        }

        sort(v.begin(),v.end(),comp);

        vector<bool> visited(n, false);

        int swaps=0;

        for(int i=0;i<n;i++){
            if(visited[i] || v[i].second==i) continue; // if it is already in the correct pos then skip 

            int cycle_size=0;
            int j=i;

            while(!visited[j]){
                visited[j]=1;
                j=v[j].second;
                cycle_size++;
            }

            swaps+=cycle_size-1;

        }

        return swaps;
    }
};