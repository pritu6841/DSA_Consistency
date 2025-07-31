class Solution {
  private:
    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isHeapRec(Node* root, int index, int node_count) {
        if (!root) return true;
        if (index >= node_count) return false; // completeness violated

        // heap-order check (max-heap)
        if (root->left && root->left->data > root->data) return false;
        if (root->right && root->right->data > root->data) return false;

        return isHeapRec(root->left, 2 * index + 1, node_count) &&
               isHeapRec(root->right, 2 * index + 2, node_count);
    }

  public:
    bool isHeap(Node* root) {
        if (!root) return true;
        int node_count = countNodes(root);
        return isHeapRec(root, 0, node_count);
    }
};
