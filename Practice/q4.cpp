// cycle in LL
// 1. can be solved using map
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool>mp; //it will also work for duplicate value bcoz we are taking address of nodes here in map not values. i.e. we are taking ListNode* as parameter not ListNode*->data
        ListNode* temp = head;
        while(temp!=NULL){
            if(mp[temp]==true){
                // if it's already true it means that cycle is present
                return true;
            }
            else{
                // if it's not already true it means that it's false currently, then we need to make it true. i.e. we are visiting it for the first time.
                mp[temp]=true; 
            }
            temp=temp->next;
        }
        // if we reached here it means we came out of the loop which means we traversed all the LL and we reached NULL , which means there is no cycle present in LL.
        return false;
    }
};

// TC = O(N) in traversing completely and if cycle is present then O(N+1) which means O(N) in total.
// SC = O(N)as we are mapping every node.

// how to optimize space? => we will use slow and fast pointer
// if fast and slow meet at same point it means that cycle is present 

// ListNode* fast=head;
// ListNode* slow = head;
// while(fast!=NULL){
//     fast=fast->next;
//     if(fast-!=NULL){
//         fast=fast->next;
//         slow=slow->next;
//         if(fast==slow){
//             // it means cycle is present
//             return true;

//         }
//     }
//     // if we have reached till here it means that there is no cycle present
//     return false; 
// }
