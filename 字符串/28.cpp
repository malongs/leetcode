/*
28. 实现 strStr()
力扣题目链接(opens new window)

实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
示例 1: 输入: haystack = "hello", needle = "ll" 输出: 2

示例 2: 输入: haystack = "aaaaa", needle = "bba" 输出: -1

说明: 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/

//构建next数组的思路
/*
i表示后缀的末尾位置；
j表示前缀的末尾位置，j的值等于next[i]的值，表示子串的最长公共前后缀的长度

1.初始化；
2.处理前后缀不相同的情况；
3.处理前后缀相同的情况；
4.更新next数组
*/

#include <iostream>
using  namespace std;

//next数组从 -1开始
void getNext(int* next,const string& s) {
    int j = -1;
    next[0] = j;
    for(int i = i;i < s.size();i++) {
        while (j >= 0 && s[j + 1] != s[i]) {
            j = next[j];
        }
        if(next[i]== next[j+1]) {
            j++;
        }
        next[i] = j;  
    }

}

int strstr(string haystack,string needle) {
    if(needle.size()==0){
        return 0;
    }
    int next[needle.size()];
    getNext(next,needle);
    int j = -1;
    for(int i =0;i < haystack.size();i++) {
        while (j>=0 && haystack[i] != needle[j+1])
        {
            j = next[j];
        }
        if(haystack[i]==needle[j + 1]){
            j++;
        }
        if(j==(needle.size()-1)){
            return(i - needle.size() + 1);
        }
        
    }
    return -1;
}
int main(int argc,char** argv) {
    return 0;
}