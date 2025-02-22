// add 1 to Linked List using head recursion:
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

void print(Node* head){
    Node* temp = head; //new temporary pointer takes constant space it doesnt matter
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void solve(Node* head,int& carry){
    if(!head){ //if head==NULL return back
        return;
    }
    // call head recursion
    solve(head->next,carry); //reach till the end node
    // case1:
    int sum = head->data + carry;
    int digit = sum%10;
    carry = sum/10;
    head->data = digit;//update the data of head
}
Node* add1(Node* head,int& carry){
    solve(head,carry);
    if(carry){
        Node* newHead = new Node(carry);
        newHead->next = head;
        head=newHead;
    }
    return head;
}

int main(){
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next= new Node(9);
    int carry = 1;
    head = add1(head,carry);
    print(head);
    return 0;
}