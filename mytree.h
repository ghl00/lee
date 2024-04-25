#pragma once
#include "lee.h"

struct TreeNode 
{
	int			val;
	TreeNode*	left;
	TreeNode*	right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


TreeNode* InsertNode(TreeNode* root, int val);
void PreOrderTraverse(TreeNode* root);
void InOrderTraverse(TreeNode* root);
void PostOrderTraverse(TreeNode* root);
void LevelOrderTraverse(TreeNode* root);