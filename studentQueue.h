class studentQueue{
  public:
    studentQueue();
    studentQueue(int maxSize);
    ~studentQueue();

    void insert(char d);
    char remove();

    char peek();
    bool isFull();
    bool isEmpty();
    unsigned int getSize();
  private:
    int front;
    int rear;
    int mSize;
    int numElements;

    char *myQueue;
}
