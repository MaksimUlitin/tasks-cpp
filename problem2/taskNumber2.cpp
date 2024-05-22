#include <iostream>

template <typename T>
class NodeDLL;
template <typename T>
class DoublyLinkedList;

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const T& data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    TreeNode<T>* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(const T& data) {
        if (root == nullptr) {
            root = new TreeNode<T>(data);
        } else {
            insertHelper(root, data);
        }
    }

    void insertHelper(TreeNode<T>* node, const T& data) {
        if (data < node->data) {
            if (node->left == nullptr) {
                node->left = new TreeNode<T>(data);
            } else {
                insertHelper(node->left, data);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new TreeNode<T>(data);
            } else {
                insertHelper(node->right, data);
            }
        }
    }

    void printTree() const {
        printTreeHelper(root, 0);
        std::cout << std::endl;
    }

    void printTreeHelper(TreeNode<T>* node, int level) const {
        if (node != nullptr) {
            printTreeHelper(node->right, level + 1);
            std::cout << std::string(level * 2, ' ') << node->data << std::endl;
            printTreeHelper(node->left, level + 1);
        }
    }
};

template <typename T>
class NodeDLL {
private:
    T data;
    NodeDLL<T>* next;
    NodeDLL<T>* prev;

public:
    NodeDLL(const T& data) : data(data), next(nullptr), prev(nullptr) {}

    T getData() const { return data; }

    NodeDLL<T>* getNext() const { return next; }

    NodeDLL<T>* getPrev() const { return prev; }

    void setNext(NodeDLL<T>* node) { next = node; }

    void setPrev(NodeDLL<T>* node) { prev = node; }
};

template <typename T>
class DoublyLinkedList {
private:
    NodeDLL<T>* head;
    NodeDLL<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(const T& data) {
        NodeDLL<T>* newNode = new NodeDLL<T>(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->setNext(head);
            head->setPrev(newNode);
            head = newNode;
        }
    }

    void push_back(const T& data) {
        NodeDLL<T>* newNode = new NodeDLL<T>(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->setPrev(tail);
            tail->setNext(newNode);
            tail = newNode;
        }
    }

    bool isEmpty() const { return head == nullptr; }

    void printList() const {
        NodeDLL<T>* current = head;
        while (current != nullptr) {
            std::cout << current->getData() << " <-> ";
            current = current->getNext();
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    DoublyLinkedList<int> dll;
    BinaryTree<int> bt;

    dll.push_front(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.push_front(0);
    dll.printList();

    bt.insert(5);
    bt.insert(3);
    bt.insert(7);
    bt.insert(1);
    bt.insert(4);
    bt.insert(6);
    bt.insert(8);
    bt.printTree();

    return 0;
}