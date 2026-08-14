#include <iostream>
using namespace std;


// =====================================================
// NODE CLASS
// =====================================================

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};


// =====================================================
// STACK CLASS
// Stack implemented using Singly Linked List
// TOP is represented by the head pointer.
// =====================================================

class Stack
{
private:
    Node* top;

public:

    // Constructor
    Stack()
    {
        top = NULL;
    }


    // Check whether Stack is empty
    // Time Complexity: O(1)
    bool isEmpty()
    {
        return top == NULL;
    }


    // Push an element
    // Time Complexity: O(1)
    void push(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = top;

        top = newNode;

        cout << "\n"
             << value
             << " pushed into Stack.\n";
    }


    // Pop an element
    // Time Complexity: O(1)
    int pop()
    {
        if (isEmpty())
        {
            cout << "\nStack Underflow!\n";
            return -1;
        }

        Node* temp = top;

        int value = temp->data;

        top = top->next;

        delete temp;

        return value;
    }


    // Peek top element
    // Time Complexity: O(1)
    int peek()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty.\n";
            return -1;
        }

        return top->data;
    }


    // Display Stack
    // Time Complexity: O(n)
    void display()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty.\n";
            return;
        }

        Node* current = top;

        cout << "\nStack:\n";

        while (current != NULL)
        {
            cout << current->data << endl;

            current = current->next;
        }
    }


    // Destructor
    // Releases all dynamically allocated nodes.
    // Time Complexity: O(n)
    ~Stack()
    {
        Node* current = top;

        while (current != NULL)
        {
            Node* nextNode = current->next;

            delete current;

            current = nextNode;
        }

        top = NULL;
    }
};


// =====================================================
// MAIN FUNCTION
// =====================================================

int main()
{
    Stack s;

    int choice;
    int value;

    do
    {
        cout << "\n=================================\n";
        cout << "       STACK USING LINKED LIST\n";
        cout << "=================================\n";

        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Is Empty\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "=================================\n";

        cout << "Enter your choice: ";
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
            {
                cout << "Popped value: "
                     << value << endl;
            }

            break;


        case 3:

            value = s.peek();

            if (value != -1)
            {
                cout << "Top element: "
                     << value << endl;
            }

            break;


        case 4:

            if (s.isEmpty())
            {
                cout << "\nStack is empty.\n";
            }
            else
            {
                cout << "\nStack is not empty.\n";
            }

            break;


        case 5:

            s.display();

            break;


        case 6:

            cout << "\nProgram ended.\n";

            break;


        default:

            cout << "\nInvalid choice.\n";
        }

    } while (choice != 6);


    return 0;
}