/*
    冒泡排序
    思想
        依次比较相邻两个元素大小,前者大于后者则进行交换
        有n个元素则每趟需要比较n-1次,共n趟
    算法时间复杂度
        O(n*(n-1)) = O(n*n)
    空间复杂度
        交换的时候需要一个临时空间,O(1)
*/
#include <iostream>
#include <stdlib.h>
#include <sys/time.h>

int swapData(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;

    return 0;
}

int bubbleSort(int a[], int len) {
    int i,j;
    for(i = 0;i < len;i ++) {
        bool flag = false;
        for(j = 0;j < len-1; j ++) {
            if(a[j] > a[j+1]) {
                swapData(a[j], a[j+1]);
                flag = true;
            }
        }
        if(flag == false) {
            return 0;
        }
    }
    return 0;
}

int genArray(int a[], int len) {
    if(NULL == a) {
        printf("a null\n");
        return -1;
    }
    for(int i = 0;i < len;i ++) {
        a[i] = rand();
    }

    return 0;
}
#define MAX_LEN 0x7FFFF

long getCurTimeMs()
{
    struct timeval curTime;
    gettimeofday(&curTime, NULL);
    return (curTime.tv_sec / 1000 + curTime.tv_usec / 1000);
}
int main(int argc, char **argv)
{
    //int a[20] = {40, 8, 15, 18, 12};
    int len = MAX_LEN;
    int a[MAX_LEN] = {0};

    long start = getCurTimeMs();
    bubbleSort(a, MAX_LEN);
    long end = getCurTimeMs();

    printf("bubble sort use : %ld ms\n", end - start);
    // for(int i = 0;i < 5;i ++) {
    //     std::cout << a[i] << " ";
    // }
    std::cout << std::endl;
    return 0;
}