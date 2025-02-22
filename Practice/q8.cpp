// add 2 numbers represented by LL:

class Solution {
    public:
    
// iterative approach:
// ListNode* iterative(ListNode* l1,ListNode* l2){
//     ListNode* ans = new ListNode(-1); //put -1 for now in the new answer list
//     ListNode* temp = ans;
//     int carry = 0;
//     while(l1 || l2 || carry){ //until l1 , l2 or carry are not NULL
//     int a = l1 ? l1->val : 0; //if l1 is not NULL then take l1->val else take 0
//     int b = l2 ? l2->val : 0; //if l2 is not NULL then take l2->val else take 0
//     int sum = a + b + carry;
//     int digit = sum%10;
//     carry = sum/10;
//     temp->next = new ListNode(digit); //-1 ke next se answer start hoga as -1 is not the part of answer
//     temp = temp->next;
//     l1 = l1 ? l1 = l1->next : NULL;
//     l2 = l2 ? l2 = l2->next : NULL;
//     }
//     ListNode* finalAns = ans->next;
//     delete ans;
//     return finalAns;
// }

// recursive approach:
ListNode* recursive(ListNode* l1,ListNode* l2,int carry =0){
    if(l1 == NULL && l2 == NULL && carry == 0){
        return 0;
    }
    // case1:
    int a = l1 ? l1->val : 0; //if l1 is not NULL then take l1->val else take 0
    int b = l2 ? l2->val : 0; //if l2 is not NULL then take l2->val else take 0
    int sum = a + b + carry;
    int digit = sum%10;
    carry = sum/10;
    // build the ans linked list
    ListNode* ans = new ListNode(digit);
    ans->next = recursive(l1 ? l1->next : l1,l2 ? l2->next : l2,carry);
    return ans;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // return iterative(l1,l2);
        return recursive(l1,l2);
    }
};