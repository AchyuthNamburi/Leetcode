class Solution {
public:
    vector<int> ans;
    
    vector<int> sequentialDigits(int low, int high) {

        for(int i=1;i<9;i++){
           int num=i;
           int next=i+1;

           while(next<=9){
            num=num*10+next;
            if(num>=low && num<=high){
                ans.push_back(num);
            }
            next++;
           }
           
        }

        sort(ans.begin(),ans.end());

        return ans;  
    }
};