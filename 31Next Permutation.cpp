class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        for(int i = size - 2; i >= 0; i--) {
            if(nums[i + 1] > nums[i]) {
                for(int j = size - 1; j > i; j--) {
                    if(nums[j] > nums[i]) {
                        swap(nums[i],nums[j]);
                        reverse(nums.begin() + i + 1, nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
