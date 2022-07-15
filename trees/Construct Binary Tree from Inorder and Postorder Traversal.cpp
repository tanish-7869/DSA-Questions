#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

//Function to return a tree created from postorder and inoreder traversals.
unordered_map<int,int> mp;
Node *solve(int in[],int post[],int start,int end,int &post_index){
    if(start > end) return 0;
    Node* root = new Node(post[post_index]);
    int in_index = mp[root->data];
    post_index--;
    root->right = solve(in,post,in_index+1,end,post_index);
    root->left = solve(in,post,start,in_index-1,post_index);
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    for(int i=0;i<n;i++){
        mp[in[i]] = i;
    }
    int post_index = n-1;
    return solve(in,post,0,n-1,post_index);
}
