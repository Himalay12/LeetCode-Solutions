/*
    Given the head of a linked list, remove the nth node from the end of the list and return its head.

    Example 1:
        Input: head = [1,2,3,4,5], n = 2
        Output: [1,2,3,5]

    Example 2:
        Input: head = [1], n = 1
        Output: []

    Example 3:
        Input: head = [1,2], n = 1
        Output: [1]
*/

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m=0;
        ListNode* temp,*temp2;
        temp=head;
        while(temp!=nullptr){
            m++;
            temp=temp->next;
        }
        if(m==1) return nullptr;
        if(m==n) { temp2 = head;
                 head=head->next;
                 delete temp2;
                 return head;}
        temp=head;
        while(m>n+1){
            temp=temp->next;
            m--;
        }
        temp2=temp->next;
        temp->next=temp2->next;
        delete temp2;
        return head;
        
    }
};