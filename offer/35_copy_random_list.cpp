/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        if(!head) return head;
        Node* copy_head = new Node(head->val);
        m[head] = copy_head; 
        if (!head->random) copy_head->random = nullptr;
        else if (m.find(head->random) != m.end()){
            copy_head->random = m[head->random];
        }
        else{
            Node* temp = new Node(head->random->val);
            m[head->random] = temp;
            copy_head->random = temp;
        }
        Node* pre = copy_head;
        Node* next = head->next;
        while(next){
            Node* temp = nullptr;
            if (m.find(next) == m.end()){
                temp = new Node(next->val);
                m[next] = temp;
            }else{
                temp = m[next];
            }
            if (!next->random) temp->random = nullptr;
            else if(m.find(next->random) == m.end()){
                Node* tmp = new Node(next->random->val);
                m[next->random] = tmp;
                temp->random = tmp;
            }else{
                temp->random = m[next->random];
            }
            pre->next = temp;
            pre = temp;
            next = next->next;
        }
        return copy_head;
    }
};