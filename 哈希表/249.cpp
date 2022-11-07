/*题意：给定两个数组，编写一个函数来计算它们的交集*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//如果哈希值比较少、特别分散、跨度非常大，使用数组就造成空间的极大浪费！
vector<int> intersection(vector<int> nums1,vector<int>nums2) {
    unordered_set<int> result;
    unordered_set<int> nums_set(nums1.begin(), nums1.end());
    for (int num : nums2) {
      if(nums_set.find(num) != nums_set.end()){
        result.insert(num);
      }    
    }
    return vector<int>(result.begin(), result.end());
}
int main(int argc,char** argv) {
  return 0;
}