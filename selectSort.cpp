/*
    交换排序
    思想
        每次在无序的元素中从前往后找一个最小的元素与待排序的位置进行比较,交换
        第一趟找出最小的元素与第一个元素进行交换
        第二趟找出剩下的元素中最小的元素与第二个位置的元素进行狡猾
        .
        .
        .
    时间复杂度
        (n-1)+(n-2)+....+1 = n*(n-1)/2
*/
#include <iostream>
int swapData(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    return 0;
}

int selectSort(int a[], int len)
{
    for(int i = 0;i < len;i ++) {
        int index = i;
        for(int j = i+1;j < len;j ++) {
            if(a[j] < a[index]) {
                index = j;
            }
        }
        if(index != i) {
            swapData(a[index], a[i]);
        }
    }

    return 0;
}


int main(int argc, char **argv)
{
    int a[20] = {40, 8, 15, 18, 12};
    selectSort(a, 5);
    for(int i = 0;i < 5;i ++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}