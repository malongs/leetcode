/*题意：删除链表中等于给定值 val 的所有节点。

示例 1：
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]

示例 2：
输入：head = [], val = 1
输出：[]

示例 3：
输入：head = [7,7,7,7], val = 7
输出：[]
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr) {}
};

//带头结点的写法
ListNode* removeElement(ListNode* head,int val) {
//删除头结点
  while(head !=nullptr && head->val==val) {
    ListNode* tmp = head;
    head = head->next;
    delete tmp;
  }

  ListNode* cur = head;
  while (cur != nullptr && cur->next !=nullptr)
  {
    if(cur->next->val ==val){
      ListNode* tmp = cur->next;
      cur->next=cur->next->next;
      delete tmp;
    } else {
      cur=cur->next;
    }
  }
  return head;
}

//设置带虚拟头结点的写法
ListNode* removeElement2(ListNode* head,int val) {
  ListNode* dummyHead =new ListNode(0);
  dummyHead->next = head;//为链表添加虚拟头结点
  ListNode* cur = dummyHead;
  while (cur->next != nullptr)
  {
    if (cur->next->val == val) {
      ListNode* tmp = cur->next;
      cur->next = cur->next->next;
      delete tmp;
    } else {
      cur = cur ->next;
    }
  }
  head = dummyHead ->next;
  delete dummyHead;
  return head;
}
int main(int argc,char** argv) {
  ListNode* head = new ListNode(10);
  ListNode* node1 = new ListNode(101);
  ListNode* node2 = new ListNode(102);
  ListNode* node3 = new ListNode(102);
  ListNode* node4 = new ListNode(103);

  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = nullptr;

  ListNode* cur = removeElement2(head,102);
  while (cur != nullptr) {
    cout<< cur->val <<std::endl;
    cur = cur->next;
    
  }
  

  delete node4;
  // delete node3;
  // delete node2;
  // delete node1;
  // delete head;

    
  return 0;
}
