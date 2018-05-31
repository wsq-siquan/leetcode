#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main() {
    cout << "xx" << endl;
}

int trap(int* height, int heightSize) {
    int lh = 0; //left highest
    int res = 0; //result
    int le = height[0]; // left
    int lp = 0; // left position
    int ri = height[heightSize - 1]; //right
    int rp = heightSize - 1; // right position
    for(int i = 1; i < heightSize; ++i) {
        if(height[i] >= le) {
            for(int j = lp; j < i; j++) {
                res += (le - height[j]);
            }
            le = height[i];
            lp = i;
        }
    }
    for(int i = heightSize - 1; i >= lp; i--) {
        if(height[i] > ri) {
            for(int j = rp; j > i; j--) {
                res += (ri - height[j]);
            }
            ri = height[i];
            rp = i;
        }
    }
    return res;
}
