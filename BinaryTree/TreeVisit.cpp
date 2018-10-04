#include<iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val),left(NULL),right(NULL) {}
};

TreeNode* init() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

void preOrder(TreeNode* root) {
    vector<TreeNode*> stack;
    TreeNode *tmp = root;
    while(tmp || !stack.empty()) {
        while(tmp) {
            cout<<tmp->val;
            stack.push_back(tmp);
            tmp = tmp->left;
        }
        if(!stack.empty()) {
            tmp = (stack[stack.size()-1])->right;
            stack.pop_back();
        }
    }
    cout<<endl;
}

void inOrder(TreeNode* root) {
    vector<TreeNode*> stack;
    TreeNode *tmp = root;
    while(tmp || !stack.empty()) {
        while(tmp) {
            stack.push_back(tmp);
            tmp = tmp->left;
        }
        if(!stack.empty()) {
            tmp = stack[stack.size()-1];
            cout<<tmp->val;
            stack.pop_back();
            tmp = tmp->right;
        }
    }
    cout<<endl;
}

void afterOrder(TreeNode* root) {
    vector<TreeNode*> stack;
    TreeNode *tmp = root;
    TreeNode *pre = NULL;
    while(tmp || !stack.empty()) {
        while(tmp) {
            stack.push_back(tmp);
            tmp = tmp->left;
        }
        tmp = stack[stack.size()-1];
        if(tmp->right && tmp->right != pre) {
            tmp = tmp->right;
            continue;
        } else {
            cout<<tmp->val;
            stack.pop_back();
            pre = tmp;
            tmp = NULL;
        }
    }
    cout<<endl;
}

int main()
{
    TreeNode* root = init();
    preOrder(root);
    inOrder(root);
    afterOrder(root);
}
