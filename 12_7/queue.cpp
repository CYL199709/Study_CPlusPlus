//queue.cpp 
#include"queue.h"
#include<cstdlib>  // for rand()

//Queue 方法
//qsize初始化为qs,因为qsize是const型，用成员初始化列表（只有构造函数可以用）
Queue::Queue(int qs):qsize(qs){
    front = rear = NULL;
    items = 0;
}

Queue::~Queue(){
    Node *temp;
    while(front!=NULL){
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const{
    return items==0;
}

bool Queue::isfull() const{
    return items==qsize; 
}

int Queue::queuecount() const{
    return items;
}

bool Queue::enqueue(const Item & item){
    if(isfull()) return false;
    Node* add = new Node;
    add->item = item;
    add->next = NULL;
    items++;
    if(front == NULL) front = add;
    else rear->next = add;
    rear = add;
    return true;
}

bool Queue::dequeue(Item & item){
    if(front==NULL) return false;
    item = front->item;
    items--;
    Node *temp= front;
    front = front->next;
    delete temp;
    if(items==0) rear = NULL;
    return true;
}

void Customer::set(long when){
    processtime = std::rand() %3 +1;
    arrive = when;
}

