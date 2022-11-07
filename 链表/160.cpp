/*给你两个单链表的头节点 headA 和 headB ，
请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null */

#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  ListNode* curA = headA;
  ListNode* curB = headB;
  int lengthA=0,lengthB=0;
  while (curA !=NULL)
  {
    lengthA++;
    curA = curA->next;
  }
  while (curB !=NULL)
  {
    lengthB++;
    curB = curB->next;
  }
  curA = headA;
  curB = headB;
  if (lengthA > lengthB)
  {
    swap(lengthA,lengthB);
    swap(curA,curB);
  }
  int gap = lengthA - lengthB;
  while (gap--)
  {
    curA=curA->next;
  }
  while (curA != nullptr)
  {
    if(curA == curB){
        return curA;
    }
    curA=curA->next;
    curB=curB->next;
  }
  return nullptr;
  
}


int main(int argc,char** argv) {

    return 0;
}


