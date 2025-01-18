// insert at any position 
#include<iostream>
using namespace std;

class Node{
public:    
    int data;
    Node* prev;
    Node* next;

public:
Node(int num){
    prev = NULL;
    data = num;
    next = NULL;
}    
};

int getLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    } 
    return count;
}

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

void insertAtAnyPosition(int pos, int num,Node* &head, Node* &tail){

    // consider a LL 10->20->30->40->50->NULL and consider them at pos 1 2 3 4 5 and 6 respectively
    int length = getLength(head);
    // first check if pos is valid or not
    if(pos<=0 || pos>length+1){
        cout<<"invalid pos"<<endl;
    }
    else{
    // case1: if insert at pos: 1 => use insertAtHead()
    if(pos==1){
        insertAtHead(num,head,tail);
    }
    // case2: if insert at pos: 6 i.e. length+1 => use insertAtTail()
    else if(pos==length + 1){
        insertAtTail(num,head,tail);
    }
    // case3: if insert at any other pos than 1 and 6 => 
    else{
        Node* temp =head; //step1
        for(int i=0;i<pos-2;i++){
            temp=temp->next;
        }
        Node* back = temp; // step2: traverse temp till pos-2 position and name it back
        Node* newNode = new Node(num); //step 3: create node at that pos
        Node* front = back->next; //step4: keep track of next node
        back->next = newNode; //step5
        newNode->prev = back; //step6
        newNode->next = front; //step7
        front->prev = newNode; //step8

    }
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(10,head,tail);
    insertAtTail(20,head,tail);
    insertAtTail(30,head,tail);
    // print(head);
    insertAtAnyPosition(6,40,head,tail);
    print(head);
}

