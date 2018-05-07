
#include<string>
#include<cstring>
#include<iostream>

using namespace std;


int search(int* n, int ns, int target) {
    int l = 0, r = ns - 1;
    int res = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(n[mid] == target) return mid;
        if(target >= n[l]) {
            if(n[mid] >= n[l] && n[mid] < target) l = mid + 1;
            else r = mid - 1;
        } else if(target < n[l]) {
            if(n[mid] < n[l] && n[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
    }
    return res;
}
