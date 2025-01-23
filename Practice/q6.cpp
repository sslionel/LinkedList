// sort 0's, 1's and 2's in LL

// approach1: do counting of 0 1 and 2-> create a new LL-> TC->O(N) SC=O(N)
// approach2: do counting of 0 1 and 2 -> overwrite the data in LL
// interviewer will not consider above 2 approaches as the best solution
// approach3:   
class Solution {
  public:
  void insertAtTail(Node* &toMove,Node* &head, Node* &tail){
    //   when LL is empty:
    if(head==NULL && tail==NULL){
        head=toMove;
        tail=toMove;
    }
    else{
        tail->next=toMove;
        tail=toMove;
    }
  }
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // we are going to take three respective heads
        // zerohead, onehead, twohead all are pointing to null
        // after preparing all the seperate LL we now need to join them
        // so we point zerotail->next = onehead and onetail->next = twohead
        // and since zerohead is the head of the resultant LL we will return zerohead.
        
        Node* zeroHead = NULL;
        Node* zeroTail = NULL;
        Node* oneHead = NULL;
        Node* oneTail = NULL;
        Node* twoHead = NULL;
        Node* twoTail = NULL;
        
        // traverse LL and create these 3 seperate LL
        Node* temp = head;
        while(temp!=NULL){
            // create toMove node and isolate it
            Node* toMove = temp;
            temp=temp->next;
            toMove->next=NULL;
            if(toMove->data==0){
                insertAtTail(toMove,zeroHead,zeroTail);
            }
            else if(toMove->data==1){
                insertAtTail(toMove,oneHead,oneTail);
            }
            else if(toMove->data==2){
                insertAtTail(toMove,twoHead,twoTail);
            }
        }
        // all 3 LL are ready now merge them
        // very important point: maybe there maybe a possibility that 0,1 or 2 LL maybe empty
        if(zeroHead!=NULL){
            // if not empty
            if(oneHead!=NULL){
                //if not empty merger zero to one
                zeroTail->next=oneHead;
                // merge one to two
                // if not empty merge one to two
                    oneTail->next = twoHead;
            }
            else{
                // if one is empty
                zeroTail->next=twoHead;
            }
            return zeroHead;
        }
        else{
            // if 0 is empty
            if(oneHead!=NULL){
                oneTail->next = twoHead;
                return oneHead;
            }
            else{
                return twoHead;
            }
        }
    }
    
};
// tc: o(n) 
// sc: o(1)