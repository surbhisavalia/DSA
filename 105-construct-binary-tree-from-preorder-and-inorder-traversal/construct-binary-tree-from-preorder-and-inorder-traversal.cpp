class Solution {
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return makeTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder,
                       int preIndex, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int rootValue = preorder[preIndex];
        TreeNode* root = new TreeNode(rootValue);
        int rootPosition = left;
        while (inorder[rootPosition] != rootValue) {
            rootPosition++;
        }
        int leftSize = rootPosition - left;
        root->left = makeTree(
            preorder,
            inorder,
            preIndex + 1,
            left,
            rootPosition - 1
        );
        root->right = makeTree(
            preorder,
            inorder,
            preIndex + leftSize + 1,
            rootPosition + 1,
            right
        );
        return root;
    }
};