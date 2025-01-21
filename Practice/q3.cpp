// find palindrome eg:123321
// 1st solution. logic: copy the linked list, reverse it and then compare all the elements one by one if there is a match then we'll say that 
// the LL is a palindrome. TC: O(n) to copy + O(n) to reverse + O(n) to compare = O(3n) = O(n). SC= O(n) for new LL.

// 2nd solution: logic: use fast and slow pointer, slow reaches on 2nd 3 and fast reaches on NULL. 
// then take 1st 3 as prev pointer just behind  slow pointer. now detach 2 LL by writing prev->next=NULL;
// break: now we have 2 LL 1->2->3->NULL and other one is 3->2->1->NULL
// reverse: now reverse the 2nd LL: 1->2->3->NULL
// compare: now finally compare both LL if they are equal then the LL was palindrome else not.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* getMiddle(ListNode* head, ListNode* &prevOfMiddleNode){
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                prevOfMiddleNode = slow; //before moving slow we will save it's previous.
                slow=slow->next;
            }
        }
        return slow;

}
ListNode* reverseList(ListNode* &prev , ListNode* &curr){
    while(curr!=NULL){
        ListNode* front = curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        // get middle and prev
// cases to avoid NULL pointer exception
if(head==NULL){
    // LL is empty
    return true;
}
if(head->next==NULL){
    // singe node in LL
    return true;

}
        ListNode* firstHalfHead = head;
        ListNode* prevOfMiddleNode = NULL;
        ListNode* getMiddleNode = getMiddle(head,prevOfMiddleNode); //tc = O(N/2)~= O(N)

        // break
        prevOfMiddleNode->next=NULL; //due to this line it gives runtime error due to null pointer exception, as it is a single node we need to check if it is a palindrome or not. error occured bcoz in this eg: 1->NUll prevOfMiddleNode is NULL and we did NULL->next=NULL bcoz of this we are gettign error, so we need to write down few cases. 
        
        // reverse
        ListNode* prev=NULL;
        ListNode* curr= getMiddleNode;
        ListNode* secondHalfHead = reverseList(prev,curr); //tc = O(N/2)~= O(N)

        // compare
        // in the case of LL with even length both parts will be of equal length
        // in case of LL with odd length , 2nd half will be longer by 1 element
        // thst's why we will compare only with respect to the length of first half.
        ListNode* tempHead1 = firstHalfHead; //tc = O(N/2)~= O(N)
        ListNode* tempHead2 =  secondHalfHead;
        while(tempHead1 !=NULL){
            if(tempHead1->val!=tempHead2->val){
                // not a palindrome
                return false;
            }
            else{
                // if data is equal then move ahead
            tempHead1=tempHead1->next;
            tempHead2 = tempHead2->next; 
            }
        }
        // if we have reacher here that means that all the elements of first half matches with the elements of the second half i.e. it is palindrome
        return true; 
           }
};

// total tc = O(N+N+N)=O(3N)=O(N)

