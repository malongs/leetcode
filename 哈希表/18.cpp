//四数之和
/*题意：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例： 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。 满足要求的四元组集合为： [ [-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2] ]
*/
//#思路
//-4 -1 0 0 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums,int target) {
  vector<vector<int>>  result;
  sort(nums.begin(),nums.end());
  for(int k = 0;k <nums.size();k++) {
    if(nums[k]>target && nums[k] >= 0) {
      return result;
    }
    if(k >0 && nums[k] == nums[k-1]) {
      break;
    }
    for(int i = k + 1;i < nums.size();i++) {
        if(nums[k] + nums[i] > target &&  nums[k] + nums[i] >= 0) {
          return result;
        }
        if(i > k +1 && nums[i] == nums[i-1]) {
          break;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while (right > left)
        {
          if(nums[k]+nums[i] + nums[left] + nums[right] > target) {
            right--;
          }
          else if(nums[k]+nums[i] + nums[left] + nums[right] < target) {
            left--;
          }
          else {
            result.push_back(vector<int>{nums[k],nums[i],nums[left],nums[right]});
            if(right > left && nums[right] == nums[right-1]) {
              right--;
            }
            if(right > left && nums[left] == nums[left-1]) {
              left++;
            }
          }
          right++;
          left--;
        }
    }
  }
  return result;
}
int main(int argc,char* argv[]) {
    return 0;
}

