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
    /**
     * @param head a ListNode
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        
        ListNode *curr = head;
        ListNode *prev = fakeHead;
        
        ListNode *pv1 = nullptr;
        ListNode *pv2 = nullptr;
        
        //Find the two nodes
        while(curr != NULL){
            if(curr->val == v1)
                pv1 = prev;
            
            else if(curr->val == v2)
                pv2 = prev;
                
            prev = curr;
            curr = curr->next;
        }
        
        if(pv1 && pv2){
            //Make sure pv1 is before pv2
            if (pv2->next == pv1){
                auto swap = pv2;
                pv2 = pv1;
                pv1 = swap;
            } 
            
            
            if(pv1->next == pv2){
                auto temp = pv2->next->next;
                pv1->next = pv2->next;
                pv1->next->next = pv2;
                pv2->next = temp;
                
            } else {
                auto temp1 = pv1->next->next;
                auto temp2 = pv2->next->next;
            
                pv1->next->next = temp2;
                pv2->next->next = temp1;
                
                temp1 = pv1->next;
                temp2 = pv2->next;
                
                pv1->next = temp2;
                pv2->next = temp1;
            }
        }
        
        head = fakeHead->next;
        delete fakeHead;
        return head;
    }
};