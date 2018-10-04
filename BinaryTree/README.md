# 这里是与二叉树相关的内容

## 一、二叉树的非递归遍历（无可厚非的利用栈实现）

总体思路都是先将左子树入栈（该处的入栈是指不断取左孩子入栈，直到没有左孩子），然后合理安排出栈和访问结点的顺序。测试代码见[TreeVisit.cpp](TreeVisit.cpp)

### 1、前序遍历

思路：入栈时访问当前结点，出栈时将栈顶结点的右子树(如果有的话)入栈

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

### 2、中序遍历

思路：入栈时不操作，出栈时先访问栈顶结点，然后将栈顶结点的右子树入栈

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

### 3、后序遍历

思路：入栈时不操作，出栈时判断栈顶结点是否有右子树 或者 上次访问的结点是不是栈顶结点的右孩子，如果满足条件则访问栈顶结点，否则继续将栈顶结点的右子树入栈

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