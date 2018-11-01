/*
    归并排序
    思想

    是不是原地排序算法?

    是不是稳定的?

    时间复杂度
        最好
        最坏
        平均
    
    分治
        递推公式
            mergeSort(a, l, r) = merge(merge(a, l,m), merge(a, m + 1, r))
            merge(a[l,r], a[l,m],a[m+1,r])
        终止条件
            l >= r
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int mergeSort(int a[], int l, int r);
int merge(int a[],int l, int r,int m);

#define MAX_SIZE 10000
int tmp[MAX_SIZE];
/*
    merge a[r..m] a[m+1...l] --> a[l...r]
*/
int merge(int a[],int l, int r, int m) {
    memset(tmp, 0, MAX_SIZE);
    int len = r - l + 1;
    int x = l;// x >= l && x <=m
    int y = m + 1;  //y >= m+1 && y <= r
    int i = 0;
    for(i = 0;i < len; i ++) {
        if(x <= m && y <= r) {
            if(a[x] < a[y]) {
                tmp[i] = a[x];
                x ++;
            }
            else {
                tmp[i] = a[y];
                y ++;
            }
        }  
        else {
            break;
        }
    }

   if(x > m) {
       while(y <= r) {
           tmp[i] = a[y];
           y ++;
           i ++;
       }
   }
   else {
       while(x <= m) {
           tmp[i] = a[x];
           x ++;
           i ++;
       }
   }
    //将tmp拷贝回a
    for(int i = 0;i < len; i ++) {
        a[l] = tmp[i];
        l ++;
    }

    return 0;
}
int mergeSort(int a[], int l, int r) {
    printf("r >= l\n");
    if(l >= r) {
        return 0;
    }
    int m = (r + l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);

    merge(a, l, r, m);

    return 0;
}

int displayArray(int a[], int len) {
    for(int i =0;i < len;i ++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
    return 0;
}
int main(int argc, char **argv) {
    int a[1024] = {1,3,5,7,9,2,4,6,8,0,11,13,15,17,19, 12, 14,16,18,20};
    mergeSort(a, 0, 19);
    displayArray(a, 20);

    return 0;
}
