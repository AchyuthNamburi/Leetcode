class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char,int> m;

        for(auto it:word){
            m[it]++;
        }

        vector<int> temp;
        
        for(auto &[keys,val]:m){
            temp.push_back(val);
        }

        sort(temp.begin(),temp.end());
        int idx=temp.size()-1;

         //case---- all char are same 
        if(temp.size()==1) return true;

        //case [1,2,2] --- remove 1st elem
        if(temp[0]==1 && temp[1]==temp[idx]) return true;

        //case ---[2,2,3] --- remove one from largest val
        if(temp[0]==temp[idx-1] && temp[idx]-temp[0]==1) return true;
        

        return false;
    }
};