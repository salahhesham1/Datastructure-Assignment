#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Structure to represent a student
struct Student {
    int id;
    string name;
    double gpa;
    string department;
};


// Binary Search Tree Node
struct BSTNode {
    Student student;
    BSTNode* left;
    BSTNode* right;
};
// Binary Search Tree Class
class BinarySearchTree {
public:
    BinarySearchTree(){
        root = NULL;
    }
    void addStudent(Student student){
        root = insertNode(root, student);

    }
    void removeStudent(int id){
        root = deleteNode(root, id);
    }
    void searchStudent(int id){
        BSTNode* node = root;
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
    BSTNode* root;

    BSTNode* insertNode(BSTNode* node, Student student){
        if (node == NULL) {
            BSTNode* newNode = new BSTNode;
            newNode->student = student;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }
        else if (student.id < node->student.id) {
            node->left = insertNode(node->left, student);
        }
        else {
            node->right = insertNode(node->right, student);
        }
        return node;
    }
    BSTNode* deleteNode(BSTNode* node, int id){
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
                BSTNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }
            else {
                BSTNode* minNode = findMin(node->right);
                node->student = minNode->student;
                node->right = deleteNode(node->right, minNode->student.id);
            }
        }
        return node;
    }
    BSTNode* findMin(BSTNode* node){
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    void inOrderTraversal(BSTNode* node){
        if (node != NULL) {
            inOrderTraversal(node->left);
            cout << "Student ID: " << node->student.id << endl;
            cout << "Student Name: " << node->student.name << endl;
            cout << "Student GPA: " << node->student.gpa << endl;
            cout << "Student Department: " << node->student.department << endl;
            cout << endl;
            inOrderTraversal(node->right);
        }
    }
    void countStudentsByDepartment(BSTNode* node, map<string, int>& departmentCount){
        if (node != NULL) {
            countStudentsByDepartment(node->left, departmentCount);
            departmentCount[node->student.department]++;
            countStudentsByDepartment(node->right, departmentCount);
        }
    }
};

void displayBSTMenu(BinarySearchTree& bst){
    cout << "1. Add a student" << endl;
    cout << "2. Search for a student" << endl;
    cout << "3. Print all students" << endl;
    cout << "4. Back to main menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    Student student;
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
            bst.addStudent(student);
        }break;
        case 2: {
            cout << "Enter student id: ";
            int id;
            cin >> id;
            bst.searchStudent(id);
        }    break;

        case 3:{
            bst.printAllStudents();
        }break;
        case 4:
            return;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    displayBSTMenu(bst);
}

