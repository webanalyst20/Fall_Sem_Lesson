#include <iostream>
using namespace std;

class Node
{

public:
int data;
Node* next;
Node* prev;
    Node(int data){
       this-> data = data;
       this -> prev = NULL;
       this -> next = NULL;
    };
   // ~Node();
};

void printList(Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }

    cout<<endl;
    
}

void insertAtHead(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    temp-> prev = temp;
    head = temp;

}

void insertAtTail(Node* &tail,int d){
 Node* temp = new Node(d);
 tail->next = temp;
 temp->prev = tail;
 tail = temp;
}

void insertAtPosition(Node* &tail,Node* &hade,int position,int d){

if(position == 1){
    insertAtHead(hade,d);
    return;
}

Node* temp = hade;
int cnt = 1;
while (cnt < position-1)
{
temp = temp->next;
cnt++;
}

if(temp->next == NULL){
    insertAtTail(tail,d);
    return;
}

Node* nodeToInsert = new Node(d);

 nodeToInsert -> next = temp->next;
 temp -> next -> prev = nodeToInsert;
 temp -> next = nodeToInsert;
 nodeToInsert -> prev = temp ;

}


int main(){
Node* node1 =new Node(10);
Node* head = node1;
Node* tail = node1;
printList(head);
insertAtHead(head,13);
printList(head);
insertAtTail(tail,12);
printList(head);
insertAtPosition(tail,head,4,100);
printList(head);
}
