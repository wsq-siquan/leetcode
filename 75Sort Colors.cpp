class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = nums.size();
        int n0, n1, n2;
        n0 = n1 = n2 = -1;
        for(int i= 0 ; i < s; ++i) {
            if(nums[i] == 0) {
                nums[++n2] = 2;
                nums[++n1] = 1;
                nums[++n0] = 0;
            } else if(nums[i] == 1) {
                nums[++n2] = 2;
                nums[++n1] = 1;
            } else if(nums[i] == 2) {
                nums[++n2] = 2;
            }
        }

}
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numsSize = nums.size();
    int fn0 = numsSize, ln2 = 0 ;
    for(int i= numsSize - 1; i > 0; --i) {
        if(nums[i] != 2) {
            ln2 = i;
            break;
        }
    }
    for(int i = 0; i < numsSize; ++i) {
        if(nums[i] == 0) {
            if(fn0 < i) {
                swap(nums[fn0], nums[i]);
                fn0++;
                i--;
            }
        } else if(nums[i] == 1) {
            if(fn0 > i) fn0 = i;
        } else if(nums[i] == 2) {
            if(ln2 > i) {
                swap(nums[i], nums[ln2]);
                ln2--;
                i--;
            }
        }
    }
}
};

