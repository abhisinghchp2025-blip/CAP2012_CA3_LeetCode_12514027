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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode*kth = head;
        for(int i =0;i<k;i++){
            if(kth==NULL){
                return head;
            }
            kth = kth->next;
        }
        ListNode*prev = NULL;
        ListNode*curr = head;
        while(curr!=kth){
            ListNode*next=curr->next;
            curr->next=prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(kth,k);
        return prev;

    }
};
