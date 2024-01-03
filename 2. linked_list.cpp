#include <iostream>
using namespace std;

class Node
{

public:
   int data;
   Node* next;

Node(int data){
    this -> data = data;
    this ->next = NULL;
}

~Node(){
    int value = this -> data;

    if(this->next != NULL){
        delete next;
        this->next = NULL;
    }

    cout<<"memory is free "<<value<<endl;
}

};

void insertAthead(Node* &hade,int d){
    Node* temp = new Node(d);
    temp ->next =hade;
    hade = temp;
}

void insertAtTail(Node* &tail, int d){
        Node* temp = new Node(d);
        tail ->next = temp;
        tail = temp;
}

void insertAtPosition(Node* &tail,Node* &hade,int position,int d){

if(position == 1){
    insertAthead(hade,d);
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
nodeToInsert->next = temp->next;
temp->next = nodeToInsert;

}

void deletedNode(int position,Node* &hade){

    // delete node

 if(position == 1){
    Node* temp = hade;
    hade = hade->next;
    temp->next = NULL;
    delete temp;
 }else{
    Node* curr = hade;
    Node* prev = NULL;

   int cnt = 1;
   while (cnt < position)
   {
        prev = curr;
        curr = curr->next;
        cnt++;
   }

   prev ->next = curr ->next;
   curr ->next = NULL;
   delete curr;
   

 }


}

void printList(Node* &hade){

 Node* temp = hade;
 while (temp != NULL)
 {
    cout<< temp -> data << " ";
    temp = temp ->next;
 }
 
 cout<<endl;

}

int main() {
 
 Node* node1 = new Node(10);

 Node* hade = node1;
 Node* tail = node1;
 //printList(hade);
 //printList(hade);

//  insertAthead(hade,12);
//  insertAthead(hade,14);

insertAtTail(tail,11);
insertAtTail(tail,12);

insertAtPosition(tail,hade,3,4);

 printList(hade);

 cout<<"hade"<<hade->data<<endl;
 cout<<"tail"<<tail->data<<endl;


 deletedNode(4,hade);
 printList(hade);
 cout<<"hade"<<hade->data<<endl;
 cout<<"tail"<<tail->data<<endl;

  return 0;
}