class Solution {
public:
    // the pattern is that it will give the 2(pow,no_of_bits_needed_to_repr_n) is the unique no of triplets
    int uniqueXorTriplets(vector<int>& nums) {
        int bits=0;
        int large_num=*max_element(nums.begin(),nums.end());
        if(large_num==1) return 1;
        if(large_num==2) return 2;
        

        while(large_num){
            bits++;
            large_num >>= 1;
        }

        return 1 << bits;

        
    }
};