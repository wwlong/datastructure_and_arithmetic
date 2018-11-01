/*
    直接插入排序

    基本思想
        前面的都是已经排序好的,下一个
*/
#include <iostream>
int insertSort(int a[], int len) {
    int j = 0;
    for(int i = 1;i < len;i ++) {
        int tmp = a[i];
        int index = i;
        for(j = i - 1;j >= 0;j --) {
            if(tmp < a[j]){
                a[j+1] = a[j];
                index = j;
            }
        }
        if(i != index) {
            a[index] = tmp;
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    // int a[1024] = {13 ,14 ,94 ,33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10};

    int a[1024] = {16, 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    insertSort(a, 16);
    
    for(int i = 0;i < 16;i ++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}