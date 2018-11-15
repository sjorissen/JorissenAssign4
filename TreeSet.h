// Sarah Jorissen
// CSCI 3250
// Assignment 4

#ifndef JORISSENASSIGN4_TREESET_H
#define JORISSENASSIGN4_TREESET_H

#include <iostream>
#include "Set.hpp"

template<typename Item>
struct BSTNode {
    Item  item;
    BSTNode* left;
    BSTNode* right;
    BSTNode(Item itemValue, BSTNode* leftPtr = nullptr, BSTNode* rightPtr = nullptr) {
        item = itemValue;
        left = leftPtr;
        right = rightPtr;
    }
};

template <typename Item>
class TreeSet: public Set<Item> {
private:
    BSTNode<Item>* mRoot;
    int mSize;
    void clear(BSTNode<Item>* root) {
        if(root != nullptr) {
            clear(root->left);
            clear(root->right);
            delete root;
        }
    }
    // does not add duplicates
    BSTNode<Item>* insert(BSTNode<Item>* root, const Item &item) {
        if(root == nullptr)
            return new BSTNode<Item>(item);
        if(item < root->item)
            root->left = insert(root->left, item);
        else
            root->right = insert(root->right, item);
        return root;
    }

    BSTNode<Item>* getMin(BSTNode<Item>* root) {
        if(root->left == nullptr)
            return root;
        else
            return getMin(root->left);
    }

    BSTNode<Item>* deleteMin(BSTNode<Item>* root) {
        if(root->left == nullptr)
            return root->right;
        else {
            root->left = deleteMin(root->left);
            return root;
        }
    }

    // Make void, return nothing, remove exception?
    BSTNode<Item>* remove(BSTNode<Item>* root, const Item &item) {
//        if(root == nullptr)
//            throw new out_of_range();
        if(item < root->item)
            root->left = remove(root->left, item);
        else if(item > root->item)
            root->right = remove(root->right, item);
        else {
            BSTNode<Item>* temp = root;
            if(root->left == nullptr) {
                root = root->right;
                delete temp;
            }
            else if(root->right == nullptr) {
                root = root->left;
                delete temp;
            }
            else {
                temp = getMin(root->right);
                root->item = temp->item;
                root->right = deleteMin(root->right);
                delete temp;
            }
        }
        return root;
    }

    bool contains(BSTNode <Item>* root, const Item &item) const {
        if(root == nullptr) {
            return false;
        }
        else if(item < root ->item)
            return contains(root->left, item);
        else if(item > root ->item)
            return contains(root->right, item);
        else
            return root ->item;
    }

    void display(BSTNode<Item>* root) const {
        if(root == nullptr) {
            return;
        }
        display(root->left);
        std::cout << root->item << " ";

        display(root->right);
    }

    // copy_from
    void copyFrom(BSTNode<Item>* &copy, BSTNode<Item>* &root) {
        if(root == nullptr) {
            return;
        }

        copy = new BSTNode<Item>(root->item);
        copyFrom(copy->left, root->left);
        copyFrom(copy->right, root->right);
    }

    // A recursive addItemsInSet that inserts all items in the set and in a second set into a third set
    //Item addItemsInSet(Set set1, Set set2) {
        // copyTo(), contains(), & insert()
    //}

    // A recursiveaddItemsNotInSetthat inserts all items in the set but not in a second set into a third set
    // copyTo(), contains(), & insert()

public:
    // Constructor
    TreeSet() {
        mRoot = nullptr;
        mSize = 0;
    }

    // Copy Constructor
    TreeSet(const TreeSet &original){

        BSTNode<Item>* localRoot = original.mRoot;
        copyFrom(mRoot, localRoot);
    }

    // Overloaded Assignment Operator
    TreeSet &operator= (TreeSet tree) {
        copyFrom(mRoot, tree.mRoot);
    }

    // Destructor
    ~TreeSet() {
        clear(mRoot);
    }

    int size() const { return mSize; }


    void insert(const Item &item) {
        mRoot = insert(mRoot, item);
        mSize++;
    }

    void remove(const Item& item) {
        mRoot = remove(mRoot, item);
        mSize--;
    }

    bool contains(const Item& item) const {
        return contains(mRoot, item);
    }

    void setUnion(const Set<Item>& set2, Set<Item>& result) const {

    }

    void setIntersection(const Set<Item>& set2, Set<Item>& result) const {

    }

    void setDifference(const Set<Item>& set2, Set<Item>& result) const {

    }

    // A recursive copyTo that does a preorder traversal of the tree, and inserts the item at each node it visits into the other set
    // clear() (not required actually) set you are copying to, insert() to copy from treeset you want to copy from
    void copyTo(Set<Item> &set) const {
//        set.display();
//        copyFrom(mRoot, set.mRoot);


        // use copyFrom

      //  copyFrom(set, mRoot);
    }

    void display() const {
        BSTNode<Item>* root = mRoot;
        display(root);
        std::cout << std::endl;
    }

    bool isEmpty() const {
        return mRoot == nullptr;
    }

    void clear() {
        clear(mRoot);
        mRoot = nullptr;
        mSize = 0;
    }

//    TreeSet copyFrom(){
//        TreeSet<Item> boi;
//        copyFrom(boi.mRoot, mRoot);
//        return boi;
//    }

};



#endif //JORISSENASSIGN4_TREESET_H
