
#include "TreeSet.h"

void test() {
    TreeSet<int> treeboi;
    int arr[7] = {1,2,1,5,2,7,9};
    for(int i = 0; i < 7; i ++) {
        treeboi.insert(arr[i]);
    }

    if(treeboi.isEmpty())
        std::cout << "empty" << std::endl;
    else
        std::cout << "not empty" << std::endl;

    TreeSet<int> leafyboi;

//    leafyboi.copyFrom(treeboi.getNode());

    treeboi.display();
//    treeboi.copyFrom().display();

    leafyboi = treeboi;

//    leafyboi.display();

//    leafyboi = treeboi;


    treeboi.insert(8);

    treeboi.display();

    leafyboi.display();



//    leafyboi.copyTo(treeboi);

//    std::cout << "\n";

//    treeboi.display();

   // leafyboi = treeboi;

    if(leafyboi.isEmpty())
        std::cout << "empty" << std::endl;
    else
        std::cout << "not empty" << std::endl;
};

int main() {
    test();
};

//TreeSet(const TreeSet &original){
//
//    BSTNode<Item>* localRoot = original.mRoot;
//    copyFrom(mRoot, localRoot);
//}
//
//// Overloaded Assignment Operator
//TreeSet &operator= (TreeSet tree) {
//    copyFrom(mRoot, tree.mRoot);
//}