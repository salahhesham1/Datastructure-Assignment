#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Structure to represent a student
struct Student3 {
    int id;
    string name;
    double gpa;
    string department;
};


// AVL Tree Node
struct AVLNode {
    Student3 student;
    int height;
    AVLNode* left;
    AVLNode* right;
};

// AVL Tree Class
class AVLTree {
public:
    AVLTree(){
        root = NULL;
    }
    void addStudent(Student3 student){
        root = insertNode(root, student);
    }
    void removeStudent(int id){
        root = deleteNode(root, id);
    }
    void searchStudent(int id){
        AVLNode* node = root;
        while (node != NULL) {
            if (id == node->student.id) {
                cout << "Student ID: " << node->student.id << endl;
                cout << "Student Name: " << node->student.name << endl;
                cout << "Student GPA: " << node->student.gpa << endl;
                cout << "Student Department: " << node->student.department << endl;
                return;
            }
            else if (id < node->student.id) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        cout << "Student not found." << endl;
    }
    void printAllStudents(){
        inOrderTraversal(root);
    }
    void generateDepartmentReport(){
        map<string, int> departmentCount;
        countStudentsByDepartment(root, departmentCount);
        for (auto it = departmentCount.begin(); it != departmentCount.end(); it++) {
            cout << it->first << ": " << it->second << endl;
        }
    }

private:
    AVLNode* root;

    AVLNode* insertNode(AVLNode* node, Student3 student){
        if (node == NULL) {
            AVLNode* newNode = new AVLNode;
            newNode->student = student;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->height = 1;
            return newNode;
        }
        else if (student.id < node->student.id) {
            node->left = insertNode(node->left, student);
        }
        else {
            node->right = insertNode(node->right, student);
        }
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balance = getBalance(node);
        if (balance > 1 && student.id < node->left->student.id) {
            return rotateRight(node);
        }
        if (balance < -1 && student.id > node->right->student.id) {
            return rotateLeft(node);
        }
        if (balance > 1 && student.id > node->left->student.id) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && student.id < node->right->student.id) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }
    AVLNode* deleteNode(AVLNode* node, int id){
        if (node == NULL) {
            return NULL;
        }
        else if (id < node->student.id) {
            node->left = deleteNode(node->left, id);
        }
        else if (id > node->student.id) {
            node->right = deleteNode(node->right, id);
        }
        else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            else if (node->left == NULL) {
                AVLNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                AVLNode* temp = node->left;
                delete node;
                return temp;
            }
            else {
                AVLNode* minNode = findMin(node->right);
                node->student = minNode->student;
                node->right = deleteNode(node->right, minNode->student.id);
            }
        }
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balance = getBalance(node);
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rotateRight(node);
        }
        if (balance < -1 && getBalance(node->right) <= 0) {
            return rotateLeft(node);
        }
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }
    AVLNode* findMin(AVLNode* node){
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    AVLNode* rotateRight(AVLNode* node){
        AVLNode* leftChild = node->left;
        AVLNode* rightGrandChild = leftChild->right;
        leftChild->right = node;
        node->left = rightGrandChild;
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;
        return leftChild;
    }
    AVLNode* rotateLeft(AVLNode* node){
        AVLNode* rightChild = node->right;
        AVLNode* leftGrandChild = rightChild->left;
        rightChild->left = node;
        node->right = leftGrandChild;
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        rightChild->height = max(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;
        return rightChild;
    }
    int getHeight(AVLNode* node){
        if (node == NULL) {
            return 0;
        }
        return node->height;
    }
    int getBalance(AVLNode* node){
        if (node == NULL) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }
    void inOrderTraversal(AVLNode* node){
        if (node == NULL) {
            return;
        }
        inOrderTraversal(node->left);
        cout << node->student.id << " " << node->student.name << " " << node->student.department << endl;
        inOrderTraversal(node->right);
    }
    void countStudentsByDepartment(AVLNode* node, map<string, int>& departmentCount){
        if (node == NULL) {
            return;
        }
        countStudentsByDepartment(node->left, departmentCount);
        departmentCount[node->student.department]++;
        countStudentsByDepartment(node->right, departmentCount);
    }
};


void displayAVLMenu(AVLTree& avl){
    cout << "1. Add a student" << endl;
    cout << "2. Search for a student" << endl;
    cout << "3. Print all students" << endl;
    cout << "4. Back to main menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    Student3 student;
    switch (choice) {
        case 1:{
            cout << "Enter student id: ";
            int id;
            cin >> id;
            cout << "Enter student name: ";
            string name;
            cin >> name;
            cout << "Enter student department: ";
            string department;
            cin >> department;
            cout << "Enter student GPA: ";
            double gpa;
            cin >> gpa;
            student.id = id;
            student.name = name;
            student.department = department;
            student.gpa = gpa;
            avl.addStudent(student);
        }break;
        case 2: {
            cout << "Enter student id: ";
            int id;
            cin >> id;
            avl.searchStudent(id);
        }    break;

        case 3:{
            avl.printAllStudents();
        }break;
        case 4:
            return;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    displayAVLMenu(avl);
}