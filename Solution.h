#pragma once
#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int value) :val(value), left(0), right(0) {}
}TreeNode;

class Solution
{
public:
	Solution();
	~Solution();
	vector<TreeNode*> generateTrees(int n);
	bool isValidBST(TreeNode* root);
	void recoverTree(TreeNode* root);
	bool isSameTree(TreeNode* p, TreeNode* q);
	bool isSymmetric(TreeNode* root);
private:
	void getData(TreeNode* tree, vector<int>& value);
	bool isSymmetricA(TreeNode* left, TreeNode* right);
};

