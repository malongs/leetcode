/*
459.重复的子字符串
力扣题目链接(opens new window)

给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:
输入: "abab"
输出: True
解释: 可由子字符串 "ab" 重复两次构成。

示例 2:
输入: "aba"
输出: False

示例 3:
输入: "abcabcabcabc"
输出: True
解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
#思路
*/ 
#include <iostream>
using namespace std;

bool repeatedSubstringPattern(string s) {
    string t = s + s;
    t.erase(t.begin());
    t.erase();
    if(t.find(s) != std::string::npos) {
        return true;
    }
    return false;
}

//KMP解法
//如果字符串由重复子串组成，最长相等前后缀就是不包含那部分为重复字串

void getNext(int* next,const string s) {
    int j = -1;
    next[0] = j;
    for(int i = 1; i < s.size();i++) {
        while(j>0 && next[i] != next[j+1]) {
            j = next[j];
        }
        if(next[i] == next[j+1]) {
            j++;
        }
        next[i] = j;
    }
}


bool repeatedSubstringPattern2(string s) {
    if(s.size()== 0){
        return false;
    }
    int next[s.size()];
    getNext(next,s);
    int len = s.size();
    //最长公共前后缀出现在末尾
    if(next[len-1] !=-1 && len %(len - (next[len-1] + 1 )) == 0) {
        return true;
    }
    return false;
}

int main(int argc,char** argv){
    return 0;
}