class Solution {
public:
    bool isfeasible(int mid,vector<int>& bloomDay,int k,int m){
        int bouq_cnt=0;
        int consec_cnt=0;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                consec_cnt++;
                if(consec_cnt==k){
                    bouq_cnt++;
                    consec_cnt=0;
                }
            }
            else {
                consec_cnt=0;
            }
        }

        return bouq_cnt>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();

        long long total_flow=(long long ) m*k;

        if(total_flow>n) return -1;

        int low=*min_element(bloomDay.begin(),bloomDay.end());;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(isfeasible(mid,bloomDay,k,m)){
                ans=mid; 
                high=mid-1; // this mid is fine but check for even min
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};