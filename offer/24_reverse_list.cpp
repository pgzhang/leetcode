// Solution 1:
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *pre = head;
        ListNode *cur = head->next;
        pre->next = nullptr;
        while(cur){
            ListNode *temp = pre;
            pre = cur;
            cur = cur->next;
            pre->next = temp;
        }
        return pre;
    }
};

// Solution 2:
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
    ListNode* reverseList(ListNode* head) {
       ListNode* pre = nullptr;
       ListNode* next = nullptr;
       while(head){
           next = head->next;
           head->next = pre;
           pre = head;
           head = next;
       }
       return pre;
    }
};