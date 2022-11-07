/*#题目：剑指Offer 05.替换空格
力扣题目链接(opens new window)

请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1： 输入：s = "We are happy."
输出："We%20are%20happy."*/
#include <vector>
#include <iostream>
using namespace std;

string replaceSpace(string s){
    int count= 0;//计算空格的个数
    int sOldsize = s.size() - 1;
    for(int  i = 0;i<s.size();i++){
        if(s[i] == ' '){
            count++;
        }
    }
    s.resize(s.size()+count*2);
    int sNewsize = s.size() - 1;
    for(int i = sOldsize,j=sNewsize;i<j;i--,j--){
        if(s[j] != ' '){
            s[i] = s[j];
        } else {
            s[i] = '0';
            s[i-1]='2';
            s[i-2]='%';
            i -=2;
        }
    }
    return s;
}

int main(int argc,char** argv){
    return 0;
}