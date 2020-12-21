// stack.h --ADT Stack的类定义
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack {
   private:
    enum { MAX = 10 };  //可参照10.6.2
    Item items[MAX];
    int top; //栈顶元素的index

   public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    // push() 如果stack已满，返回false,否则true
    bool push(const Item& item);
    // pop() 如果stack已空，返回false,否则true
    bool pop(Item& item);
};

#endif