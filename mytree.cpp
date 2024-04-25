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
        PreOrderTraverse(root->right);
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
