#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a student
struct Student1 {
    int id;
    string name;
    double gpa;
    string department;
};


// Max Heap Node
struct MaxHeapNode {
    MaxHeapNode() {

    }

    MaxHeapNode(Student1 student) {
        this->student = student;
    }

    Student1 student;
};


// Max Heap Class
class MaxHeap {
public:
    MaxHeap(){
        heap.push_back(MaxHeapNode());
    }

    void addStudent(Student1 student){
        heap.push_back(MaxHeapNode(student));
        heapifyUp(heap.size() - 1);
    }
    void printAllStudents(){
        for (int i = 1; i < heap.size(); i++) {
            cout << heap[i].student.id << " " << heap[i].student.name << " " << heap[i].student.department << endl;
        }
    }

private:
    vector<MaxHeapNode> heap;

    void heapifyUp(int index){
        if (index == 1) {
            return;
        }
        int parentIndex = index / 2;
        if (heap[parentIndex].student.id < heap[index].student.id) {
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
        int maxIndex = index;
        if (heap[maxIndex].student.id < heap[leftChildIndex].student.id) {
            maxIndex = leftChildIndex;
        }
        if (rightChildIndex < heap.size() && heap[maxIndex].student.id < heap[rightChildIndex].student.id) {
            maxIndex = rightChildIndex;
        }
        if (maxIndex != index) {
            swap(heap[maxIndex], heap[index]);
            heapifyDown(maxIndex);
        }
    }
};


void displayMaxHeapMenu(MaxHeap& maxHeap){
    cout << "1. Add a student" << endl;
    cout << "2. Print all students" << endl;
    cout << "3. Back to main menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    Student1 student;
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
            maxHeap.addStudent(student);
        }break;

        case 2:{
            maxHeap.printAllStudents();
        }break;
        case 3:
            return;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    displayMaxHeapMenu(maxHeap);
}