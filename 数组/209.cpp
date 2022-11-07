/*给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。
如果不存在符合条件的子数组，返回 0。

示例：

输入：s = 7, nums = [2,3,1,2,4,3] 输出：2 解释：子数组 [4,3] 是该条件下的长度最小的子数组。*/

#include <vector>
#include <iostream>
using namespace std;

//暴力搜索法
int minSubArrayLen1(int s,vector<int>& nums) {
    int result = INT32_MAX;//最终结果
    int sum =0;
    int subLength = 0;
    for(int i=0;i<nums.size();i++) {
       sum = 0 ;  
       for(int j=i;j<nums.size();j++) {
        sum +=nums[j];
        if (sum >= s) {
          subLength = j - i + 1;
          result = result <= subLength ? result : subLength;
          break;
        }
       }

    }   

    return result == INT32_MAX ? 0 : result;
}

//滑动窗口
int minSubArrayLen1(int s,vector<int>& nums) {
  int result = INT32_MAX;
  int i= 0; //滑动窗口的起始位置
  int sum = 0;
  int subLenght = 0;
  for (int j =0; j< nums.size();j++){
    sum += nums[j];
    while (sum >= s) {
       subLenght = j - i + 1;  
       result = result <= subLenght ? result : subLenght;
       sum -=nums[i++];//不断变更子序列的起始位置
    } 
  }
  return result ==INT32_MAX ? 0 : result;
}

int main(int argc,char** argv) {

    return 0;
}
