#include <iostream>
#include <sys/time.h>
/*
    堆排序
    创建堆 BuildHeap
    堆调整
        大顶堆调整 MaxHeapAdjust
        // 小顶堆调整 MinHeapAdjust //TODO
    堆排序 HeapSort
*/
unsigned long long GetCurrentMicroSecond() {
    struct timeval start;
    unsigned long long cur_time_in_microsend;
    gettimeofday(&start, NULL);
    cur_time_in_microsend = (start.tv_sec) * 1000 + start.tv_usec / 1000;
    return cur_time_in_microsend;
}

int swapData(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    return 0;
}

int HeapAdjust(int a[], int i, int size) {

    int parent = i;
    int lson = 2 * i + 1;
    if(lson >= size) {
        return -1;
    }
    int tmp = lson;
    int rson = lson + 1;
    if(rson  < size && a[lson] < a[rson]) {
        tmp = rson;
    }

    if(a[tmp] > a[parent]) {
        swapData(a[tmp], a[parent]);
        HeapAdjust(a, tmp, size);
    }
    return 0;
}

int BuildHeap(int a[], int size) {
    //从最大的非叶节点开始进行HeapAdjust
    for(int i = (size >> 1);i >= 0;i --) {
        HeapAdjust(a, i, size);
    }
    return 0;
}

int HeapSort(int a[], int size) {
    for(auto i = size - 1;i > 0;i --) {
        HeapAdjust(a, 0, i + 1);
        swapData(a[0], a[i]);
    }

    return 0;
}

int HeapSort(int a[], int size) {
//    BuildHeap(a, size);
//    swapData(a[0], a[size-1]);

    for(auto i = size;i > 0;i --) {
        HeapAdjust(a, 0, i);
        swapData(a[0], a[i-1]);
    }

    return 0;
}
int main(int argc, char **argv) {
    int a[10240]={ 1, 3, 4, 5, 2, 6, 9, 7, 8, 0 };

    int size = 10000;

    for(auto i = 0;i < 10000; i ++) {
        a[i] = size - i;
    }

    std::cout << "hello world" << std::endl;

    for(auto i = 0; i < size;i ++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    int start = GetCurrentMicroSecond();
    //堆排序
//    HeapSort(a, size);
    HeapSort(a, size);
    int end = GetCurrentMicroSecond();
    std::cout << " HeapSort use : " << end -start << " ms " << std::endl;
    for(auto i = 0; i < size;i ++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}