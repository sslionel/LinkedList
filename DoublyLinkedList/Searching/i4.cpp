// search a target in a DLL
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
    next = NULL;
    data = num;
}
};

bool searchTarget(int target, Node* head){ // searching will take O(N) time which is same as insertion and accessing a LL.
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        if(temp->data == target){
            return true;
                }
        temp=temp->next;
    }
    // if we reached till here that means LL is travelled fully and target is not found till yet
    return false;
}