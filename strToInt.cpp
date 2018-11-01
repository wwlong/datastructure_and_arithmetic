/*
    字符创转化为整数

    空串
    空格
    非数字
    整型溢出
*/
#include <stdio.h>
#include <string.h>

bool isSpace(char c) {
    if(' ' == c) {
        return true;
    }
    else {
        return false;
    }
}

bool isDigital(char c) {
    if(c >= '0' && c <= '9') {
        return true;
    }
    else {
        false;
    }
}

int strToInteger(char *str) {
    if(NULL == str) {
        printf("NULL str\n");
    }
    static const int MAX_INT = (int)((unsigned)~0 >> 1);
    static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
    unsigned int n = 0;

    int len = strlen(str);
    int i = 0;
    while(isSpace(str[i])) {
        i ++;
        if(i >= len) {
            //超出了str的范围
            return -1;
        }
    }
    //处理正负
    int sign = 0;
    if('-' == str[i]) {
        sign = -1;
        i ++;
    }
    else if('+' == str[i]) {
        sign = 1;
        i ++;
    }
    else {
        sign = 1;
    }

    //开始计算
    while(isDigital(str[i])) {
        int d = str[i] - '0';
        if(sign > 0 && (MAX_INT / 10 < n || (MAX_INT / 10 == n) && (MAX_INT % 10 < d))) {
            //溢出了
            n = MAX_INT;
            break;
        }
        else if(sign < 0 && (unsigned int)MIN_INT / 10 < n || ((unsigned int)MIN_INT / 10 == n) && ((unsigned int)MIN_INT % 10 < d)) {
            n = MIN_INT;
            break;
        }

        n = n * 10 + d;
        i ++;
        if(i == len) {
            break;
        }
    }

    int integer = sign * n;
    printf("strToInteger : %d\n", integer);
    return integer;
}

int main()
{
    char str[128] = {"-2147"};

    int n = strToInteger(str);

    return 0;
}