/*
    快速排序
    1.  找一个基准值
    2.  根据基准值将需要排序的数分成两个部分，一部分比基准值大，另一部分比基准值小
    3.  将分类后的各部分继续执行步骤1，2，直至完成所有排序

    思想；
    二分法
*/
#include <stdio.h>

int quick_sort(int num[], int left, int right)
{
    int ref = 0;    //保存基准值
    /*
       将基准值定义为数组最左边的数
    */
    ref = num[left];
    int i, j;
    i = right;
    j = left+1;
    if(left >= right) {
        return 0;
    }
    while(1) {
        //从右往左找到小于ref的值
        for(;i >= j;i--) {
            if(ref > num[i]) {
                break;
            }
        }
        //从左往右找大于ref的值
        for(;j <= i;j++) {
            if(ref < num[j]) {
                break;
            }
        }
        if(i <= j) {    //说明i和j走到一起了
            num[left] = num[i];
            num[i] = ref;
            break;
        }
        else {
            int tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
        }
        //从左往右找到第一个大于ref的值
    }
   //一次排序完成之后，进行递归
    quick_sort(num, left, i - 1);
    quick_sort(num, i + 1, right);
    return 0;
}

int main()
{
    int i;
    int num[10] = {6,1,2,7,9,3, 4, 5,10, 8};

    quick_sort(num, 0, 9);

    for(i = 0;i < 10;i ++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}
