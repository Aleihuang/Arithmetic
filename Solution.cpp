#include "Solution.h"



Solution::Solution()
{
}

vector<TreeNode*> generate(int start,int end/*, vector<TreeNode*>& result*/) {
	vector<TreeNode*> result;
	if (start == end) {
		TreeNode* node = new TreeNode(start);
		result.push_back(node);
	}
	return result;
}

//获取所有组成的二叉搜索树
vector<TreeNode*> Solution::generateTrees(int n) {
	vector<TreeNode*> result;
	for (size_t i = 1; i < n+1; i++)
	{
		vector<TreeNode*> res = generate(1, i - 1);
		for (auto j = res.begin(); j != res.end(); j++)
		{
			TreeNode* node = new TreeNode(i);
			node->left = *j;
			result.push_back(node);
		}
		res = generate(i+1, n);
		for (auto j = res.begin(); j != res.end(); j++)
		{
			TreeNode* node = new TreeNode(i);
			node->left = *j;
			result.push_back(node);
		}
	}
}
void getData(TreeNode* tree,vector<int>& value) {
	if (tree == NULL) {
		return;
	}
	getData(tree->left, value);
	value.push_back(tree->val);
	getData(tree->right, value);
}
bool Solution::isValidBST(TreeNode* root) {
	if (root == NULL) {
		return true;
	}
	vector<int> value;
	getData(root->left, value);
	for (auto i = value.begin(); i != value.end(); i++)
	{
		if (*i>=root->val) {
			return false;
		}
	}
	value.clear();
	getData(root->right, value);
	for (auto i = value.begin(); i != value.end(); i++)
	{
		if (*i <= root->val) {
			return false;
		}
	}
	return isValidBST(root->left) && isValidBST(root->right);
}

void Solution::recoverTree(TreeNode* root) {

}

bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
	if (p == 0&&q == 0) {
		return true;
	}
	if ((p == NULL && q != NULL) || p != NULL && q == NULL) {
		return false;
	}
	if (p->val == q->val) {
		if (isSameTree(p->left, q->left)) {
			return isSameTree(p->right, q->right);
		}
		return false;
	}
	return false;
}

bool Solution::isSymmetricA(TreeNode* left,TreeNode* right) {
	if (left == NULL && right == NULL) {
		return true;
	}
	if ((left == NULL && right != NULL) || (left != NULL && right == NULL)) {
		return false;
	}
	if (left->val == right->val) {
		if (isSymmetricA(left->left,right->right)) {
			return isSymmetricA(left->right, right->left);
		}
	}
}

bool Solution::isSymmetric(TreeNode* root) {
	if (root == NULL) {
		return true;
	}
	return isSymmetricA(root->left, root->right);
}
void getList(vector<TreeNode*> node, vector<vector<int>>& result) {
	vector<int> res;
	for (auto i = node.begin(); i != node.end(); i++)
	{
		res.push_back((*i)->val);
	}
	return;
}
vector<vector<int>> Solution::levelOrder(TreeNode* root) {

}

Solution::~Solution()
{
}
