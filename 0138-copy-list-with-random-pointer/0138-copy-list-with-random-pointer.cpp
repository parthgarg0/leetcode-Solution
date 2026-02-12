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
        if (head == NULL)
            return NULL;

        unordered_map<Node*, Node*> m;

        Node* newh = new Node(head->val);
        Node* oldt = head->next;
        Node* newt = newh;

        m[head] = newh;   

        while (oldt != NULL) {
            Node* newcopy = new Node(oldt->val);
            m[oldt] = newcopy;
            newt->next = newcopy;

            oldt = oldt->next;
            newt = newt->next;
        }

        oldt = head;
        newt = newh;

        while (oldt != NULL) {
            newt->random = (oldt->random != NULL) ? m[oldt->random] : NULL;  

            oldt = oldt->next;
            newt = newt->next;
        }

        return newh;
    }
};
