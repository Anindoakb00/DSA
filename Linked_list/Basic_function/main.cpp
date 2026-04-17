#include <iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* next; // pointer to the next node


        Node(int val){
            data = val; // store the node value
            next = NULL; // initialize as last node
    }
};
    class List{
        Node* head;
        Node* tail;

    public:
        List(){
                        head = tail = NULL; // start with an empty list
        }
        void push_front(int val){
                    Node* newNode = new Node(val); // create a new node
                    if(head ==NULL){
                        head = tail = newNode; // first node becomes both head and tail
            return;
          }else{
                        newNode ->next = head; // link new node to current head
                        head = newNode; // move head to new node
          }
        }
        void push_back(int val){
                        Node* newNode = new Node(val); // create a new node
            if(head == NULL){
                                head = tail = newNode; // first node becomes both head and tail
            }else{
                                tail->next = newNode; // attach node after current tail
                                tail = newNode; // update tail to new last node
            }
        }
        void pop_front(){
            if(head ==NULL){
                cout << "List is empty.";
                return;
                
            }
                Node* temp = head; // keep old head to delete safely
                head = head->next; // move head to next node
                temp->next = NULL; // detach old head from list
                delete temp; // free removed node memory
            

        }
        void pop_back(){
                if (head ==NULL) // cannot remove from an empty list
         {
            cout << "List is empty.:";
            return;
         }
            Node* temp = head; // start from head to find node before tail
            while(temp-> next !=tail){
                temp = temp->next; // move until previous-to-tail node
         }
            temp->next = NULL; // new tail should point to null
            delete tail; // free old tail node memory
            tail = temp; // update tail pointer
         
        }
        void insert(int pos, int val){
            if (pos <0){
                cout <<"Invalid position.";
                return;
            }if(pos ==0){
                push_front(val);
                return;
            }
            Node* newNode = new Node(val);
            Node* temp = head;
            for( int i =0; i < pos-1;i++){
                if(temp == NULL){
                    cout << "Position out of bounds.";
                    return;
                }
                temp = temp->next;


            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        void printLL(){
                        Node* temp = head; // start traversal from head
            while(temp != NULL){
                                cout << temp->data << "-"; // print current node data
                                temp = temp->next; // move to next node
            }
            cout << endl;
        }
            int search(int key){
                Node* temp = head;
                int idx =0;
                while(temp != NULL){
                    if(temp-> data == key){
                        return idx; 

                    } temp = temp-> next;
                    idx++;
                }
                return -1; // key not found
            }
        
    };
    int main(){
        List ll; ll.push_front(1);ll.push_front(2);ll.push_front(2); // insert at front
        ll.push_back(2); // insert at back
        ll.push_back(3); // insert at back
        ll.push_back(4); // insert at back
        ll.printLL();
        ll.pop_front(); // remove first node
        ll.pop_back();
        ll.printLL(); ll.insert(3,2);ll.printLL(); cout <<ll.search(4)<<endl;return 0;// print list and exit
    }
            




   

