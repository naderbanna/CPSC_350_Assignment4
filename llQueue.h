#include "linkedList.h"
using namespace std;

template <class temp>
class llQueue{
  public:
    llQueue();
    llQueue(int maxSize);
    ~llQueue();

    void insert(temp d);
    void remove();

    temp peek();
    bool isEmpty();
    unsigned int getSize();
  private:
    int numElements;
    NaiveList<temp> *queue = new NaiveList<temp>;

};

template <class temp>
llQueue<temp>::llQueue(){
  numElements = 0;
}

template <class temp>
llQueue<temp>::~llQueue(){

}

template <class temp>
void llQueue<temp>::insert(temp d){
  if(!isEmpty()){
    queue->insertBack(d);
  }
  else{
    queue->insertFront(d);
  }
  ++numElements;
}

template <class temp>
void llQueue<temp>::remove(){
  queue->removeFront();
  --numElements;
}

template <class temp>
temp llQueue<temp>::peek(){
  queue->printFront();
}


template <class temp>
bool llQueue<temp>::isEmpty(){
  return (numElements == 0);
}

template <class temp>
unsigned int llQueue<temp>::getSize(){
  return numElements;
}
