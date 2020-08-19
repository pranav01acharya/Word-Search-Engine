//Paritosh Jha and Pranav Acharya
//Feb 10 2020
#ifndef DNODE_H
#define DNODE_H
template <class Item>
class dnode{
    private:
        dnode* next;
        dnode* prev;
        Item obj;
    public:
        dnode();
        dnode(Item& obj);
        //~dnode(); might need destructor
        dnode*& getNext();
        void setNext(dnode* temp);
        dnode*& getPrev();
        void setPrev(dnode* temp);
        Item& getObj();
        void setObj(Item& obj);
};
template <class Item>
dnode<Item>::dnode()
{
    next = nullptr;
    prev = nullptr;
}

template <class Item>
dnode<Item>::dnode(Item& obj)
{
    this->obj = obj;
    next = nullptr;
    prev = nullptr;
}

template <class Item>
dnode<Item>*& dnode<Item>::getNext()
{
    return next;
}
template<class Item>
void dnode<Item>::setNext(dnode<Item>* temp)
{
    next = temp;
}


template <class Item>
dnode<Item>*& dnode<Item>::getPrev()
{
    return prev;
}
template<class Item>
void dnode<Item>::setPrev(dnode<Item>* temp)
{
    prev = temp;
}
template<class Item>
Item& dnode<Item>::getObj()
{
    return obj;
}

template <class Item>
void dnode<Item>::setObj(Item& obj)
{
    this-> obj = obj;       //may need to change because of assignment operator issues 
}


template <class Item>
void swap(dnode<Item>*& prev, dnode<Item>*& current)
{
    //cout<<prev->getObj().getString()<< " swapping with " << current->getObj().getString()<<endl;
    Item x = prev->getObj();
    prev->setObj(current->getObj());
    current->setObj(x);
    //cout<<prev->getObj().getString() <<" and " <<current->getObj().getString()<<endl;
}
#endif
/*
template <class Item>
void swap(dnode<Item>*&head,dnode<Item>*& tail,dnode<Item>* front, dnode<Item>* back)
{
    if (front->getPrev() == nullptr && back->getNext() == nullptr)
    {
        back->setPrev(nullptr);
        front->setNext(nullptr);
        back->setNext(front);
        front->setPrev(back);
        head = back;  
        tail = front;  

    }
    else if (front->getPrev() == nullptr)
    {
        front->setNext(back->getNext());
        back->getNext()->setPrev(front);
        back->setNext(front);
        back->setPrev(nullptr);
        front->setPrev(back);
        head = back;
    }

    else if (back->getNext() == nullptr)
    {
        back->setPrev(front->getPrev());
        front->getPrev()->setNext(back);
        front->setPrev(back);
        back->setNext(front);
        front->setNext(nullptr);
        tail = front;
    }
    else{

        front->getPrev()->setNext(back);
        front->setNext(back->getNext());
        back->getNext()->setPrev(front);
        back->setPrev(front->getPrev());
        front->setPrev(back);
        back->setNext(front);
    }

}
*/

