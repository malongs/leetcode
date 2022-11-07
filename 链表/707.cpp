/*
在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点
*/
#include <iostream>
using namespace  std;

class MyLinkedList {
public:
 struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
 };
 
 //初始化链表
 MyLinkedList() {
   m_dummyHead = new ListNode(0);
   m_size = 0;
 }

int get(int index) {
    if (index > (m_size -1) || index < 0) {
        return -1;
    }

    ListNode* cur = m_dummyHead->next;
    while (index--){
        cur = cur ->next;
    } 
    return cur->val;
}

//在第一个元素前添加一个值为val的节点
void addAtHead(int val) {
  ListNode* newLinkNode = new ListNode(val);
  newLinkNode ->next = m_dummyHead->next;//注意顺序
  m_dummyHead ->next = newLinkNode;
  m_size++;
}

//  将值为val的元素添加到链表的最后
void addAtTail(int val) {
  ListNode* newLinkNode = new ListNode(val);
  ListNode* cur = m_dummyHead->next;
  while (cur->next !=nullptr) {
    cur = cur->next;
  }
  cur->next = newLinkNode;
  m_dummyHead++;
}

// 在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。
//如果 index 大于链表长度，则不会插入节点。
//如果index小于0，则在头部插入节点。
void addAtIndex(int index,int val) {
  if ( index > m_size || index < 0) {
    return ;
  }   
  ListNode* newLinkNode = new ListNode(val);
  ListNode* cur = m_dummyHead;
  while (index--) {
    cur = cur->next;
  }
  newLinkNode->next = cur->next;
  cur->next= newLinkNode;
  m_dummyHead++; 
}

//添加了虚拟节点，index从0开始
void deleteAtIndex(int index) { 
  if (index >= m_size || index < 0) {
     return;
  }
  ListNode* cur = m_dummyHead;
  while (index--)
  {
    cur = cur->next;
  }
  ListNode* tmp = cur->next;
  cur->next = cur->next->next;
  m_size--;
}

//打印链表
void ListPrint(ListNode* head) {
  ListNode* cur = m_dummyHead;
  while (cur->next != nullptr)
  {
    cout<<cur->next->val;
    cur=cur->next;
  }
  cout<<endl;
}
public:
 ListNode* m_dummyHead;
 int m_size;

};


int main(int argc, char** argv) {


    return 0;
}
