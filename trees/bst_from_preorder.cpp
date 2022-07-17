//Iterative approach
TreeNode* bstFromPreorder(vector<int>& preorder) {      
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *p = root;
        stack<TreeNode*> S;
        int i = 1;
        while(i < preorder.size()){
            if(p->val > preorder[i]){
                p->left = new TreeNode(preorder[i]);
                S.push(p);
                p = p->left;
            }
            else{
                while(!S.empty() && S.top()->val < preorder[i]){
                    p = S.top();
                    S.pop();
                }
                p->right = new TreeNode(preorder[i]);
                p = p->right;
            }
            i++;
        }
        return root;
    }

// Recursive approach
TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)
            return NULL;
        TreeNode* root=new TreeNode(preorder[0]);
        if(preorder.size()==1)
            return root;
        vector<int>left;
        vector<int>right;
        for(int i=0;i<preorder.size();i++)
        {
            if(preorder[i]>preorder[0])
                right.push_back(preorder[i]);
            else if(preorder[i]<preorder[0])
                left.push_back(preorder[i]);
        }
        root->left=bstFromPreorder(left);
        root->right=bstFromPreorder(right);
        return root;
    }
