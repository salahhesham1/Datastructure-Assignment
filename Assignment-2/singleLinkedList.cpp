//single linked list and linked list problems

#include <iostream>

using namespace std;

template <class T>
class singleLinkedList {
private:
    struct node {
        T data;
        node *next;

    };
    node *head;
    node *tail;
    int length;
public:
    singleLinkedList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void insertAtHead(T element) {
        node *temp = new node;
        temp->data = element;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        length++;
    }

    void insertAtTail(T element) {
        node *temp = new node;
        temp->data = element;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        length++;
    }

    void insertAt(T element, int index) {
        if (index == 0) {
            insertAtHead(element);
        } else if (index == length) {
            insertAtTail(element);
        } else {
            node *temp = new node;
            temp->data = element;
            temp->next = NULL;
            node *current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
            length++;
        }
    }

    void removeAtHead() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        } else {
            node *temp = head;
            head = head->next;
            delete temp;
            length--;
        }
    }

    void removeAtTail() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        } else {
            node *current = head;
            node *temp = tail;
            while (current->next != tail) {
                current = current->next;
            }
            tail = current;
            tail->next = NULL;
            delete temp;
            length--;
        }
    }

    void removeAt(int index) {
        if (index == 0) {
            removeAtHead();
        } else if (index == length - 1) {
            removeAtTail();
        } else {
            node *current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            node *temp = current->next;
            current->next = temp->next;
            delete temp;
            length--;
        }
    }

    T retrieveAt(int index) {
        node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    void replaceAt(T element, int index) {
        node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = element;
    }

    bool isExist(T element) {
        node *current = head;
        while (current != NULL) {
            if (current->data == element) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool isItemEqual(T element, int index) {
        node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        if (current->data == element) {
            return true;
        }
        return false;
    }

//swap two nodes without swapping data
    void swap(int index1, int index2) {
        if (index1 == index2) {
            // No need to swap if the indices are the same
            return;
        }

        // Find the nodes at index1 and index2
        node *prev1 = nullptr;
        node *node1 = head;
        for (int i = 0; i < index1 && node1 != nullptr; i++) {
            prev1 = node1;
            node1 = node1->next;
        }
        node *prev2 = nullptr;
        node *node2 = head;
        for (int i = 0; i < index2 && node2 != nullptr; i++) {
            prev2 = node2;
            node2 = node2->next;
        }

        // If either index is out of bounds, return
        if (node1 == nullptr || node2 == nullptr) {
            return;
        }

        // Swap the nodes
        if (prev1 != nullptr) {
            prev1->next = node2;
        } else {
            head = node2;
        }
        if (prev2 != nullptr) {
            prev2->next = node1;
        } else {
            head = node1;
        }
        node *temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
    }

    bool isEmpty() {
        if (head == NULL) {
            return true;
        }
        return false;
    }

    int size() {
        return length;
    }

    void clear() {
        while (head != NULL) {
            node *temp = head;
            head = head->next;
            delete temp;
        }
        length = 0;
    }

    void print() {
        node *current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void combineNodesBetweenZeros() {
        node *current = head;
        while (current != NULL) {
            if (current->data == 0) {
                node *temp = current->next;
                while (temp != NULL && temp->data != 0) {
                    current->data += temp->data;
                    node *temp2 = temp;
                    temp = temp->next;
                    delete temp2;
                    length--;
                }
                current->next = temp;
            }
            current = current->next;
        }
        removeAtTail();
    }

};
int main()
{

    return 0;
}