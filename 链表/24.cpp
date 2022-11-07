//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

#include <iostream>
using namespace std;

struct  ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* cur = dummyHead;
    while (cur->next !=nullptr && cur->next->next != nullptr)
    {
      ListNode* tmp = cur->next;
      ListNode* tmp1= cur->next->next;

      cur->next = cur->next->next;
      cur->next->next = tmp;
      cur->next->next->next = tmp1;

      cur =cur->next->next;
    }
    return dummyHead->next;
}


int main(int argc, char** argv) {
    ListNode* head = new ListNode(0);
    ListNode* node = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    head->next = node;
    node->next = node2->next;
    node2->next = node3;
    node3->next = nullptr;

    auto ss= swapPairs(head);
    while (ss !=nullptr)
    {
       cout<<ss->val << endl;
       ss = ss->next;
    }
    return 0;
}


