// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
   void traversal(Node* root, vector<int>&ans){
       if(!root) return ;
       traversal(root->left, ans);
       ans.push_back(root->data);
       traversal(root->right, ans);
   }
    void solve(Node* root, vector<int>&ans, int &idx , int n){
        if(!root) return ;
        if(idx < n){
        solve(root->left, ans, idx, n);
        solve(root->right, ans, idx, n);
        root->data = ans[idx];
        idx += 1;
            
        }
        
    }
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        vector<int>ans;
        traversal(root, ans);
        // for(auto &a:ans) cout<<a<<" ";
        // cout<<endl;
        sort(ans.begin(), ans.end());
        int n = ans.size();
        int a = 0;
        solve(root, ans, a, n);
        
        }
};
