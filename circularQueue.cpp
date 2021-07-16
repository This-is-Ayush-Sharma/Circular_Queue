#include <bits/stdc++.h>

using namespace std;

class CircularQueue
{
private:
    int front, rear, size = 5;
    int arr[5];

public:
    CircularQueue()
    {
        front = rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if ((rear + 1) % size == front)
            return true;
        else
            return false;
    }
    void Enqueue(int val)
    {
        if (isFull())
        {
            cout << "The Queue is Full.." << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = front = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
    }
    int Dequeue()
    {
        int x;
        if (isEmpty())
        {
            cout << "The Queue is Empty.." << endl;
            return 0;
        }
        else if (front == rear)
        {
            x = arr[front];
            front = rear = -1;
        }
        else
        {
            x = arr[front];
            arr[front]=0;
            front = (front + 1) % size;
        }
        return x;
    }
    int count()
    {
        return ((rear - front) + 1);
    }
    void dispaly()
    {
        cout << "The value are:-" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    CircularQueue p;
    int option, item;
    do
    {
        cout << ">>>>>>>>>>>>>>>>>The available options are:-<<<<<<<<<<<<<<<<\n";
        cout << "                      1. ENQUEUE\n";
        cout << "                      2. DEQUEUE\n";
        cout << "                      3. isEmpty()\n";
        cout << "                      4. isFull()\n";
        cout << "                      5. COUNT()\n";
        cout << "                      6. DISPLAY\n";
        cout << "                      7. CLEAR SCREEN\n";
        cout << "               0. <<<<<<<<TO EXIT>>>>>>>\n";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Please enter the value:-";
            cin >> item;
            p.Enqueue(item);
            break;
        case 2:
            cout << "The value is:-" << p.Dequeue() << endl;
            break;
        case 3:
            if (p.isEmpty())
            {
                cout << "The Queue is Empty.." << endl;
            }
            else
            {
                cout << "The Queue is Not Empty.." << endl;
            }
            break;
        case 4:
            if (p.isFull())
            {
                cout << "The Queue is Full.." << endl;
            }
            else
            {
                cout << "The Queue is Not Full.." << endl;
            }
            break;
        case 5:
            cout << "The Total values are:-" << p.count() << endl;
            break;
        case 6:
            p.dispaly();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << ">>>TERMINATING THE CODE FOR YOU<<<" << endl;
            break;
        }
    } while (option != 0);
    return 0;
}