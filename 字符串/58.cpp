/*
题目：剑指Offer58-II.左旋转字符串
力扣题目链接(opens new window)

字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

示例 1：
输入: s = "abcdefg", k = 2
输出: "cdefgab"

示例 2：
输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"

限制：
1 <= k < s.length <= 10000

#思路
1.首先翻转前n个字符串；
2.再翻转n到结尾的字符串；
3.再整体翻转整个字符串
*/
#include <iostream>
#include <algorithm>
using namespace std;
string reverseLeftWords(string s,int n){
    reverse(s.begin(),s.begin()+n);
    reverse(s.begin()+n,s.end());
    reverse(s.begin(),s.end());
    return s;
}
int main(int argc,char** argv) {
    string s = "15erty";
    int n = 3;
    auto ret = reverseLeftWords(s,3);
    std::cout<<"ret = " << ret << std::endl;
    return 0;
}