#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int firstMissingPositive(int* n, int ns) { // array numbers , numbers size
    int t;
    for(int i = 0; i < ns; ++i) {
        // take out the number from the array, and set the original position to 0.
        // 取出数组中的数，并将原位置设为0
        t = n[i];
        n[i] = 0;
        // loop：switch number i to the array,the index is i-1
        //循环：将数字i放在数组的i-1位置中
        // every num that is bigger than numSize or non-positive will no be the answer. so just drop them.
        //所有大于数组大小或者非正数，都不会是我们所需要的数字，直接抛弃
        while(t > 0 && t <= ns && n[t - 1] != t) {
            int x = n[t - 1];
            n[t - 1] = t;
            t = x;
        }
    }
    // check if every position i-1 have the num i
    // 检测每个位置i-1是否是数字i
    for(int i = 0; i < ns; ++i) {
        if(n[i] != i + 1) return i + 1;
    }
    //every position have the right number, from 1 to size ,than the missing positive number is size+1
    //如果每个数字都在原位上，那就是从1到size，于是缺失的数字就是size+ 1
    return ns + 1;
}


// useless but interesting main
int main() {
    int a[5] = {1,2,3,4,5};
    cout << a[4] << endl;
    cout <<4[a] << endl;

}
