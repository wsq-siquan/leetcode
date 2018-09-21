#include<cstdlib>
#include
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return {};
        int ans;
        int sdiff = 2147483647;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 2; ++i) {
            // while(i > 0 && nums[i] == nums[i - 1]) i++;
            int a = i + 1;
            int b = nums.size() - 1;
            while(a < b) {
                int sum = nums[i] + nums[a] + nums[b];
                if (sum == target) return target;
                int diff = sum - target;
                int adiff = abs(diff);
                if(adiff < sdiff) {
                    ans = sum;
                    sdiff = adiff;
                }
                if(diff > 0) {
                    b--;
                } else if(diff < 0) {
                    a++;
                }
            }
        }
        return ans;
    }
};
