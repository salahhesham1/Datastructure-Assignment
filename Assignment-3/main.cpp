#include "BST.cpp"
#include "AVL.cpp"
#include "MaxHeap.cpp"
#include "MinHeap.cpp"


// Function to display the main menu
void displayMainMenu(BinarySearchTree& bst, AVLTree& avl, MinHeap& minHeap, MaxHeap& maxHeap){
    cout << "1. Binary Search Tree" << endl;
    cout << "2. AVL Tree" << endl;
    cout << "3. Min Heap" << endl;
    cout << "4. Max Heap" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            displayBSTMenu(bst);
            break;
        case 2:
            displayAVLMenu(avl);
            break;
        case 3:
            displayMinHeapMenu(minHeap);
            break;
        case 4:
            displayMaxHeapMenu(maxHeap);
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    displayMainMenu(bst, avl, minHeap, maxHeap);
}




int main() {
    BinarySearchTree bst;
    AVLTree avl;
    MinHeap minHeap;
    MaxHeap maxHeap;
    displayMainMenu(bst, avl, minHeap, maxHeap);
    return 0;
}