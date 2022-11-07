//二分法查找
/*给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。*/

// 版本一

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    /*int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }*/
    int search(vector<int>& nums,int target) {  //[left,right]左闭右开区间
      int left = 0;
      int right = nums.size() - 1;
      while (left <= right){
        //int middle = (left + right) / 2;
        int middle = left + ((right - left) / 2);//防溢出的写法，防止越界的写法。
        if (nums[middle] > target)
        {
            right = middle - 1;
        }
        else if (nums[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
      }
    }
    
    //版本二
    int search2(vector<int>& nums,int target) {  //[left,right)左闭右开区间,右区间取不到
      int left = 0;
      int right = nums.size();
      while (left < right)
      {
          int middle = left + ((right - left) / 2);
        if(nums[middle] > target) {
            right = middle;
        }
        else if (nums[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
      }
    }
};

int main(int argc, char** argv) {
    Solution init;
    vector<int> nums = {1, 6, 7, 19, 100};
    int target = 7;

    int ret = init.search(nums, target);
    std::cout << "ret = " << ret << std::endl;
    return 0;
}