#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int value;
        Node *next;
    
    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

class LinkedList{
    private:
        Node *head;
        Node *tail;
        int length;

    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        LinkedList(int value){
            Node *newNode = new Node(value);
            head=newNode;
            tail=newNode;
            length=1;
            cout<<"Linked List is created with head value: "<<head->value <<endl;
        }

        void printList() {
            Node *temp = head;
            while(temp) {
                cout<<temp->value<<" -> ";
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

            if(!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            
            length++;
        }

        void prepend(int value) {
            Node* newNode = new Node(value);

            if(!head) {
                head = tail = newNode;
            }else {
                newNode->next = head;
                head = newNode;
            }

            length++;
        }


        void deleteLast() {
            if(!tail) {
                return;
            }
            
            if(head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }else {
                Node * temp = head;
                while(temp->next != tail) {
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }

            length--;
        }

        void deleteFirst() {
            if(!head) return;

            Node* temp = head;
            head = head->next;
            delete temp;
            length--;

            if(length == 0) {
                tail = nullptr;
            }
        }

        Node* get(int index) {
            if(index < 0 || index >= length){
                return nullptr;
            }

            Node* temp = head;
            for(int i = 0; i<index;i++){
                temp = temp->next;
            }

            return temp;
        }

        bool set(int index,int value) {
            Node* temp = get(index);
            if(temp ){
                temp->value=value;
                return true;
            }
            return false;
        }

        bool insert(int index, int value) {
            if(index < 0 || index > length) return false;

            if(index == 0) {
                prepend(value);
                return true;
            }

            if(index == length) {
                append(value);
                return true;
            }

            Node * newNode = new Node(value);
            Node* temp = get(index - 1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }

        void deleteNode(int index) {
            if (index < 0 || index >= length) return;
            if (index == 0) return deleteFirst();
            if (index == length-1) return deleteLast();

            Node* prev = get(index - 1);
            Node* temp = prev->next;
            prev->next = temp->next;
            delete temp;
            length--;
        }

        void reverse() {
            Node* temp = head;
            head = tail;
            tail = temp;

            Node* prev = nullptr;
            Node* after = temp->next;

            for(int i = 0; i < length; i++) {
                after = temp->next;
                temp->next=prev;
                prev = temp;
                temp = after;
            }
        }

        ~LinkedList() {
            Node* temp = head;
            while(head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
};


int main() {
    
    LinkedList *myList = new LinkedList(12);
    myList->append(14);
    myList->append(33);
    myList->append(338);
    myList->prepend(1);


    

    

    cout<<endl;
    myList->printList();

    // myList->set(4,39);
    // myList->insert(0,2);
    // myList->insert(6,22);
    // myList->insert(3,45);

    // myList->deleteNode(2);

    myList->reverse();
  

    myList->printList();

    cout << endl;
    cout<<"Head: "<<myList->getHead()<<endl;
    cout<<"Tail: "<<myList->getTail()<<endl;
    cout <<"Length: "<<myList->getLength()<<endl;
    return 0;
}