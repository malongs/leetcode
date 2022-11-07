//三数之和
/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意： 答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]

#思路
重点在于去重，1.首先对数组排序
             2.遍历数组，寻找a,去重
             3. left指针为b,right指针为c;b,c去重，收缩指针。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for(int i =0;i<nums.size();i++) {
        if(nums[i]> 0){
            return result;
        }
        if(i > 0 && nums[i-1]== nums[i]) {//对a去重
            continue;
        }
        int left = i +1;
        int right = nums.size() - 1;
        while (right > left)
        {          
          if(nums[i] + nums[left] + nums[right] > 0) {
            right--;
          }
          else if (nums[i] + nums[left] + nums[right] < 0) {
            left++;
          }
          else{
            result.push_back(vector<int> {nums[i],nums[left],nums[right]});
            while(right > left && nums[right] == nums[right - 1]) right--;//对b和c去重
            while (right > left && nums[left] == nums[left + 1]) left++;
            right--;
            left++;
          }
        }

    }
    return result;
}
int main(int argc,char** argv){
    return 0;
}