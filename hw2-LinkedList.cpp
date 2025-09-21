#include <memory>
#include <iostream>
using namespace std;

// constructor, initialize class variables and pointers
struct node {
    int data; // value of this node
    node* next; // points to the next node or nullptr if last node
};

class LinkedList {
    public:
        LinkedList(); // constructor
        ~LinkedList(); // destructor
        node* init_node(int data); // create a new node
        string report(); // report all values in the list
        void append_data(int data); // append a new node with given data to the end of the list
        void append(node* new_node); // append a given node to the end of the list
        void insert_data(int offset, int data); // insert a new node with given data at the given offset
        void insert(int offset, node* new_node); // insert a given node at the given offset
        void remove(int offset); // remove the node at the given offset
        int size(); // return the size of the list
        bool contains(int data); // check if the list contains a node with the given data
        node* get_top(); // return the top noe of the list
        void set_top(node* top_ptr); // set the top node of the list
    private:
        node* top_ptr_; // points to the first node in the list or nullptr if empty list
};

LinkedList::LinkedList() {
    top_ptr_ = nullptr; // initialize top pointer to nullptr
}

LinkedList::~LinkedList() {}

node* LinkedList::init_node(int data) {
    node* ret(new node); // create a new node
    ret->data = data; // set the data
    ret->next = nullptr; // set the next pointer to nullptr
    return ret; // return the new node
}

string LinkedList::report() {
    string ret; // return string
    node* curr = top_ptr_; // current node pointer
    while (curr != nullptr) { // traverse the list
        ret += to_string(curr->data) + " "; // append the data to the return string
        curr = curr->next; // move to the next node
    }
    return ret; // return the string
}

void LinkedList::append_data(int data) {
    node* new_node = init_node(data); // create a new node
    append(new_node); // append the new node to the list
}

void LinkedList::append(node* new_node) {
    if (top_ptr_ == nullptr) { // if the list is empty
        top_ptr_ = new_node; // set the top pointer to the new node
    } else { // if the list is not empty
        node* curr = top_ptr_; // current node pointer
        while (curr->next != nullptr) { // traverse to the end of the list
            curr = curr->next; // move to the next node
        }
        curr->next = new_node; // set the next pointer of the last node to the new node
    }
}

void  LinkedList::insert_data(int offset, int data) {
    node* new_node = init_node(data); // create a new node
    insert(offset, new_node); // insert the new node at the given offset
}

void LinkedList::insert(int offset, node* new_node) {
    if (offset == 0) { // if inserting at the top
        new_node->next = top_ptr_; // set the next pointer of the new node to the current top
        top_ptr_ = new_node; // set the top pointer to the new node
    } else { // if inserting at a position other than the top
        node* curr = top_ptr_; // current node pointer
        for (int i = 0; i < offset - 1; i++) { // traverse to the node before the offset
            if (curr == nullptr) { // if the offset is out of bounds
                cout << "Offset out of bounds" << endl;
                return; // exit the function
            }
            curr = curr->next; // move to the next node
        }
        if (curr == nullptr) { // if the offset is out of bounds
            cout << "Offset out of bounds" << endl;
            return; // exit the function
        }
        new_node->next = curr->next; // set the next pointer of the new node to the next node of the current node
        curr->next = new_node; // set the next pointer of the current node to the new node
    }
}

void LinkedList::remove(int offset) {
    if (top_ptr_ == nullptr) { // if the list is empty
        cout << "List is empty" << endl;
        return; // exit the function
    }
    if (offset == 0) { // if removing the top node
        node* temp = top_ptr_; // temporary pointer to the top node
        top_ptr_ = top_ptr_->next; // set the top pointer to the next node
        delete temp; // delete the old top node
    } else { // if removing a node other than the top
        node* curr = top_ptr_; // current node pointer
        for (int i = 0; i < offset - 1; i++) { // traverse to the node before the offset
            if (curr == nullptr) { // if the offset is out of bounds
                cout << "Offset out of bounds" << endl;
                return; // exit the function
            }
            curr = curr->next; // move to the next node
        }
        if (curr == nullptr || curr->next == nullptr) { // if the offset is out of bounds
            cout << "Offset out of bounds" << endl;
            return; // exit the function
        }
        node* temp = curr->next; // temporary pointer to the node to be removed
        curr->next = curr->next->next; // set the next pointer of the current node to skip the removed node
        delete temp; // delete the removed node
    }
}

int LinkedList::size() {
    int ret; // return size
    node* curr = top_ptr_; // current node pointer
    ret = 0; // initialize size to 0
    while (curr != nullptr) { // traverse the list
        ret++; // increment size
        curr = curr->next; // move to the next node
    }
    return ret; // return the size
}

bool LinkedList::contains(int data) {
    bool ret; // return value
    node* curr = top_ptr_; // current node pointer
    ret = false; // initialize return value to false
    while (curr != nullptr) { // traverse the list
        if (curr->data == data) { // if the data is found
            ret = true; // set return value to true
            break; // exit the loop
        }
        curr = curr->next; // move to the next node
    }
    return ret; // return the value
}

node* LinkedList::get_top() {
    return top_ptr_; // return the top pointer
}

void LinkedList::set_top(node* top_ptr) {
    top_ptr_ = top_ptr; // set the top pointer
}

int main() {
    LinkedList list; // create a linked list
    list.append_data(1); // append data to the list
    list.append_data(2);
    list.append_data(3);
    cout << "List after appending 1, 2, 3: " << list.report() << endl; // report the list

    list.insert_data(1, 4); // insert data at offset 1
    cout << "List after inserting 4 at offset 1: " << list.report() << endl; // report the list

    list.remove(2); // remove data at offset 2
    cout << "List after removing data at offset 2: " << list.report() << endl; // report the list

    cout << "Size of the list: " << list.size() << endl; // report the size of the list

    cout << "List contains 3: " << (list.contains(3) ? "true" : "false") << endl; // check if the list contains 3
    cout << "List contains 5: " << (list.contains(5) ? "true" : "false") << endl; // check if the list contains 5

    return 0;
}
   