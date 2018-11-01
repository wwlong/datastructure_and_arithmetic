/*
    shell sort
    思想
        将无需数组分成多个子序列,每个子序列不是分段的,而是相隔特定增量的子序列,对每个子序列进行插入排序
        然后选择一个较小的增量,对更多的子序列进行增量排序
        最终选择增量为1,对整体进行一次直接插入排序
    增量的选择
        在每趟的排序过程都有一个增量，至少满足一个规则 增量关系 d[1] > d[2] > d[3] >..> d[t] = 1 (t趟排序)；根据增量序列的选取其时间复杂度也会有变化，
        这个不少论文进行了研究，在此处就不再深究；本文采用首选增量为n/2,以此递推，每次增量为原先的1/2，直到增量为1
*/

#include <iostream>
#include <cstdio>

int shellSort(int a[], int len) {
    if(NULL == a || len <= 0) {
        std::cout << "invalid params" << std::endl;
        return -1;
    }
    int k = 0;
    for(int i = len >> 1;i >= 1;i = i >> 1) {
        for(int j = i;j < len;j ++) {
            int tmp = a[j];
            for(k = j - i;k >= 0 && a[k] > tmp; k -= i){
                a[k+i] = a[k];
            }
            if(j != k + i) {
                a[k] = tmp;
            }
        }
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
