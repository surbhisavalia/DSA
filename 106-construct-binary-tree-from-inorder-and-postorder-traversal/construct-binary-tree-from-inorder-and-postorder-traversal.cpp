class Solution {
public:

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return makeTree(inorder, postorder, 0, inorder.size() - 1,
                        postorder.size() - 1);
    }
    TreeNode* makeTree(vector<int>& inorder, vector<int>& postorder,
                       int left, int right, int postIndex) {
        if (left > right) {
            return nullptr;
        }
        int rootValue = postorder[postIndex];
        TreeNode* root = new TreeNode(rootValue);
        int rootPosition = left;
        while (inorder[rootPosition] != rootValue) {
            rootPosition++;
        }
        int rightSize = right - rootPosition;
        root->right = makeTree(
            inorder,
            postorder,
            rootPosition + 1,
            right,
            postIndex - 1
        );
        root->left = makeTree(
            inorder,
            postorder,
            left,
            rootPosition - 1,
            postIndex - rightSize - 1
        );
        return root;
    }
};