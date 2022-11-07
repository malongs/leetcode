//反转单链表
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(nullptr) {}
};

//双指针法
ListNode* reverseList(ListNode* head) {
  ListNode* tmp = nullptr;
  ListNode* cur = head;
  ListNode* pre = nullptr;
  while (cur != nullptr)
  {
     tmp = cur->next;
     cur->next = pre;

     pre =cur;
     cur = tmp;
  }
  return pre;
}

//递归法  从前往后翻转
ListNode* reverse(ListNode* pre,ListNode* cur) {
    if(cur==nullptr) {
        return pre;
    }
    ListNode* tmp = cur->next;
    cur->next = pre;
    return reverse(pre,cur);
}

ListNode* reverseList(ListNode* head) {
  return reverse(NULL,head);
}


//递归调用，从后往前翻转
ListNode* reverseList2(ListNode* head) {
    if(head ==nullptr) {return nullptr;}
    if(head->next==nullptr) {return head;}
    
    ListNode* last = reverseList2(head->next);
    head->next->next = head;
    head->next = nullptr;

    return last;
}

int main(int argc,char** argv) {
 ListNode* head = new ListNode(0);
 ListNode* node1 = new ListNode(1);
 ListNode* node2 = new ListNode(2);
 ListNode* node3 = new ListNode(2);
 
 head->next = node1;
 node1->next = node2;
 node2->next = node3;
 node3->next = nullptr;

 ListNode* cur = reverseList(head);

 while (cur!= nullptr)
 {
    cout<<cur->val<<endl;
    cur = cur->next;
 }
 delete head;  
 return 0;
}
