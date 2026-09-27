#include <iostream>
using namespace std;

const int SIZE = 5;

class Stack
{
private:
    int arr[SIZE];
    int top;

public:

    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == SIZE - 1;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "\nStack Overflow!\n";
            return;
        }

        top++;
        arr[top] = value;

        cout << "\n" << value
             << " pushed into Stack.\n";
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "\nStack Underflow!\n";
            return -1;
        }

        int value = arr[top];
        top--;

        return value;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty.\n";
            return -1;
        }

        return arr[top];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty.\n";
            return;
        }

        cout << "\nStack:\n";

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Stack s;

    int choice;
    int value;

    do
    {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Is Empty\n";
        cout << "5. Is Full\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;

            s.push(value);
            break;

        case 2:
            value = s.pop();

            if (value != -1)
                cout << "Popped value: "
                     << value << endl;

            break;

        case 3:
            value = s.peek();

            if (value != -1)
                cout << "Top element: "
                     << value << endl;

            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";

            break;

        case 5:
            if (s.isFull())
                cout << "Stack is full.\n";
            else
                cout << "Stack is not full.\n";

            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}
