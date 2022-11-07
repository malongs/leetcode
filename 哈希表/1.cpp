/*
首先我在强调一下 什么时候使用哈希法，当我们需要查询一个元素是否出现过，或者一个元素是否在集合里的时候，就要第一时间想到哈希法。

本题呢，我就需要一个集合来存放我们遍历过的元素，然后在遍历数组的时候去询问这个集合，某元素是否遍历过，也就是 是否出现在这个集合
*/

/*
再来看一下使用数组和set来做哈希法的局限。

数组的大小是受限制的，而且如果元素很少，而哈希值太大会造成内存空间的浪费。
set是一个集合，里面放的元素只能是一个key，而两数之和这道题目，不仅要判断y是否存在而且还要记录y的下标位置，因为要返回x 和 y的下标。所以set 也不能用。
*/
/*
key表示数组的元素，value表示下标
遍历数组，find  target-nums[i]是否出现在unordered_map中，出现了就返回，没出现就insert
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using  namespace std;
vector<int> sumTwo(vector<int> nums,int target) {
    unordered_map<int,int> result;
    for(int i =0; i < nums.size();i++) {
      unordered_map<int,int>::iterator  it = result.find(target - nums[i]);
      if(it != result.end()){
        return {it->second,i};
      }
      result.insert(pair<int,int>(nums[i],i));
    }
    return {};
}

int main(int argc,char** argv) {
    return 0;
}