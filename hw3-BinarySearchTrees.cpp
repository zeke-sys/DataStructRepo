#include <memory>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// bst_node is the binary search tree node structure
struct bst_node {
    int data; // value of this node
    bst_node* left; // points to the left child or nullptr if no left child
    bst_node* right; // points to the right child or nullptr if no right child
};

class BST {
    public:
        BST(); // constructor

        ~BST(); // destructor

        bst_node* init_node(int data); // create a new bst_node

        void insert(bst_node* new_node); // insert a given node into the BST 

        void insert_data(int data); // insert a new node with given data into the BST

        void remove(int data); // remove the node with the given data from the BST

        bool contains(bst_node* subt, int data); // check if the subtree contains a node with the given data

        bst_node* get_node(bst_node* subt, int data); // get the node with the given data from the subtree

        int size(bst_node* subt); // return the size of the subtree

        void to_vector(bst_node* subt, vector<int>& vec); // convert the subtree to a vector

        bst_node* get_root(); // return the root node of the BST

        void set_root(bst_node** new_root); // set the root node of the BST

        
    private:
        bst_node** root;
};

BST::BST() {
    root = new bst_node*;
    *root = NULL; // initialize root pointer to nullptr
}

BST::~BST() {} // destructor

bst_node* BST::init_node(int data) {
    bst_node* ret(new bst_node); // create a new node
    ret->data = data; // set the data
    ret->left = nullptr; // set the left pointer to nullptr
    ret->right = nullptr; // set the right pointer to nullptr
    return ret; // return the new node
}

void BST::insert(bst_node* new_node) {
    if (*root == nullptr) { // if the tree is empty
        *root = new_node; // set the root pointer to the new node
    } else { // if the tree is not empty
        bst_node* curr = *root; // current node pointer
        while (true) { // traverse the tree
            if (new_node->data < curr->data) { // if the new node's data is less than the current node's data
                if (curr->left == nullptr) { // if there is no left child
                    curr->left = new_node; // set the left pointer to the new node
                    break; // exit the loop
                } else { // if there is a left child
                    curr = curr->left; // move to the left child
                }
            } else { // if the new node's data is greater than or equal to the current node's data
                if (curr->right == nullptr) { // if there is no right child
                    curr->right = new_node; // set the right pointer to the new node
                    break; // exit the loop
                } else { // if there is a right child
                    curr = curr->right; // move to the right child
                }
            }
        }
    }
}

void BST::insert_data(int data) {
    bst_node* new_node = init_node(data); // create a new node
    insert(new_node); // insert the new node into the tree
}

void BST::remove(int data) {
    // Helper function to find the minimum value node in a subtree
    auto find_min = [](bst_node* node) -> bst_node* {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    };

    // Recursive function to remove a node with the given data
    function<bst_node*(bst_node*, int)> remove_rec = [&](bst_node* node, int data) -> bst_node* {
        if (node == nullptr) {
            return node; // Base case: tree is empty
        }
        if (data < node->data) {
            node->left = remove_rec(node->left, data); // Recur on the left subtree
        } else if (data > node->data) {
            node->right = remove_rec(node->right, data); // Recur on the right subtree
        } else {
            // Node with the data found
            if (node->left == nullptr) {
                bst_node* temp = node->right;
                delete node; // Free memory
                return temp; // Return right child
            } else if (node->right == nullptr) {
                bst_node* temp = node->left;
                delete node; // Free memory
                return temp; // Return left child
            }
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            bst_node* temp = find_min(node->right);
            node->data = temp->data; // Copy the inorder successor's content to this node
            node->right = remove_rec(node->right, temp->data); // Delete the inorder successor
        }
        return node; // Return the (possibly updated) node pointer
    };

    *root = remove_rec(*root, data); // Start the removal process from the root
}

bool BST::contains(bst_node* subt, int data) {
    if (subt == nullptr) { // if the subtree is empty
        return false; // return false
    }
    if (subt->data == data) { // if the data is found
        return true; // return true
    }
    if (data < subt->data) { // if the data is less than the current node's data
        return contains(subt->left, data); // search in the left subtree
    } else { // if the data is greater than the current node's data
        return contains(subt->right, data); // search in the right subtree
    }
}

bst_node* BST::get_node(bst_node* subt, int data) {
    if (subt == nullptr) { // if the subtree is empty
        return nullptr; // return nullptr
    }
    if (subt->data == data) { // if the data is found
        return subt; // return the current node
    }
    if (data < subt->data) { // if the data is less than the current node's data
        return get_node(subt->left, data); // search in the left subtree
    } else { // if the data is greater than the current node's data
        return get_node(subt->right, data); // search in the right subtree
    }
}

int BST::size(bst_node* subt) {
    if (subt == nullptr) { // if the subtree is empty
        return 0; // return 0
    }
    return 1 + size(subt->left) + size(subt->right); // return 1 + size of left subtree + size of right subtree
}

void BST::to_vector(bst_node* subt, vector<int>& vec) {
    if (subt == nullptr) { // if the subtree is empty
        return; // return
    }
    to_vector(subt->left, vec); // traverse the left subtree
    vec.push_back(subt->data); // add the current node's data to the vector
    to_vector(subt->right, vec); // traverse the right subtree
}

bst_node* BST::get_root() {
    if (*root == nullptr) {
        return NULL; // if the tree is empty, return null
    }
    return *root; // return the root node
}

void BST::set_root(bst_node** new_root) {
    root = new_root; // set the root pointer to the new root
}

// End of BST class

// Example usage
int main() {
    BST tree; // create a new BST
    tree.insert_data(5); // insert data into the tree
    tree.insert_data(3);
    tree.insert_data(7);
    tree.insert_data(2);
    tree.insert_data(4);
    tree.insert_data(6);
    tree.insert_data(8);

    cout << "Tree contains 4: " << (tree.contains(tree.get_root(), 4) ? "Yes" : "No") << endl; // check if the tree contains 4
    cout << "Tree contains 10: " << (tree.contains(tree.get_root(), 10) ? "Yes" : "No") << endl; // check if the tree contains 10

    cout << "Size of the tree: " << tree.size(tree.get_root()) << endl; // get the size of the tree

    vector<int> vec; // create a vector to store the tree elements
    tree.to_vector(tree.get_root(), vec); // convert the tree to a vector
    cout << "Tree elements in sorted order: ";
    for (int val : vec) {
        cout << val << " "; // print the elements
    }
    cout << endl;

    tree.remove(3); // remove an element from the tree
    cout << "Tree contains 3 after removal: " << (tree.contains(tree.get_root(), 3) ? "Yes" : "No") << endl; // check if the tree contains 3 after removal

    return 0;
}

// End of example usage



