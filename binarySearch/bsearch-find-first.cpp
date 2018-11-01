#include <iostream>
using namespace std;
/*
 *  查找第一个值等于给定值的元素
 * */
int bsearch1(int a[], int n, int val) {
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = low + ((high - low) >> 1);
        if(a[mid] > val) {
            high = mid - 1;
        }
        else if(a[mid] < val) {
            low = mid + 1;
        }
        else {//a[mid] == val
            if((mid > 0) && (a[mid-1] == val)) {
                high = mid - 1;
            }
            else {
                return mid;
            }
        }
    }

    return -1;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    int a[1024] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    for(i = 0;i < 100;i ++) {
            a[i] = i;
    }
    a[3]=4;
    a[5]=4;
    a[6]=4;
    cout << endl;
    int pos = bsearch1(a, i, 4);
    std::cout << "position : " << pos << endl;
    return 0;
}
