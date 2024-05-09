#include "mytree.h"

TreeNode* CreataNode(int val)
{
    return new TreeNode(val, nullptr, nullptr);
}

TreeNode* Solution::CreateTree(TreeNode* root, std::vector<TreeNode*>& vtree)
{
    std::queue<TreeNode*> q;
    q.push(vtree[0]);
    root = vtree[0];

    int i = 0;
    while (1)
    {
        TreeNode* tmp = q.front();
        q.pop();
        if (tmp != nullptr)
        {
            if (++i < vtree.size())
            {
                tmp->left = vtree[i];
                q.push(tmp->left);
            }
            else
            {
                break;
            }
            if (++i < vtree.size())
            {
                tmp->right = vtree[i];
                q.push(tmp->right);
            }
            else
            {
                break;
            }
        }
    }
    return root;
}

TreeNode* InsertNode(TreeNode* root, int val)
{
    if (root == nullptr)
    {
        return CreataNode(val);
    }
    TreeNode* cur = root;
    while (1) 
    {
        if (val < cur->val)
        {
            if (cur->left == nullptr) 
            {
                cur->left = CreataNode(val);
                break;
            }
            else
            {
                cur = cur->left;
            }
        }
        else 
        {
            if (cur->right == nullptr)
            {
                cur->right = CreataNode(val);
                break;
            }
            else
            {
                cur = cur->right;
            }
        }
    }
    return root;
}

void PreOrderTraverse(TreeNode* root)
{
    if (root)
    {
        std::cout << " " << root->val;
        PreOrderTraverse(root->left);
        PreOrderTraverse(root->right);
    }
}

void InOrderTraverse(TreeNode* root)
{
    if (root)
    {
        InOrderTraverse(root->left);
        std::cout << " " << root->val;
        InOrderTraverse(root->right);
    }
}

void PostOrderTraverse(TreeNode* root)
{
    if (root)
    {
        PostOrderTraverse(root->left);
        PostOrderTraverse(root->right);
        std::cout << " " << root->val;
    }
}

void LevelOrderTraverse(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* cur = q.front();
        std::cout << " " << cur->val;
        q.pop();
        if (cur->left)
        {
            q.push(cur->left);
        }
        if (cur->right)
        {
            q.push(cur->right);
        }
    }
}

int maxDepth(TreeNode* root) 
{
    if (root == nullptr)
    {
        return 0;
    }
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int maxDepth2(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    for (; !q.empty(); depth++)
    {
        for (size_t size = q.size(); size > 0; size--)
        {
            TreeNode* node = q.front();
            q.pop();
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
    }
    return depth;
}
std::vector<int> inorderTraversal(TreeNode* root)
{
    static std::vector<int> v;
    static int rdepth = 0;
    ++rdepth;
    if (root)
    {
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);
    }
    if (--rdepth == 0)
    {
        std::vector<int> tmp = v;
        v.clear();
        return tmp;
    }
    return v;
}

TreeNode* invertTree(TreeNode* root) 
{
    if (root == nullptr)
    {
        return root;
    }
    invertTree(root->left);
    invertTree(root->right);
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}

std::vector<std::vector<int>> levelOrder(TreeNode* root)
{
    std::vector<std::vector<int>> vv;
    if (root == nullptr)
    {
        return vv;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    for (int depth = 0; !q.empty(); depth++)
    {
        std::vector<int> v;
        for (size_t size = q.size(); size > 0; size--)
        {
            TreeNode* node = q.front();
            v.push_back(node->val);
            q.pop();
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        vv.push_back(v);
    }
    return vv;
}

int Solution::depth(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int L = depth(root->left);
    int R = depth(root->right);
    ans = max(ans, L + R + 1);
    return max(L, R) + 1;
}

int Solution::diameterOfBinaryTree(TreeNode* root)
{
    ans = 1;
    ans = depth(root);
    return ans - 1;
}

TreeNode* helper(vector<int>& nums, size_t left, size_t right)
{
    if (left > right)
    {
        return nullptr;
    }
    size_t mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);
    return root;
}

static bool check(TreeNode* p, TreeNode* q) 
{
    if (!p && !q) return true;
    if (!p || !q) return false;
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
}

bool isSymmetric(TreeNode* root) 
{
    return check(root, root);
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) 
{
    return helper(nums, 0, nums.size() - 1);
}


bool Solution::isValidBST(TreeNode* root)
{
    std::stack<TreeNode*> stack;
    long long inorder = (long long)INT_MIN - 1;

    while (!stack.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        if (root->val <= inorder)
        {
            return false;
        }
        inorder = root->val;
        root = root->right;
    }

    return true;
}