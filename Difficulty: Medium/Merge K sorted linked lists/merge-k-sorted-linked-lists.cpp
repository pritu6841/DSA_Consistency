/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
  struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data; // min-heap: smaller value has higher priority
        }
    };
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<Node*, vector<Node*>, compare>pq;
        for(int i = 0; i<arr.size(); i++) pq.push(arr[i]);
        
        Node* root = new Node(-1);
        Node* temp2 = root;
        while(!pq.empty()){
            Node* smallest = pq.top();
            root->next = smallest;
            root = root->next;
            if(smallest->next) pq.push(smallest->next);
            pq.pop();
        }
        return temp2->next;
    }
};