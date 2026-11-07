class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        vector<int> temp;
        while(x){
            int last=x%10;
            temp.push_back(last);
            x/=10;
        }

        int i=0;
        int j=temp.size()-1;

        while(i<j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
        
    }
};