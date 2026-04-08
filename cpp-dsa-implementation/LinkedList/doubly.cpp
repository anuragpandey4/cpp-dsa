#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int value){
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};


class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
    
        void printList() {
            if(length == 0) cout<<"Empty List"<<endl;
            Node *temp = head;
            while(temp) {
                cout<<"<- "<<temp->value<<" -> ";
                temp = temp->next;
            }
            cout<<endl;
        }

         int getHead() {
            if(head) return head->value;
            return -1;
        }

        int getTail() {
            if(tail) return tail->value;
            return -1;
        }

        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if(head == nullptr) {
                head = newNode;
                tail = newNode;
            }else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }

            length++;
        }

        void deleteLast() {
            if(length == 0) return;

            Node* temp = tail;
            if(head == tail) {
                head = nullptr;
                tail = nullptr;
            }else {
                tail = tail->prev;
                tail->next = nullptr;
            }
            
            delete temp;
            length--;
        }

        void prepend(int value) {
            Node* newNode = new Node(value);
            
            if(length == 0) {
                head = newNode;
                tail = newNode;
            }else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }

            length++;
        }
        
        void deleteFirst(){
            if (length == 0) return;

            Node* temp = head;
            if(length == 1) {
                head = nullptr;
                tail = nullptr;
            }else {
                head = head->next;
                head->prev = nullptr;
            }

            delete temp;
            length--;
        }

        Node* get(int index){
            if(index < 0 || index >= length) return nullptr;

            Node* temp;
            if(index < length/2) {
                temp = head;
                for(int i = 0; i < index;i++) {
                    temp = temp->next;
                }
            }else {
                temp = tail;
                for(int i = length-1; i > index; i--){
                    temp = temp->prev;
                }
            }
            return temp;
        }
};

int main() {

    DoublyLinkedList* dll = new DoublyLinkedList(33);
    dll->append(334);
    dll->append(2);
    dll->append(19);
    
    Node* node = dll->get(2);
    cout<<node->value;


    return 0;
}