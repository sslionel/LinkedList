// remove duplicate in sorted LL
// -> using 2 pointer method

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // using 2 pointer approach
        // case1: LL is empty
        if(head==NULL){
            return head;
        }
        // case2: LL has single node
        else if(head->next==NULL){
            return head;
        }
        // case3: LL has more than 1 node
        else{
        ListNode* prev = head;
        ListNode* temp = head->next;
        while(temp!=NULL){
            // check for duplicate
            if(temp->val==prev->val){
                // duplicate found
                prev->next=temp->next;
                temp->next=NULL;
                delete temp;
            }
            else{
                // duplicate not found
                prev=prev->next;
            }
            // set temp again after deletion of temp, very important line
            temp=prev->next; //bcoz maybe we have deleted temp node so we need to update temp;
        }
        // if we have reached here it means temp has reached NULL
        return head;
        }
    }
};