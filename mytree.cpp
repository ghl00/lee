#include "mytree.h"

TreeNode* CreataNode(int val)
{
    return new TreeNode(val, nullptr, nullptr);
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
        TreeNode* parent = cur;
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
        for (int size = q.size(); size > 0; size--)
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
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    return root;
}