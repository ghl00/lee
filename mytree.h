#pragma once
#include "lee.h"

struct TreeNode 
{
	int			val;
	TreeNode*	left;
	TreeNode*	right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	int			ans;

	static TreeNode* CreateTree(TreeNode* root, std::vector<TreeNode*>& vtree);
	int depth(TreeNode* root);
	int diameterOfBinaryTree(TreeNode* root);
	static bool isValidBST(TreeNode* root);

};

TreeNode* CreataNode(int val);
TreeNode* InsertNode(TreeNode* root, int val);
void PreOrderTraverse(TreeNode* root);
void InOrderTraverse(TreeNode* root);
void PostOrderTraverse(TreeNode* root);
void LevelOrderTraverse(TreeNode* root); 
int maxDepth(TreeNode* root);
std::vector<int> inorderTraversal(TreeNode* root);
int maxDepth2(TreeNode* root);
TreeNode* invertTree(TreeNode* root);
bool isSymmetric(TreeNode* root);
std::vector<std::vector<int>> levelOrder(TreeNode* root);
