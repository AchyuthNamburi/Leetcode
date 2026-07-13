class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> temp;

        for(int i=1;i<=n;i++){
            temp.push_back(to_string(i));
        }

        sort(temp.begin(),temp.end());

        vector<int> res;
        for(int i=0;i<temp.size();i++){

            res.push_back(stoi(temp[i]));
        }

        return res;
    }
};