#include<stdio.h>
#include <sys/time.h>
#include <iostream>
unsigned long long GetCurrentMicroSecond() {
    struct timeval start;
    unsigned long long cur_time_in_microsend;
    gettimeofday(&start, NULL);
    cur_time_in_microsend = (start.tv_sec) * 1000 + start.tv_usec / 1000;
    return cur_time_in_microsend;
}
void HeapAdjust(int a[], int m, int n){
    int i;
    int t = a[m];

    for(i = 2 * m + 1;i <= n;i = 2 * i + 1){
        if(i < n && a[i + 1] > a[i])++i;
        if(t >= a[i])break;
        //把空缺位置往下放
        a[m] = a[i];
        m = i;
    }
    a[m] = t;//只做一次交换，步骤上的优化
}

void HeapSort(int a[], int n){
    int i;
    int t;

    //自下而上构造大根堆
    for(i = n / 2 - 1;i >= 0;--i){
        HeapAdjust(a, i, n - 1);
    }

    printf("初始堆: ");
    for(i = 0;i < n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    for(i = n - 1;i > 0;i--){
        //首尾交换，断掉尾巴
        t = a[i];
        a[i] = a[0];
        a[0] = t;
        //对断尾后的部分重新建堆
        HeapAdjust(a, 0, i - 1);
    }
}

int main(){
    //int a[] = {5, 6, 3, 4, 1, 2, 7};
    //int a[] = {1, 2, 3, 4, 5, 6, 7};
    //int a[] = {7, 6, 5, 4, 3, 2, 1};
//    int a[] = {7, 1, 6, 5, 3, 2, 4};
    int a[10240]={ 1, 3, 4, 5, 2, 6, 9, 7, 8, 0 };

    int size = 10000;

    for(auto i = 0;i < 10000; i ++) {
        a[i] = size - i;
    }
    int m, n;
    int i;

    m = 0;
    n = size;//sizeof(a) / sizeof(int);
    //HeapAdjust(a, m, n);
    int start = GetCurrentMicroSecond();
    HeapSort(a, n);
    int end = GetCurrentMicroSecond();
    std::cout << " HeapSort use : " << end -start << " ms " << std::endl;
//    printf("结果: ");
//    for(i = 0;i < n;i++){
//        printf("%d ", a[i]);
//    }
//    printf("\n");
}
