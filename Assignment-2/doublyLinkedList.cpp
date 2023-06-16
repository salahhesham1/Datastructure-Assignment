//Doubly Linked List

#include <iostream>

using namespace std;

template<class T>
class doublyLinkedList
{
private:
    struct node
    {
        T data;
        node *next;
        node *prev;
    };
    node *head;
    node *tail;
    int length;
public:
    doublyLinkedList()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    void insertAtHead(T element)
    {
        node *temp = new node;
        temp->data = element;
        temp->next = NULL;
        temp->prev = NULL;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        length++;
    }

    void insertAtTail(T element)
    {
        node *temp = new node;
        temp->data = element;
        temp->next = NULL;
        temp->prev = NULL;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        length++;
    }

    void insertAt(T element, int index)
    {
        if(index == 0)
        {
            insertAtHead(element);
        }
        else if(index == length)
        {
            insertAtTail(element);
        }
        else
        {
            node *temp = new node;
            temp->data = element;
            temp->next = NULL;
            temp->prev = NULL;
            node *current = head;
            for(int i=0; i<index-1; i++)
            {
                current = current->next;
            }
            temp->next = current->next;
            current->next->prev = temp;
            current->next = temp;
            temp->prev = current;
            length++;
        }
    }

    void insertAfter(node *prev_node , int data)
    {
    if(prev_node == NULL)
        {
            cout<<"The given previous node cannot be NULL";
            return;
        }
        node *temp = new node;
        temp->data = data;
        temp->next = prev_node->next;
        prev_node->next = temp;
        temp->prev = prev_node;
        if(temp->next != NULL)
        {
            temp->next->prev = temp;
        }

    }

    void removeAtHead()
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
        }
        else
        {
            node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            length--;
        }
    }

    void removeAtTail()
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
        }
        else
        {
            node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            length--;
        }
    }

    void removeAt(int index)
    {
        if(index == 0)
        {
            removeAtHead();
        }
        else if(index == length-1)
        {
            removeAtTail();
        }
        else
        {
            node *current = head;
            for(int i=0; i<index-1; i++)
            {
                current = current->next;
            }
            node *temp = current->next;
            current->next = temp->next;
            temp->next->prev = current;
            delete temp;
            length--;
        }
    }

    T retrieveAt(int index)
    {

        node *current = head;
        for(int i=0; i<index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    void replaceAt(T element, int index)
    {
        node *current = head;
        for(int i=0; i<index; i++)
        {
            current = current->next;
        }
        current->data = element;
    }

    bool isExist(T element)
    {
        node *current = head;
        while(current != NULL)
        {
            if(current->data == element)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool isItemEqual(T element, int index)
    {
        node *current = head;
        for(int i=0; i<index; i++)
        {
            current = current->next;
        }
        if(current->data == element)
        {
            return true;
        }
        return false;
    }

    //swap two nodes without swapping data

    void swap(int firstIndex, int secondIndex)
    {
        node *current = head;
        node *firstNode = NULL;
        node *secondNode = NULL;
        for(int i=0; i<firstIndex; i++)
        {
            current = current->next;
        }
        firstNode = current;
        current = head;
        for(int i=0; i<secondIndex; i++)
        {
            current = current->next;
        }
        secondNode = current;
        node *temp = new node;
        temp->data = firstNode->data;
        firstNode->data = secondNode->data;
        secondNode->data = temp->data;
    }

    void reverse()
    {
        node *current = head;
        node *temp = NULL;
        while(current != NULL)
        {
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = current->prev;
        }
        if(temp != NULL)
        {
            head = temp->prev;
        }

        temp = head;
        head = tail;
        tail = temp;

    }

    bool isEmpty()
    {
        if(head == NULL)
        {
            return true;
        }
        return false;
    }

    int size()
    {
        return length;
    }

    void clear()
    {
        node *current = head;
        while(current != NULL)
        {
            node *temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void forwardTraversal()
    {
        node *current = head;
        while(current != NULL)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }

    void backwardTraversal()
    {
        node *current = tail;
        while(current != NULL)
        {
            cout<<current->data<<" ";
            current = current->prev;
        }
        cout<<endl;
    }
    node getHead()
    {
        return head;
    }
};

int main()
{
    doublyLinkedList<int> dll;
    dll.insertAtHead(1);
    dll.insertAtHead(2);
    dll.insertAtHead(3);
    dll.insertAtHead(4);
    dll.insertAtHead(5);

    dll.forwardTraversal();
    dll.backwardTraversal();

    dll.insertAtTail(6);
    dll.insertAtTail(7);
    dll.insertAtTail(8);
    dll.insertAtTail(9);
    dll.insertAtTail(10);

    dll.forwardTraversal();
    dll.backwardTraversal();

    dll.insertAt(11, 0);

    dll.forwardTraversal();
    dll.backwardTraversal();

    dll.insertAt(12, 5);

    dll.forwardTraversal();
    dll.backwardTraversal();

    dll.removeAtHead();
    dll.removeAtTail();
    dll.removeAt(5);

    dll.forwardTraversal();
    dll.backwardTraversal();

    cout<<dll.retrieveAt(0)<<endl;
    cout<<dll.retrieveAt(4)<<endl;

    dll.replaceAt(100, 0);

    dll.forwardTraversal();
    dll.backwardTraversal();

    cout<<dll.isExist(100)<<endl;

    cout<<dll.isItemEqual(100, 0)<<endl;

    dll.swap(0, 4);

    dll.forwardTraversal();
    dll.backwardTraversal();

    dll.reverse();

    dll.forwardTraversal();
    dll.backwardTraversal();

    cout<<dll.isEmpty()<<endl;

    cout<<dll.size()<<endl;

    dll.clear();

    cout<<dll.isEmpty()<<endl;

    cout<<dll.size()<<endl;

    return 0;
}