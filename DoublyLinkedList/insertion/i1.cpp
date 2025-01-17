// 1. insertion at head
#include<iostream>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;

    public:
    Node(int num){
        prev = NULL;
        data = num;
        next = NULL;
    }
};



void insertAtHead(int num,Node* &head,Node* &tail){
// case1: if LL is empty: We are going to create first node
if(head == NULL && tail == NULL){
    //i.e. LL is empty
    Node* newNode = new Node(num);
    head = newNode;
    tail = newNode;
}
else{
// case2: if LL is not empty:
Node* newNode = new Node(num); //step 1: create the node
newNode->next = head; // step2: point the next of newNode to the head
head->prev = newNode;  //step3: point the prev of head to newNode
head=newNode; //step4: update head to newNode
}
}

void print(Node* head){
    Node* temp = head; //new temporary pointer takes constant space it doesnt matter
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void printReverse(Node* tail){
    Node* temp = tail; //new temporary pointer takes constant space it doesnt matter
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->prev;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL; //create head pointer
    Node* tail = NULL; //create tail pointer
    insertAtHead(10,head,tail); //10->NULL
    insertAtHead(20,head,tail); // 20->10->NULL
    insertAtHead(30,head,tail); //30->20->10->NULL
    print(head); //print in forward direction
    printReverse(tail); //print in backward direction
    return 0;
}
