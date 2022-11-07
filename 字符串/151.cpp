/*
151.翻转字符串里的单词
力扣题目链接(opens new window)

给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：
输入: "the sky is blue"
输出: "blue is sky the"

示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

示例 3：
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
*/
/*
1.移除多余的空格；
2.整个字符串翻转
3.整个单词翻转；
*/
#include <iostream>
using namespace std;
void removeExtraSpaces(string& s){
    int slow = 0;
    for(int fast = 0;fast < s.size();fast++){
     if(s[fast] != ' '){
        if(slow>0 && s[slow]!= ' ') {
          s[slow++]= ' ';
        }
        while (fast < s.size() && s[fast] != ' ')
        {
            s[slow++] = s[fast++];
        }  
     }
    }
    s.resize(slow);
}

void reverse(string &s,int start,int end) {
    for(int i = start,j = end;i < j;) {
        swap(s[i],s[j]);
    }
}

string reverseWords(string &s){
   removeExtraSpaces(s);
   reverse(s,0,s.size()-1);
   int start = 0;
   for(int i = 0; i < s.size();i++){
      if((i == s.size()-1) && (s[i] == ' ')){
        reverse(s,start,i-1);
        start = i + 1;
      }
   
   }
   return s;
}