#include<vector>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        if(nums1.size() == 0) return findMedianSortedArrays(nums2, nums2);
        if(nums2.size() == 0) return findMedianSortedArrays(nums1,nums1);

        int size1 = nums1.size(), size2 = nums2.size();
        int mid1 = 0, mid2, left = 0, right = size1;
        int lm=0,rm=0;

        while(right >= left) {
            mid1 = (right + left) >> 1; // i
            mid2 = (size1 + size2 + 1) >> 1 - mid1; // j
            if(mid1 < right && nums2[mid2 - 1] > nums1[mid1]) {
                left = mid1 + 1;
            } else if(mid1 > left && nums1[mid1-1] > nums2[mid2]) {
                right = mid1 - 1;
            } else {
                if(mid1 == 0) {
                    lm = nums2[mid2-1];
                } else if (mid2 == 0) {
                    lm = nums1[mid1-1];
                } else {
                    lm = nums1[mid1-1] > nums2[mid2-1] ? nums1[mid1-1] : nums2[mid2-1];
                }
                if((size1 + size2) %2 ==1) return lm;

                if(mid1 == size1) {
                    rm = nums2[mid2];
                } else if(mid2 == size2) {
                    rm = nums1[mid1];
                } else {
                    rm = nums1[mid1] < nums2[mid2] ? nums1[mid1] : nums2[mid2];
                }
                return (double)(lm + rm) / 2.0;
            }
        }
        return 110;
    }
};


double findMedianSortedArrays(int* nums1, int size1, int* nums2, int size2) {
        if(size1 > size2) {
            printf("xx\n");
            return findMedianSortedArrays(nums2,size2, nums1,size1);
        }
        //if(size1 == 0) return findMedianSortedArrays(nums2,size2, nums2,size2);
        //if(size2 == 0) return findMedianSortedArrays(nums1,size1,nums1,size1);

        int mid1 = 0, mid2, left = 0, right = size1;
        int lm=0,rm=0;

        while(right >= left) {
            mid1 = (right + left) >> 1; // i
            mid2 = (size1 + size2 + 1) /2 - mid1; // j
            cout << mid1 << "\t" << mid2 << endl;
            if(mid1 < right && nums2[mid2 - 1] > nums1[mid1]) {
                left = mid1 + 1;
            } else if(mid1 > left && nums1[mid1-1] > nums2[mid2]) {
                right = mid1 - 1;
            } else {
                if(mid1 == 0) {
                    lm = nums2[mid2-1];
                } else if (mid2 == 0) {
                    lm = nums1[mid1-1];
                } else {
                    lm = nums1[mid1-1] > nums2[mid2-1] ? nums1[mid1-1] : nums2[mid2-1];
                }
                if((size1 + size2) %2 ==1) return lm;

                if(mid1 == size1) {
                    rm = nums2[mid2];
                } else if(mid2 == size2) {
                    rm = nums1[mid1];
                } else {
                    rm = nums1[mid1] < nums2[mid2] ? nums1[mid1] : nums2[mid2];
                }
                return (double)(lm + rm) / 2.0;
            }
        }
        return 110;
}

int main() {
cout << (3>>(1+1)) << endl;
}
