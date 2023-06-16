#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a student
struct Student2 {
    int id;
    string name;
    double gpa;
    string department;
};

// Min Heap Node
struct MinHeapNode {
    MinHeapNode() {}
    MinHeapNode(Student2 student) {
        this->student = student;
    }
    Student2 student;
};



// Min Heap Class
class MinHeap {
public:
    MinHeap(){
        heap.push_back(MinHeapNode());
    }
    void addStudent(MinHeapNode student){
        heap.push_back(MinHeapNode(student));
        heapifyUp(heap.size() - 1);
    }
    void printAllStudents(){
        for (int i = 1; i < heap.size(); i++) {
            cout << heap[i].student.id << " " << heap[i].student.name << " " << heap[i].student.department << endl;
        }
    }


private:
    vector<MinHeapNode> heap;

    void heapifyUp(int index){
        if (index == 1) {
            return;
        }
        int parentIndex = index / 2;
        if (heap[parentIndex].student.id > heap[index].student.id) {
            swap(heap[parentIndex], heap[index]);
            heapifyUp(parentIndex);
        }
    }
    void heapifyDown(int index){
        int leftChildIndex = index * 2;
        int rightChildIndex = index * 2 + 1;
        if (leftChildIndex >= heap.size()) {
            return;
        }
        int minIndex = index;
        if (heap[minIndex].student.id > heap[leftChildIndex].student.id) {
            minIndex = leftChildIndex;
        }
        if (rightChildIndex < heap.size() && heap[minIndex].student.id > heap[rightChildIndex].student.id) {
            minIndex = rightChildIndex;
        }
        if (minIndex != index) {
            swap(heap[minIndex], heap[index]);
            heapifyDown(minIndex);
        }
    }
};


void displayMinHeapMenu(MinHeap& minHeap){
    cout << "1. Add a student" << endl;
    cout << "2. Print all students" << endl;
    cout << "3. Back to main menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    Student2 student;
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
            minHeap.addStudent(student);
        }break;

        case 2:{
            minHeap.printAllStudents();
        }break;
        case 3:
            return;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    displayMinHeapMenu(minHeap);
}