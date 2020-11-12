#include "studentQueue.h"

studentQueue::studentQueue(){
  myQueue = new char [128];
  mSize = 128;
  front = 0;
  rear = 0;
  numElements = 0;
}

studentQueue::studentQueue(int maxSize){
  myQueue = new char [maxSize];
  mSize = maxSize;
  front = 0;
  rear = 0;
  numElements = 0;
}

studentQueue:~studentQueue(){
  delete myQueue;
}

studentQueue::insert(char d){
  myQueue[rear++] = d;
  rear = (rear) % mSize;
  ++numElements;
}

char studentQueue::remove(){
  char c = '\0';
  c = myQueue[front++];
  front = (front) % mSize;
  --numElements;
  return c;
}

char studentQueue::peek(){
  return myQueue[front];
}

bool studentQueue::isFull(){
  return(numElements == mSize);
}

bool studentQueue::isEmpty(){
  return (numElements == 0);
}

unsigned int studentQueue::getSize(){
  return numElements;
}
