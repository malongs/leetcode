/*给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1： 输入：nums = [-4,-1,0,3,10] 输出：[0,1,9,16,100] 解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]

示例 2： 输入：nums = [-7,-3,2,3,11] 输出：[4,9,9,49,121] */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//暴力搜索法
vector<int> sortedSquares1(vector<int>& A) {
  for (size_t i = 0; i < A.size(); i++)
  {
    A[i] *= A[i];
  }
  sort(A.begin(),A.end());//快速排序
  return A;
  
}
//双指针
vector<int> sortedSquares2(vector<int>& A) {
  int k = A.size()-1;
  vector<int> result(A.size(),0);
  for(int i=0,j=A.size()-1;i<=j;) {
    if (A[i]*A[i] < A[j]*A[j]) {
        result[k--] = A[j]*A[j];
        j--;
    } else {
        result[k--] = A[i]*A[i];
        i++;
    }
  }
  return result;
}

int main(int argc,char** argv) {
   vector<int> A={-9,-3,9 ,99 ,111};
   auto S =sortedSquares2(A);
   for (vector<int>::iterator it = S.begin();it !=S.end();it++) {
     cout<<*it<<endl;
   }
   return 0;
}