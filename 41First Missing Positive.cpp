#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int firstMissingPositive(int* n, int ns) { // array numbers , numbers size
    int t;
    for(int i = 0; i < ns; ++i) {
        // take out the number from the array, and set the original position to 0.
        // ȡ�������е���������ԭλ����Ϊ0
        t = n[i];
        n[i] = 0;
        // loop��switch number i to the array,the index is i-1
        //ѭ����������i���������i-1λ����
        // every num that is bigger than numSize or non-positive will no be the answer. so just drop them.
        //���д��������С���߷�����������������������Ҫ�����֣�ֱ������
        while(t > 0 && t <= ns && n[t - 1] != t) {
            int x = n[t - 1];
            n[t - 1] = t;
            t = x;
        }
    }
    // check if every position i-1 have the num i
    // ���ÿ��λ��i-1�Ƿ�������i
    for(int i = 0; i < ns; ++i) {
        if(n[i] != i + 1) return i + 1;
    }
    //every position have the right number, from 1 to size ,than the missing positive number is size+1
    //���ÿ�����ֶ���ԭλ�ϣ��Ǿ��Ǵ�1��size������ȱʧ�����־���size+ 1
    return ns + 1;
}


// useless but interesting main
int main() {
    int a[5] = {1,2,3,4,5};
    cout << a[4] << endl;
    cout <<4[a] << endl;

}
