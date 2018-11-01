/*
    shell sort 
    思想
        设置增量d
        对每一个间隔增量的数组进行插入排序
    时间复杂度

    空间复杂度
*/
#include <iostream>
int shellInsert(int a[], int len, int d) {
    for(int i = d;i < len;i ++) {
        int tmp = a[i];
        int index = i;
        for(int j = i - d;j >= 0;j -= d) {
            if(tmp < a[j]) {
                a[j+d] = a[j];
                index = j;
            }
        }
        if(index != i) {
            a[index] = tmp;
        }
    }

    return 0;
}
int shellSort(int a[], int len)
{
    int d = len / 2;
    while(d >= 1) {
        shellInsert(a, len, d);
        d = d >> 1;
    }

    return 0;
}

int main(int argc, char **argv) {
    int a[1024] = {13 ,14 ,94 ,33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10};
    shellSort(a, 16);
    
    for(int i = 0;i < 16;i ++) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}