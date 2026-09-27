#include <iostream>
using namespace std;

// ============================================================
// Node Class
// ============================================================
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

// ============================================================
// Singly Linked List Class
// ============================================================
class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Destructor: releases all dynamically allocated nodes.
    ~LinkedList()
    {
        while (head != NULL)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // O(1)
    bool isEmpty()
    {
        return head == NULL;
    }

    // O(n)
    void display()
    {
        if (isEmpty())
        {
            cout << "\nLinked List is empty.\n";
            return;
        }

        Node* temp = head;

        cout << "\nLinked List: ";

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Insert at beginning - O(1)
    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        cout << "\nNode inserted at beginning.\n";
    }

    // Insert at end - O(n)
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            cout << "\nNode inserted at end.\n";
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        cout << "\nNode inserted at end.\n";
    }

    // Insert at a particular index - O(n)
    void insertAtPosition(int position, int value)
    {
        if (position < 0)
        {
            cout << "\nInvalid position.\n";
            return;
        }

        if (position == 0)
        {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "\nInvalid position.\n";
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "\nNode inserted at position " << position << ".\n";
    }

    // Insert before first occurrence of target - O(n)
    void insertBefore(int target, int value)
    {
        if (head == NULL)
        {
            cout << "\nLinked List is empty.\n";
            return;
        }

        // Target is the first node.
        if (head->data == target)
        {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;

        // Find the node immediately before target.
        while (temp->next != NULL && temp->next->data != target)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "\nTarget element not found.\n";
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "\nNode inserted before " << target << ".\n";
    }

    // Insert after first occurrence of target - O(n)
    void insertAfter(int target, int value)
    {
        Node* temp = head;

        while (temp != NULL && temp->data != target)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "\nTarget element not found.\n";
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "\nNode inserted after " << target << ".\n";
    }

    // Delete from beginning - O(1)
    void deleteFromBeginning()
    {
        if (head == NULL)
        {
            cout << "\nLinked List is empty. Underflow!\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "\nFirst node deleted.\n";
    }

    // Delete from end - O(n)
    void deleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "\nLinked List is empty. Underflow!\n";
            return;
        }

        // Only one node.
        if (head->next == NULL)
        {
            delete head;
            head = NULL;

            cout << "\nLast node deleted.\n";
            return;
        }

        Node* temp = head;

        // Find the second-last node.
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;

        cout << "\nLast node deleted.\n";
    }

    // Delete from a particular index - O(n)
    void deleteFromPosition(int position)
    {
        if (head == NULL)
        {
            cout << "\nLinked List is empty. Underflow!\n";
            return;
        }

        if (position < 0)
        {
            cout << "\nInvalid position.\n";
            return;
        }

        if (position == 0)
        {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;

        for (int i = 0; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            cout << "\nInvalid position.\n";
            return;
        }

        Node* nodeToDelete = temp->next;

        temp->next = nodeToDelete->next;

        delete nodeToDelete;

        cout << "\nNode at position " << position << " deleted.\n";
    }

    // Delete first occurrence of a given element - O(n)
    void deleteElement(int target)
    {
        if (head == NULL)
        {
            cout << "\nLinked List is empty. Underflow!\n";
            return;
        }

        if (head->data == target)
        {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->data != target)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "\nElement not found.\n";
            return;
        }

        Node* nodeToDelete = temp->next;

        temp->next = nodeToDelete->next;

        delete nodeToDelete;

        cout << "\nElement " << target << " deleted.\n";
    }

    // Linear search - O(n)
    // Returns index if found; otherwise returns -1.
    int search(int key)
    {
        Node* temp = head;
        int index = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return index;
            }

            temp = temp->next;
            index++;
        }

        return -1;
    }

    // Update first occurrence of oldValue - O(n)
    void update(int oldValue, int newValue)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->data == oldValue)
            {
                temp->data = newValue;

                cout << "\nNode updated successfully.\n";
                return;
            }

            temp = temp->next;
        }

        cout << "\nElement not found.\n";
    }
};

// ============================================================
// Main Function
// ============================================================
int main()
{
    LinkedList list;

    // Initial data for demonstration.
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    int choice;
    int value;
    int target;
    int position;
    int oldValue;
    int newValue;
    int index;

    do
    {
        cout << "\n\n============================================\n";
        cout << "       SINGLY LINKED LIST OPERATIONS\n";
        cout << "============================================\n";
        cout << "1.  Display List\n";
        cout << "2.  Insert at Beginning\n";
        cout << "3.  Insert at End\n";
        cout << "4.  Insert at Position\n";
        cout << "5.  Insert Before an Element\n";
        cout << "6.  Insert After an Element\n";
        cout << "7.  Delete from Beginning\n";
        cout << "8.  Delete from End\n";
        cout << "9.  Delete from Position\n";
        cout << "10. Delete an Element\n";
        cout << "11. Search Element\n";
        cout << "12. Update a Node\n";
        cout << "13. Exit\n";
        cout << "============================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.display();
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 4:
            cout << "Enter position (0-based): ";
            cin >> position;

            cout << "Enter value: ";
            cin >> value;

            list.insertAtPosition(position, value);
            break;

        case 5:
            cout << "Enter target element: ";
            cin >> target;

            cout << "Enter value to insert: ";
            cin >> value;

            list.insertBefore(target, value);
            break;

        case 6:
            cout << "Enter target element: ";
            cin >> target;

            cout << "Enter value to insert: ";
            cin >> value;

            list.insertAfter(target, value);
            break;

        case 7:
            list.deleteFromBeginning();
            break;

        case 8:
            list.deleteFromEnd();
            break;

        case 9:
            cout << "Enter position (0-based): ";
            cin >> position;

            list.deleteFromPosition(position);
            break;

        case 10:
            cout << "Enter element to delete: ";
            cin >> target;

            list.deleteElement(target);
            break;

        case 11:
            cout << "Enter element to search: ";
            cin >> target;

            index = list.search(target);

            if (index == -1)
                cout << "\nElement not found.\n";
            else
                cout << "\nElement found at index: " << index << endl;

            break;

        case 12:
            cout << "Enter old value: ";
            cin >> oldValue;

            cout << "Enter new value: ";
            cin >> newValue;

            list.update(oldValue, newValue);
            break;

        case 13:
            cout << "\nProgram ended.\n";
            break;

        default:
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 13);

    return 0;
}
