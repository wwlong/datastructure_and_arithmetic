/*
    单词翻转。输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变，句子中单词以空格符隔开。
    为简单起见，标点符号和普通字母一样处理。例如，输入“I am a student.”，则输出“student. a am I”。
*/

/*
 *  三步反转法
 * */

#include <iostream>
#include <string.h>
#include <stdio.h>
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

int main(int argc, char **argv)
{
    char str[128] = {"I am a student."};
    int len = strlen(str);
    int i = 0, j ;
    int to = 0, from;
    for(i = 0;i < len; ) {
        if(str[i] == ' ') {
            i++;
            continue;
        }
        from = i;
        for(j = i;j < len;) {   //寻找单词的to,以空格为结束符
            if(str[j] != ' ') {
                j ++;
                continue;
            }
            break;
        }
        if(j <= len) {
            to = -- j;
            printf("before from : %d -- to : %d\n", from, to);
            std::cout << str  << endl;
            reverse(str, from, to);
            printf("after from : %d -- to : %d\n", from, to);
            i = ++ j ;
        }
        else {
            //结束了
            break;
        }
    }
    cout << __LINE__<< "    " << str << endl;
    reverse(str, 0, len-1);

    cout << "str reverse : " << str << endl;

    return 0;
}