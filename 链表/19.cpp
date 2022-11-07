/*给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点*/
#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head,int n) {
   ListNode* dummyNode = new ListNode(0);
   dummyNode->next = head;
   ListNode* fast = dummyNode;
   ListNode* slow = dummyNode;
   while (n-- && fast != nullptr)//保证n有效
   {
     fast = fast->next;
   }
   fast = fast->next;
   while (fast != nullptr)
   {
     fast = fast->next;
     slow = slow->next;
   }
   slow->next = slow->next->next;
   return dummyNode->next;
}

int main(int agrc,char** agrv) {
    return 0;
}