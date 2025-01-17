// insert at tail
#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    Node(int num){
        data = num;
        prev = NULL;
        next = NULL;
    }
};



void insertAtTail(int num,Node* &head,Node* &tail){

    // case1
    if(head==NULL && tail == NULL){
         Node* newNode = new Node(num);
         head = newNode;
         tail = newNode;
    }
    else{
    Node* newNode = new Node(num); //step1
    tail->next = newNode;//step2
    newNode->prev = tail;//step3
    tail = newNode;//step4

    }
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* tail =NULL;
    Node* head =NULL;
    insertAtTail(10,head,tail); //10->NULL
    insertAtTail(20,head,tail); //10->20->NULL
    insertAtTail(30,head,tail); //10->20->30->NULL
    print(head);
    return 0;
}