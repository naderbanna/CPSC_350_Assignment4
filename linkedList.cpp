#include <iostream>
using namespace std;

template <class temp>
class ListNode{
  public:
    ListNode();
    ListNode(temp d);
    ~ListNode();
    //maybe a temp type?
    temp data;
    ListNode *next;
    ListNode *prev;

}

//sperate file .cpp
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
ListNode<temp>:~ListNode(){
//research what goes here, prob all garbage collection
}

//seperate file . h file for my single linked List

template <class temp>
class NaiveList{
  private:
    ListNode *front;
    ListNode *back;
    unsigned int size;
  public:
    NaiveList();
    ~NaiveList();
    void insertFront(temp d);
    void insertBack(temp d);
    int removeFront();

    int find(temp value);
    //int deletePos(int pos);
    int removeNode(int key);

    void printList();
    bool isEmpty();
    unsigned int getSize();
}

//seperate file .cpp implementation
template <class temp>
NaiveList<temp>::NaiveList(){
  front = NULL;
  back = NULL;
  size = 0;
}
template <class temp>
NaiveList<temp>:~NaiveList(){
  //builds some character, research
}
template <class temp>
void NaiveList<temp>::insertFront(temp d){
  ListNode *node = new ListNode(d);
  //we need to update pointer back aswell
  if(size == 0){
    back = node;
  }
  else{
    front->prev = node;
    node->next = front;
  }
  front = node;
  ++size;
}

template <class temp>
void NaiveList<temp>::insertBack(temp d){
  ListNode *node = new ListNode(d);

  if (front == NULL){
    front = back;
  }
  else{
    back->next = node;
    node->prev = back;
  }

  back = node;
  ++size;
}

template <class temp>
int NaiveList<temp>::removeFront(){
  ListNode *node = front;
  if(front->next == NULL){
    back = NULL;
  }
  else{
    front->next->prev = 0;
  }

  front = front->next;
  --size;
  node->next = 0;
  int temp = node->data;

  delete node;
  return temp;
}

//remove front and remove back functions

template <class temp>
void NaiveList<temp>::printList(){
  ListNode *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class temp>
int NaiveList<temp>::find(int value){
  int pos = -1;
  ListNode *curr = front;

  while(curr != NULL){
    ++pos;
    if(curr->data == value)
      break;

    curr = curr->next;
  }
  //did not find value
  if(curr == NULL)
    pos = -1;

  return pos;
}

template <class temp>
int NaiveList<temp>::deletePos(int pos){
  int p = 0;
  ListNode *curr = front;
  ListNode *prev = front;

  //iternate to the position
  while(p != pos){
    //iterate and update my pointers
    prev = curr;
    curr = curr->next;
    p++
  }

  //we found our target, all pointers should be in the correct location
  prev->next = curr->next;
  curr->next = NULL;
  int temp = curr->data;
  size--;

  delete curr;
  return temp;

  //try drawing this
}
