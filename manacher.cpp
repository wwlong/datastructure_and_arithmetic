/*
    manacher alg
    get max length of palindrome substring 
*/
#include <iostream>
#include <cstring>

using namespace std;

//使用#填充字符串
int init(char *str,int strLen, char *newStr, int newStrLen) {
    if(NULL == str || NULL == newStr || strLen <= 0 || newStrLen <= 0 || strLen * 2 > (newStrLen - 1)) {
        cout << "invalid params" << endl;
        return -1;
    }
    memset(newStr, 0, newStrLen);
    newStr[0] = '$';
    int j = 0;
    for(int i = 1;i < strLen ;i ++) {
        newStr[j++] = '#';
        newStr[j++] = str[i];
    }
    newStr[j] = '#';
    cout << "newStr : " << newStr << endl;

    return j+1;
}

int manacher(char *str, int strLen)
{
    if(NULL == str) {
        cout << "NULL == str" << endl;
        return -1;
    }
    char newStr[1024] = {0};
    int newStrLen = init(str, strLen, newStr, sizeof(newStr));
    int p[1024] = {0};
    int id = 0;
    int mx = 0;
    int maxLen = 0;
    int i = 0;
    int maxp = 0;
    cout << "newStrlen : " << newStrLen << endl;
    for(i = 1;i < newStrLen; i ++) {
        cout << "i : " << i << endl;
        if(mx > i) {
            if(mx - i > p[2 * id - i]) {
                p[i] = p[2 * id - i];
            }
            else {
                p[i] = mx - i;
            }
        }
        else {
            p[i] = 1;
        }

        // for(; (str[i + p[i]] == str[i-p[i]]) && (i < newStrLen); i ++) {
        while((i + p[i] < newStrLen) && (i-p[i] >= 0) && (newStr[i + p[i]] == newStr[i-p[i]]) && (i < newStrLen) ) {
            cout << "i + p[i] : " << i + p[i] << " i-p[i] : " << i-p[i] << endl;
            if(newStr[i + p[i]] == newStr[i-p[i]]) {
                cout << "str[i + p[i]] : " << str[i + p[i]] << " str[i-p[i]] : " << str[i-p[i]] << endl;
            }
            p[i] ++;
        }

        cout << " +++ " << "p[i]+i : " << p[i]+i << " mx : " << mx << endl;
        if(p[i]+i > mx) {
            mx = p[i] + i;
            id = i;
            cout << "mx : " << mx  << " id :"<< id << " p[id] : " <<  p[i] <<  endl;
        }
    }

    //返回最长的
    for(i = 1;i < newStrLen;i ++) {
        printf("%d ", p[i]);
        if(p[i] > maxp) {
            maxp = p[i];
        }
    }
    printf("\n");

    return maxp;
}

int main(int argc, char **argv) {
    char str[1024] = {"12212321"};
    int len = manacher(str, strlen(str));

    cout << str << "'s max palindrome substring len : " << len << endl;
    return 0;
}