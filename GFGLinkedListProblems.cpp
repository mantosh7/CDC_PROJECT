// Q. Intersection Point in Y-Shaped Linked List
class Solution {
    public:
        Node* intersectPoint(Node* head1, Node* head2) {
            Node* t1=head1;
            Node* t2=head2;
            while(t1!=t2)
            {
                t1=(t1==NULL)?t1=head2:t1->next;
                t2=(t2==NULL)?t2=head1:t2->next;
            }
            return t2;
        }
    };
    
    
    // Q. Check List is Paindrome or not
    class Solution {
    public:
        // Function to check whether the list is palindrome.
        bool isPalindrome(Node *head) {
            stack<int> st;
            Node* temp=head;
            while(temp!=NULL)
            {
                st.push(temp->data);
                temp=temp->next;
            }
            temp=head;
            while(temp!=NULL)
            {
                if(temp->data!=st.top()) return false;
                temp=temp->next;
                st.pop();
            }
            return true;
        }
    };