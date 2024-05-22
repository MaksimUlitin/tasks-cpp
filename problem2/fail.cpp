// #include <iostream>

// template <typename T>
// struct TreeNode {
//     T data;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(const T& data) : data(data), left(nullptr), right(nullptr) {}
// };

// template <typename T>
// class BinaryTree {
// private:
//     TreeNode<T>* root;

// public:
//     BinaryTree() : root(nullptr) {}

//     void insert(const T& data) {
//         if (root == nullptr) {
//             root = new TreeNode<T>(data);
//         } else {
//             insertHelper(root, data);
//         }
//     }

//     void insertHelper(TreeNode<T>* node, const T& data) {
//         if (data < node->data) {
//             if (node->left == nullptr) {
//                 node->left = new TreeNode<T>(data);
//             } else {
//                 insertHelper(node->left, data);
//             }
//         } else {
//             if (node->right == nullptr) {
//                 node->right = new TreeNode<T>(data);
//             } else {
//                 insertHelper(node->right, data);
//             }
//         }
//     }

//     void printTree() const {
//         printTreeHelper(root, 0);
//         std::cout << std::endl;
//     }

//     void printTreeHelper(TreeNode<T>* node, int level) const {
//         if (node != nullptr) {
//             printTreeHelper(node->right, level + 1);
//             std::cout << std::string(level * 2, ' ') << node->data << std::endl;
//             printTreeHelper(node->left, level + 1);
//         }
//     }
// };