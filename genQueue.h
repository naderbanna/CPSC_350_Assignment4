template <class temp>
class genQueue{
  public:
    genQueue();
    genQueue(int maxSize);
    ~genQueue();

    void insert(temp d);
    temp remove();

    temp peek();
    bool isFull();
    bool isEmpty();
    unsigned int getSize();
  private:
    int front;
    int rear;
    int mSize;
    int numElements;

    temp *myQueue;
};

template <class temp>
genQueue<temp>::genQueue(){
  myQueue = new temp [128];
  mSize = 128;
  front = 0;
  rear = 0;
  numElements = 0;
}

template <class temp>
genQueue<temp>::genQueue(int maxSize){
  myQueue = new temp [maxSize];
  mSize = maxSize;
  front = 0;
  rear = 0;
  numElements = 0;
}

template <class temp>
genQueue<temp>::~genQueue(){
  delete myQueue;
}

template <class temp>
void genQueue<temp>::insert(temp d){
  myQueue[rear++] = d;
  rear = (rear) % mSize;
  ++numElements;
}

template <class temp>
temp genQueue<temp>::remove(){
  temp c = '\0';
  c = myQueue[front++];
  front = (front) % mSize;
  --numElements;
  return c;
}

template <class temp>
temp genQueue<temp>::peek(){
  return myQueue[front];
}

template<class temp>
bool genQueue<temp>::isFull(){
  return(numElements == mSize);
}

template <class temp>
bool genQueue<temp>::isEmpty(){
  return (numElements == 0);
}

template <class temp>
unsigned int genQueue<temp>::getSize(){
  return numElements;
}
