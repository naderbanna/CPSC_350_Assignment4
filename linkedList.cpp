// #include "linkedList.h"
// #include "listNode.h"

// template <class temp>
// NaiveList<temp>::NaiveList(){
//   front = NULL;
//   back = NULL;
//   size = 0;
// }
// template <class temp>
// NaiveList<temp>:~NaiveList(){
//
// }
//
// template <class temp>
// void NaiveList<temp>::insertFront(temp d){
//   ListNode<temp> *node = new ListNode(d);
//   //we need to update pointer back aswell
//   if(size == 0){
//     back = node;
//   }
//   else{
//     front->prev = node;
//     node->next = front;
//   }
//   front = node;
//   ++size;
// }
//
// template <class temp>
// void NaiveList<temp>::insertBack(temp d){
//   ListNode<temp> *node = new ListNode(d);
//
//   if (front == NULL){
//     front = back;
//   }
//   else{
//     back->next = node;
//     node->prev = back;
//   }
//
//   back = node;
//   ++size;
// }
//
// template <class temp>
// int NaiveList<temp>::removeFront(){
//   ListNode<temp> *node = front;
//   if(front->next == NULL){
//     back = NULL;
//   }
//   else{
//     front->next->prev = 0;
//   }
//
//   front = front->next;
//   --size;
//   node->next = 0;
//   int temp = node->data;
//
//   delete node;
//   return temp;
// }
//
// //remove front and remove back functions
// template <class temp>
// void NaiveList<temp>::printList(){
//   ListNode<temp> *curr = front;
//
//   while(curr != NULL){
//     cout << curr->data << endl;
//     curr = curr->next;
//   }
// }
//
// template <class temp>
// temp NaiveList<temp>::printFront(){
//   return front;
// }
//
// template <class temp>
// int NaiveList<temp>::find(int value){
//   int pos = -1;
//   ListNode<temp> *curr = front;
//
//   while(curr != NULL){
//     ++pos;
//     if(curr->data == value)
//       break;
//
//     curr = curr->next;
//   }
//   //did not find value
//   if(curr == NULL)
//     pos = -1;
//
//   return pos;
// }
//
// template <class temp>
// int NaiveList<temp>::deletePos(int pos){
//   int p = 0;
//   ListNode<temp> *curr = front;
//   ListNode<temp> *prev = front;
//   //iternate to the position
//   while(p != pos){
//     //iterate and update my pointers
//     prev = curr;
//     curr = curr->next;
//     p++
//   }
//   //we found our target, all pointers should be in the correct location
//   prev->next = curr->next;
//   curr->next = NULL;
//   int temp = curr->data;
//   size--;
//
//   delete curr;
//   return temp;
//
//   //try drawing this
// }
