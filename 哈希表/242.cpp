/*242.有效的字母异位词 (字符串中字符出现的次数和个数相同)
力扣题目链接(opens new window)

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1: 输入: s = "anagram", t = "nagaram" 输出: true

示例 2: 输入: s = "rat", t = "car" 输出: false

说明: 你可以假设字符串只包含小写字母。*/

//索引表示26个字母
//元素代表每个字母出现的字数


#include <iostream>
using namespace std;
bool isAnagram(string s,string t) {
    int record[26] = {0};
    for (int i = 0; i < s.size();i++) {
      record[s[i] - 'a']++; //记录下每个字母出现的次数
    }

    for (int j = 0; j < t.size();j++) {
        record[t[j] - 'a']--;  //查找
    } 
    for (int i = 0; i < 26;i++) {
        if(record[i] != 0) {
            return false;
        }
    }
    return true;
}

int main(int argc ,char** argv) {
    
    return 0;
}
// namespace std;





