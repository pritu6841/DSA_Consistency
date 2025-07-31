// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int countNodes(Node* root){
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    bool checkHeap(Node* root,int idx ,int totalNodes){
        if(!root) return true;
        if(idx >= totalNodes) return false;
        
        if(root->left && root->left->data > root->data) return false;
        if(root->right && root->right->data > root->data) return false;
        
        return checkHeap(root->left, idx*2+1, totalNodes) && checkHeap(root->right, idx*2+2, totalNodes);
    }
    bool isHeap(Node* root) {
        // code here
        int totalNodes = countNodes(root);
        return checkHeap(root,0 ,totalNodes);
    }
};