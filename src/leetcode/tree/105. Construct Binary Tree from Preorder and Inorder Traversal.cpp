// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34538/My-Accepted-Java-Solution

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorder_no_recursive(TreeNode *node)
{
    stack<TreeNode *> stack;
    stack.push(node);

    while (!stack.empty())
    {
        auto t = stack.top();
        stack.pop();

        if (t == NULL)
            continue;

        cout << t->val;

        stack.push(t->right);
        stack.push(t->left);
    }
}

void inorder_no_recursive(TreeNode *node)
{
    stack<pair<TreeNode *, bool>> stack;

    stack.push(make_pair(node, false));

    while (!stack.empty())
    {
        auto t = stack.top().first;
        auto visited = stack.top().second;
        stack.pop();

        if (t == NULL)
            continue;

        if (visited)
        {
            cout << t->val;
        }
        else
        {
            stack.push(make_pair(t->right, false));
            stack.push(make_pair(t, true));
            stack.push(make_pair(t->left, false));
        }
    }
}

TreeNode *build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    auto root = new TreeNode(preorder[preStart]);

    int inRoot = 0;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inorder[i] == root->val)
        {
            inRoot = i;
            break;
        }
    }

    int leftTreeLen = inRoot - inStart;
    root->left = build(preorder, preStart + 1, preStart + leftTreeLen, inorder, inStart, inRoot - 1);
    root->right = build(preorder, preStart + leftTreeLen + 1, preEnd, inorder, inRoot + 1, inEnd);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

int main()
{
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};

    auto tree = buildTree(preorder, inorder);

    preorder_no_recursive(tree);
    cout << endl;
    inorder_no_recursive(tree);

    getchar();
    return 0;
}