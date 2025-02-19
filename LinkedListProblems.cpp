// 206. Reverse Linked List
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
        ListNode* reverseList(ListNode* head) {
            if(head==NULL) return NULL;
            ListNode* temp=head;
            ListNode* prev=NULL;
            while(temp!=NULL)
            {
                ListNode* front=temp->next;
                temp->next=prev;
                prev=temp;
                temp=front;
            }
            return prev;
        }
    };
    
    
    // 21. Merge Two Sorted Lists
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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode *list3=new ListNode(0);
            ListNode* temp=list3;
            while(list1&&list2)
            {
                if(list1->val>list2->val)
                {
                    temp->next=list2;
                    list2=list2->next;
                }
                else
                {
                    temp->next=list1;
                    list1=list1->next;
                }
                temp=temp->next;
            }
            temp->next=list1?list1:list2;
            ListNode* head=list3->next;
            delete list3;
            return head;
        }
    };
    
    
    // 141. Linked List Cycle
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
            ListNode* fast=head;
            ListNode* slow=head;
            while(fast!=NULL&&fast->next!=NULL)
            {
                fast=fast->next->next;
                slow=slow->next;
                if(fast==slow) return true;
            }
            return false;
        }
    };
    
    
    // 83. Remove Duplicates from Sorted List
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
        ListNode* deleteDuplicates(ListNode* head) {
            if(head==NULL) return head;
            ListNode* list2=new ListNode(head->val);
            ListNode* temp=head;
            ListNode* temp2=list2;
            while(temp!=NULL)
            {
                if(temp2->val<temp->val)
                {
                    temp2->next=temp;
                    temp2=temp2->next;
                }
                temp=temp->next;
            }
            temp2->next=NULL;
            return list2;
        }
    };