/*题意： 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。*/

#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(nullptr) {}
};

ListNode* detectCircle(ListNode* head) {
  ListNode* fast = head;
  ListNode* slow = head;
  while (fast != nullptr && fast->next != nullptr)
  {
    fast = fast->next->next;
    slow = slow->next;
    if(slow == fast) {
        ListNode* index1 = fast;
        ListNode* index2 = head;
        while (index1 != index2)
        {
          index1 = index1->next;
          index2 = index2->next;
        }
        return index2;
    }
  }
  return nullptr;
   
}
int main(int argc,char** argv) {

}
