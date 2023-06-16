//Queue using array and queue problems

#include <iostream>

using namespace std;

template<class T>
class queue
{
private:
    int size;
    int length;
    T *arr;

public:

        queue()
        {
            size = 100;
            length = 0;
            arr = new T[size];
        }

        queue(int s)
        {
            size = s;
            length = 0;
            arr = new T[size];
        }

        void enqueue(T item)
        {
            arr[length] = item;
            length++;

        }

        T dequeue()
        {
            T temp = arr[0];
            for(int i=0; i<length; i++)
            {
                arr[i] = arr[i+1];
            }
            length--;
            return temp;
        }

       T first()
        {
            return arr[0];
        }

        bool isEmpty()
        {
            if(length == 0)
                return true;
            else
                return false;
        }

        int Size()
        {
            return length;
        }
        void  clear()
        {
            length = 0;
        }

        void print()
        {
            for(int i=0; i<length; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        //function to print all binary numbers from 1 to n
        void binary(int n)
        {
            queue<string> q;
            q.enqueue("1");
            while(n--)
            {
                string s1 = q.dequeue();
                cout<<s1<<endl;
                string s2 = s1;
                q.enqueue(s1.append("0"));
                q.enqueue(s2.append("1"));
            }
        }

        void sort()
        {
            for(int i=0; i<length; i++)
            {
                for(int j=0; j<length-1; j++)
                {
                    if(arr[j] > arr[j+1])
                    {
                        T temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
        }


};
template<class T>
class stack
{
private:
    queue<T> q1;
    queue<T> q2;
public:
    void push(T element)
    {
        q1.enqueue(element);
    }
    T pop()
    {
        while(q1.Size() != 1)
        {
            q2.enqueue(q1.dequeue());
        }
        T temp = q1.dequeue();
        while(!q2.isEmpty())
        {
            q1.enqueue(q2.dequeue());
        }
        return temp;
    }
    void print()
    {
        q1.print();
    }

};

int main()
{
//test sort
    queue<int> q1;
    q1.enqueue(3);
    q1.enqueue(15);
    q1.enqueue(2);
    q1.enqueue(4);
    q1.print();
    q1.sort();
    q1.print();
}