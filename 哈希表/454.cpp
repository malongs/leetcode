/*
第454题.四数相加II
力扣题目链接(opens new window)

给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。

例如:

输入:

A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
输出:

2

解释:

两个元组如下:

(0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
(1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
#思路
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int fourSumCount(vector<int>&A,vector<int>&B,vector<int>&C,vector<int>&D) {
    unordered_map<int,int> unmap; //key为a+b的和，value表示a+b的和出现的次数
    for(int a :A){
        for(int b : B){
            unmap[a+b]++;
        }
    }
    int count = 0;//符合a+b+c+d的元组的
    for(int c : C) {
        for (int d : D)
        {
            if (unmap.find(0-(c+d)) != unmap.end())
            {
                count += unmap[0-(c+d)];
            }
            
        }
        
    }
    return count;
}
int main(int argc,char** argcv) {
    return 0;
}