/* 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1: 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。

示例 2: 给定 nums = [0,1,2,2,3,0,4,2], val = 2, 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。*/
#include <iostream>
#include <vector>
using namespace std;

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小-1
            }
        }
        return size;

    }
};

//方法一，暴力搜索法
int search(vector<int>& nums,int val) {
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == val)
        {
            for (int j = i + 1; j < size;j++)
            {
                nums[j - 1] = nums[j];
            }
            size --;
            i--;
        }
    }
    return size;
}

//方法二、快慢指针法，
//快指针负责寻找新的数组中元素
//慢指针负责更新下标的位置
int search1(vector<int> &nums,int val) {//同向双指针
  int slow = 0;
  for (int fast =0;fast < nums.size();fast++) {
    if (val != nums[fast]) {
       nums[slow++] =nums[fast];
    }
  }
  return slow;          
}

int search2(vector<int> &nums,int val) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right){
       //先找左边等于val的数
       while (left <= right && nums[left] != val) {
         ++left;
       }
       while (left <= right && nums[right] == val)
       {
         --right;
       }
       while(left <right){
         nums[left++] = nums[right--];
       }
       
    }
    return left;
}

int main(int argv,char** argc) {
    vector<int> nums = {1, 3, 5, 11, 11, 6, 3, 5, 12, 45};
    int val = 5;
    int ret = search(nums,val);
    cout << "ret =" << ret << endl;
    return 0;
}
