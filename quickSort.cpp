/*
    quickSort 
    思想
        分治
        一次排序,先找一个pivot,将整个数组分成以pivot为中点的两部分,一部分都小于pivot,另一部分都大于等于pivot
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int swapData(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    return 0;
}
int displayArray(int a[], int len) {
    for(int i =0;i < len;i ++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
    return 0;
}
int partition(int a[], int l, int r) {
    if(a == NULL || l >= r) {
        printf("invalid params\n");
        exit(-1);
        // return -1;
    }
    int pivot = a[l];
    int i = l+1;
    int j = r;
    while(i <= j) {
        while(i <= j) {
            if(a[j] >= pivot) {
                j --;
            }
            else {
                break;
            }
        }

        while(i <= j) {
            if(a[i] < pivot) {
                i ++;
            }
            else {
                break;
            }
        } 

        if(i < j) {
            swapData(a[i], a[j]);
        }
        else if(i >= j) {
            swapData(a[l], a[j]);
            
            return j;
        }
    } 

    return 0;
}

int quickSort_c(int a[], int l, int r) {
    if(l >= r) {
        return 0;
    }
    int i = partition(a, l, r);
    printf("partition l : %d, r : %d, i : %d\n",l, r, i);
    displayArray(a, 10);
    quickSort_c(a, l, i - 1);
    quickSort_c(a, i + 1, r);

    return 0;
}


int main(int argc, char **argv)
{
    int a[1024] = {4,3,5,7,9,2,1,6,8,0};
    quickSort_c(a, 0, 9);

    displayArray(a, 10);
    return 0;
}