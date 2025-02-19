// Q. Reverse a Stack
class Solution {
    public:
        void insertAtBottom(stack<int> &St, int x) {
            if (St.empty()) {
                St.push(x);
                return;
            }
            int topElement = St.top();
            St.pop();
            insertAtBottom(St, x);
            St.push(topElement);
        }
    
        void Reverse(stack<int> &St) {
            if (St.empty()) return;
            int topElement = St.top();
            St.pop();
            Reverse(St);
            insertAtBottom(St, topElement);
        }
    };