/*
 *  三步反转法
 * */

#include <iostream>
#include <string.h>
using namespace std;
int reverse(char *str, int from, int to) {
    while(from < to) {
        char tmp = str[from];
        str[from] = str[to];
        str[to] = tmp;
        from ++;
        to --;
    }

    return 0;
}

int main()
{
    char str[16] = {"abcdefg"};
    reverse(str, 0, 1);
    reverse(str, 2, 6);
    reverse(str, 0, 6);
    cout << "reverse : " << str << endl;

    char str1[16] = {"ilovebaofeng"};
    int len = strlen(str1);
    reverse(str1, 0, len -1 - 7);
    reverse(str1, len - 6 - 1, len - 1);
    reverse(str1, 0, len - 1);
    cout << "reverse : " << str1 << endl;

    return 0;
}

