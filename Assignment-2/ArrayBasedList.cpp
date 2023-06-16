//array based list

#include <iostream>

using namespace std;

template<class T>
class arrayList
{
private:
    int size;
    int length;
    T *arr;

public:

    arrayList()
    {
        size = 100;
        length = 0;
        arr = new T[size];
    }

    arrayList(int s)
    {
        size = s;
        length = 0;
        arr = new T[size];
    }
    void insert(T item)
    {
        arr[length] = item;
        length++;

    }
    void insertAt(T element, int index)
    {
        for(int i=length; i>index; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[index] = element;
        length++;
    }


    T retrieveAt(int index)
    {
        return arr[index];
    }

    void removeAt(int index)
    {

        for(int i=index; i<length; i++)
        {
            arr[i] = arr[i+1];
        }
        length--;
    }

    void replaceAt(T element, int index)
    {
        arr[index] = element;
    }

    bool isItemAtEqual(T element, int index)
    {
        if(arr[index]==element)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isEmpty()
    {
        if(length==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if(length==size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int listSize()
    {
        return length;
    }

    int maxListSize()
    {
        return size;
    }

    void clear()
    {
        length = 0;
    }

    void print()
    {
        for(int i=0; i<length; i++)
        {
            cout<<arr[i]<<" ";
        }
    }

};

int main()
{

    arrayList<int> a(5);
    a.insert(5);
    a.insert(4);
    a.insert(3);
    a.insert(2);
    a.insert(1);
    a.print();
    cout<<endl;
    a.insertAt(6, 2);
    a.print();
    cout<<endl;
    cout<<a.retrieveAt(2)<<endl;
    a.removeAt(2);
    a.print();
    cout<<endl;
    a.replaceAt(7, 2);
    a.print();
    cout<<endl;
    cout<<a.isItemAtEqual(7, 2)<<endl;
    cout<<a.isEmpty()<<endl;
    cout<<a.isFull()<<endl;
    cout<<a.listSize()<<endl;
    cout<<a.maxListSize()<<endl;
    a.clear();
    a.print();
    cout<<endl;

    return 0;
}










