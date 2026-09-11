class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // generate all the numbers and check the conditions 
        int n=digits.size();

        set<int> st;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    int num=0;
                    if(i!=j && j!=k && i!=k){
                         num+=digits[i]*100+digits[j]*10+digits[k]*1;
                    }
                    if(num>=100 && num<=999){
                        st.insert(num);
                    }
                    
                }
            }
        }

        int cnt=0;
        for(auto it : st){
            cout<<it<<" ";
            if(it%2==0){
                cnt++;
            }
        }

        return cnt;
    }
};