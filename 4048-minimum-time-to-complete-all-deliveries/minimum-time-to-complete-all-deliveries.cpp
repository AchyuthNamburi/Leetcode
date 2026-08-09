class Solution {
public:
    bool canDeliver(long long T, vector<int>& d, vector<int>& r) {
        // Total deliveries needed
        long long totalNeeded = (long long)d[0] + d[1];
        
        // Hours each drone can work individually
        long long drone0Hours = T - (T / r[0]);
        long long drone1Hours = T - (T / r[1]);
        
        // Each drone must have enough hours for its own deliveries
        if(drone0Hours < d[0] || drone1Hours < d[1]) {
            return false;
        }
        
        // Hours when BOTH drones are recharging (neither can work)
        long long lcmVal = lcm(r[0], r[1]);
        long long bothRechargeHours = T / lcmVal;
        
        // Hours when at least one drone can work
        long long availableSlots = T - bothRechargeHours;
        
        // Total available slots must be enough for all deliveries
        return availableSlots >= totalNeeded;
    }
    
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long low = 1;
        long long high = 1e14;  // Large enough upper bound
        long long ans = -1;
        
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            
            if(canDeliver(mid, d, r)) {
                ans = mid;
                high = mid - 1;  // Try to find smaller time
            } else {
                low = mid + 1;   // Need more time
            }
        }
        
        return ans;
    }
};
    