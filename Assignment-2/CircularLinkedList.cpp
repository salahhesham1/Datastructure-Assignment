//circular Linked List

#include <iostream>

using namespace std;

template<class T>
class circularLinkedList
{
private:
    struct node
    {
        T data;
        node *next;
    };
    node *head;
    node *tail;
    int length;

public:

    circularLinkedList()
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
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            tail->next = head;
        }
        else
        {
            temp->next = head;
            head = temp;
            tail->next = head;
        }
        length++;
    }

    void insertAtEnd(T element)
    {
        node *temp = new node;
        temp->data = element;
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            tail->next = head;
        }
        else
        {
            tail->next = temp;
            tail = temp;
            tail->next = head;
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
            insertAtEnd(element);
        }
        else
        {
            node *temp = new node;
            temp->data = element;
            temp->next = NULL;
            node *current = head;
            for(int i=0; i<index-1; i++)
            {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
            length++;
        }
    }
    void removeAtHead()
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
            length--;
        }
    }

    void removeAtEnd()
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            node *current = head;
            node *previous = head;
            while(current->next != head)
            {
                previous = current;
                current = current->next;
            }
            tail = previous;
            tail->next = head;
            delete current;
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
            removeAtEnd();
        }
        else
        {
            node *current = head;
            node *previous = head;
            for(int i=0; i<index; i++)
            {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
            delete current;
            length--;
        }
    }

    T retrieve(int index)
    {
        if(index == 0)
        {
            return head->data;
        }
        else if(index == length-1)
        {
            return tail->data;
        }
        else
        {
            node *current = head;
            for(int i=0; i<index; i++)
            {
                current = current->next;
            }
            return current->data;
        }
    }

    void replaceAt(T element, int index)
    {
        if(index == 0)
        {
            head->data = element;
        }
        else if(index == length-1)
        {
            tail->data = element;
        }
        else
        {
            node *current = head;
            for(int i=0; i<index; i++)
            {
                current = current->next;
            }
            current->data = element;
        }
    }

    bool isExist(T element)
    {
        node *current = head;
        while(current->next != head)
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
        if(index == 0)
        {
            return head->data == element;
        }
        else if(index == length-1)
        {
            return tail->data == element;
        }
        else
        {
            node *current = head;
            for(int i=0; i<index; i++)
            {
                current = current->next;
            }
            return current->data == element;
        }
    }
//swap two nodes without swapping data
    void swap(int index1,int index2)
    {
        node *current1 = head;
        node *current2 = head;
        node *previous1 = head;
        node *previous2 = head;
        for(int i=0; i<index1; i++)
        {
            previous1 = current1;
            current1 = current1->next;
        }
        for(int i=0; i<index2; i++)
        {
            previous2 = current2;
            current2 = current2->next;
        }
        previous1->next = current2;
        previous2->next = current1;
        node *temp = current1->next;
        current1->next = current2->next;
        current2->next = temp;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    int size()
    {
        return length;
    }

    void clear()
    {
        while(head != NULL)
        {
            removeAtHead();
        }
    }

    void print()
    {
        node *current = head;
        while(current->next != head)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << current->data << endl;
    }
};