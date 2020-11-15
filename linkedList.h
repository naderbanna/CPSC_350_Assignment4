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

};

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
};
