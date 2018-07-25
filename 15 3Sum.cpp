class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 2; ++i) {
            while(i > 0 && nums[i] == nums[i - 1]) i++;

            int a = i + 1;
            int b = nums.size() - 1;
            while(a < b) {
                if(a != i + 1 && nums[a] == nums[a - 1]) {
                    a++;
                    continue;
                }
                if(b != nums.size() - 1 && nums[b] == nums[b + 1]) {
                    b--;
                    continue;
                }
                int sum = nums[i] + nums[a] + nums[b];
                if(sum == 0) {
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[a]);
                    t.push_back(nums[b]);
                    ans.push_back(t);
                    a++;
                    b--;
                } else if(sum > 0) {
                    b--;
                } else if(sum < 0) {
                    a++;
                }
            }
        }
        return ans;
    }
};
