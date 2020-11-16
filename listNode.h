#include <iostream>
using namespace std;

template <class temp>
class ListNode{
  public:
    ListNode();
    ListNode(temp d);
    ~ListNode();

    temp data;
    ListNode *next;
    ListNode *prev;

};

template <class temp>
ListNode<temp>::ListNode(){
}

template <class temp>
ListNode<temp>::ListNode(temp d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <class temp>
ListNode<temp>::~ListNode(){
}
