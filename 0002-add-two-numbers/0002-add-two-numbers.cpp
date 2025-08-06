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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummyHead = dummy;
        int sum = 0;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            int val1 = l1->val;
            int val2 = l2->val;
            sum += (val1 + val2);
            carry = sum%10;
            sum /= 10;
            ListNode* temp = new ListNode(carry);
            dummy -> next = temp;
            dummy = dummy->next;
            l1= l1 -> next;
            l2 = l2 -> next;
            }
        cout<<sum<<endl;    
        while(l1!=NULL){
            int val1 = l1->val;
            sum += val1;
            carry = sum % 10;
            sum /= 10;
            ListNode* temp = new ListNode(carry);
            dummy -> next = temp;
            dummy = dummy->next;
            l1 = l1->next;
        }
        
        while(l2!=NULL){
            int val2 = l2->val;
            sum += val2;
            carry = sum % 10;
            sum /= 10;
            ListNode* temp = new ListNode(carry);
            dummy -> next = temp;
            dummy = dummy->next;
            l2 = l2->next;
        }   
        if(sum == 1){
            ListNode* temp = new ListNode(sum);
            dummy -> next = temp;
            dummy = dummy->next;
            
        } 
        return dummyHead->next;
    }
};