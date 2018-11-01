#include <iostream>

/*
 *  binary search
 *  边界条件
 *      low < high 还是 low <= high?
 *      
 * */
using namespace std;

int bsearch(int a[], int n, int val) {
    if(NULL == a|| n <= 0) {
        std::cout << "invalid params" << std::endl;
    }
    int low = 0;
    int high = n - 1;
    int findTimes = 0;
    while(low <= high) {
        findTimes ++;
        int mid = low + (high - low)/2;
        std::cout << "times : " << findTimes << " mid : " << mid << endl;
        if(val == a[mid]) {
            std::cout << "found " << val << " in arr[" << mid <<"]" << endl;
            std::cout << "use " << findTimes << " times" << endl;
            return mid;
        }
        else if(val < a[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return 0;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    int a[1024] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    for(i = 0;i < 1000;i ++) {
        a[i] = i;
    }
    int pos = bsearch(a, i, 4);
    std::cout << "position : " << pos << endl;
    return 0;
}

