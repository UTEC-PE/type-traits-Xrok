#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : 
public Iterator<T> {     
    public: 
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++(){
            this->current=this->current->next;
            return *this;
        };
};

template <typename Tr>
class SList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Operation cmp;
              
    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
            pointer=&head;
            while(*pointer && cmp(search,(*pointer)->data)){
                
                if(search == (*pointer)->data){
                    return true;
                }
                pointer = &((*pointer)->next);
            }
            return false;
        }
             
        bool insert(T data) {
            Node<T> **pointer;
            //pointer=&head;
            if(!find(data,pointer)){
                Node<T>* nuevo_nodo = new Node<T>(data);
                nuevo_nodo->next=*pointer;
                (*pointer)= nuevo_nodo;
                return true;
            }else{
                return false;
            }
            
        }
             
        bool remove(T item) {
           Node<T>* temp;
           Node<T> **pointer;
           
           if(find(item,pointer)){

           temp=*pointer;
           (*pointer)=(*pointer)->next;
           delete temp;
           return true;
           }else{
            return false;
           }

        }  
             
        iterator begin() {
            return  iterator(head);
        }
             
        iterator end() {
            return iterator(nullptr);
        }
             
        ~SList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif