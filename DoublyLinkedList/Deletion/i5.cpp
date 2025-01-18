// deletion of node from any position
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

int getLength(Node* head){
Node* temp = head;
int count =0;
while(temp!=NULL){
    count++;
    temp=temp->next;
}
return count;
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

void deleteFromPosition(int pos,Node* &head, Node* &tail){
    // case 1: LL is empty
    int length = getLength(head);
    if(head == NULL && tail == NULL ){
        cout<<"No nodes to delete"<<endl;
    }

    // case2: LL only has single node
    else if(head== tail){
        Node* temp = head;//step1: point temp to head
        head =NULL; //step2: point head to NULL
        tail = NULL; //step3: point tail to NULL
        delete temp; //delete temp;
    }

    // case3: delete head node
    else if(pos == 1){
        Node* temp=head;//step1
        head=head->next;//step2
        temp->next=NULL;//step3
        head->prev=NULL;//step4
        delete temp;//step5
    }

    // case4: delete tail
    else if(pos == length){
        Node* temp = tail; //step1
        Node* back = temp->prev;//step2
        tail = back;//step3
        tail->next=NULL;//step4
        temp->prev=NULL;//step5
        delete temp;//step6
    }

    // case5: delete any node other than head and tail
    else{
        Node* temp = head; //step1
        for(int i=0;i<pos-2;i++){
            temp = temp->next;
        }
        Node* back = temp;//step2
        Node* curr= back->next; //step3
        Node* front = curr->next; //step4
        back->next = front;// step5
        front->prev = back; //step6
        curr->next=NULL; //step7
        curr->prev=NULL; //step8
        delete curr; //step9
    }

}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(10,head,tail);
    insertAtTail(20,head,tail);
    insertAtTail(30,head,tail);
    print(head);
    deleteFromPosition(3,head,tail);
    print(head);
}