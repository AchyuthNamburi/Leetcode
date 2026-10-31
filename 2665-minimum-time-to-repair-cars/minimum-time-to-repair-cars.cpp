class Solution {
public:
    // number of cars one mechanic (rank r) can repair within T minutes
    long long carsIn(long long T, long long r) {
        long long q = T / r;                     // we need n*n <= q
        long long n = (long long)sqrtl((long double)q);
        while (n * n > q) n--;                   // fix floating point errors
        while ((n + 1) * (n + 1) <= q) n++;
        return n;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long minR = *min_element(ranks.begin(), ranks.end());

        long long low = 1, high = minR * (long long)cars * cars;  // fastest mechanic does all cars
        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            for (int r : ranks) {
                count += carsIn(mid, r);
                if (count >= cars) break;        // early exit
            }
            if (count >= cars) high = mid;       // mid works, try smaller
            else low = mid + 1;                  // mid too small
        }
        return low;
    }
};