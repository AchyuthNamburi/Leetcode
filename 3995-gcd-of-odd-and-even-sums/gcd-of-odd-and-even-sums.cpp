class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int temp=n;
        int sumOdd=0;
        int i=1;
        while(temp){
            sumOdd+=i;
            i+=2;
            temp--;
        }
        
        cout<<sumOdd;

        int sumEven=0;
        int j=2;
        temp=n;
        while(temp){
            sumEven+=j;
            j+=2;
            temp--;
        }
         cout<<sumOdd;

        return gcd(sumEven,sumOdd);
    }
};