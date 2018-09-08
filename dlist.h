#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {     
    public: 
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++(){
            this->current=this->current->next;
            return *this;
        };
        DListIterator<T> operator--(){
            this->current=this->current->prev;
            return *this;
        };
};

template <typename Tr>
class DList {     
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Node<T>* tail;
              
    public:
        DList() {
            head = tail = nullptr;
        };

        void push_front(T data) {
            Node<T> *temp = new Node<T>(data);
            temp->data=data;
            if (head)
            {
                temp->next=head;
                temp->prev=head->prev;
                temp->prev->next=temp;
                temp->next->prev=temp;
                head=temp;
            }else{
                head=temp;
                temp->next=head;
                temp->prev=head;
            }
        };

        void push_back(T data) {
            Node<T> *temp = new Node<T>;
            temp->data=data;
            if (head)
            {
                temp->next=head;
                temp->prev=head->prev;
                temp->prev->next=temp;
                temp->next->prev=temp;
            }else{
                head=temp;
                temp->next=head;
                temp->prev=head;   
            }
            
        };
             
        void pop_front() {
            if (head)
            { 
                Node<T> *temp_head;
                head->next->prev=head->prev;
                head->prev->next=head->next;
                temp_head=head->next;
                delete head;
                
                if(head==temp_head){
                    head=nullptr;
                    temp_head=nullptr;
                }else{    
                    head= temp_head;
                    temp_head=nullptr;
                }

            }else{
                //cout<<"lista vacia"<<endl;
            }
            
        };
             
        void pop_back() {
            if (head){
                if(head == head->prev){
                    delete head;
                    head= nullptr;
                }else{
                    Node<T>* temp_prev;
                    temp_prev = head->prev;

                    head->prev->prev->next=head;
                    head->prev=head->prev->prev;
                    delete temp_prev;
                    temp_prev=nullptr;   
                }
            }else{
               // cout<<"lista vacia"<<endl;
            }  
            
        };
             
        iterator begin() {
            return  iterator(head);
        };
             
        iterator end() {
            return iterator(nullptr);
        };
             
        ~DList() {
            if (head) {
                head->killSelf();
            } 
        };         
};

#endif