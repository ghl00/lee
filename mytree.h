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