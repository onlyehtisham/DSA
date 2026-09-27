#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node* head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    ~DoublyLinkedList()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    // Forward traversal - O(n)
    void displayForward()
    {
        if (isEmpty())
        {
            cout << "\nDoubly Linked List is empty.\n";
            return;
        }

        Node* temp = head;

        cout << "\nForward: NULL <- ";

        while (temp != NULL)
        {
            cout << temp->data;

            if (temp->next != NULL)
                cout << " <-> ";

            temp = temp->next;
        }

        cout << " -> NULL\n";
    }

    // Backward traversal - O(n)
    // No tail pointer: first reach the last node.
    void displayBackward()
    {
        if (isEmpty())
        {
            cout << "\nDoubly Linked List is empty.\n";
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        cout << "\nBackward: NULL <- ";

        while (temp != NULL)
        {
            cout << temp->data;

            if (temp->prev != NULL)
                cout << " <-> ";

            temp = temp->prev;
        }

        cout << " -> NULL\n";
    }

    // Insert at beginning - O(1)
    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        cout << "\nNode inserted at beginning.\n";
    }

    // Insert at end - O(n), because no tail pointer is used.
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
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;

        cout << "\nNode inserted at end.\n";
    }

    // Insert at a particular position - O(n)
    // Position is 0-based.
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

        Node* current = head;

        for (int i = 0; i < position && current != NULL; i++)
            current = current->next;

        if (current == NULL)
        {
            // Check whether position is exactly after the last node.
            if (head == NULL)
            {
                cout << "\nInvalid position.\n";
                return;
            }

            Node* last = head;
            int lastIndex = 0;

            while (last->next != NULL)
            {
                last = last->next;
                lastIndex++;
            }

            if (position == lastIndex + 1)
                insertAtEnd(value);
            else
                cout << "\nInvalid position.\n";

            return;
        }

        Node* newNode = new Node(value);

        newNode->prev = current->prev;
        newNode->next = current;

        current->prev->next = newNode;
        current->prev = newNode;

        cout << "\nNode inserted at position " << position << ".\n";
    }

    // Insert before first occurrence of target - O(n)
    void insertBefore(int target, int value)
    {
        if (head == NULL)
        {
            cout << "\nDoubly Linked List is empty.\n";
            return;
        }

        Node* current = head;

        while (current != NULL && current->data != target)
            current = current->next;

        if (current == NULL)
        {
            cout << "\nTarget element not found.\n";
            return;
        }

        if (current == head)
        {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);

        newNode->prev = current->prev;
        newNode->next = current;

        current->prev->next = newNode;
        current->prev = newNode;

        cout << "\nNode inserted before " << target << ".\n";
    }

    // Insert after first occurrence of target - O(n)
    void insertAfter(int target, int value)
    {
        if (head == NULL)
        {
            cout << "\nDoubly Linked List is empty.\n";
            return;
        }

        Node* current = head;

        while (current != NULL && current->data != target)
            current = current->next;

        if (current == NULL)
        {
            cout << "\nTarget element not found.\n";
            return;
        }

        Node* newNode = new Node(value);

        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != NULL)
            current->next->prev = newNode;

        current->next = newNode;

        cout << "\nNode inserted after " << target << ".\n";
    }

    // Delete from beginning - O(1)
    void deleteFromBeginning()
    {
        if (head == NULL)
        {
            cout << "\nDoubly Linked List is empty. Underflow!\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;

        cout << "\nFirst node deleted.\n";
    }

    // Delete from end - O(n), because no tail pointer is used.
    void deleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "\nDoubly Linked List is empty. Underflow!\n";
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;

            cout << "\nLast node deleted.\n";
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;

        cout << "\nLast node deleted.\n";
    }

    // Delete from a particular position - O(n)
    void deleteFromPosition(int position)
    {
        if (head == NULL)
        {
            cout << "\nDoubly Linked List is empty. Underflow!\n";
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

        Node* current = head;

        for (int i = 0; i < position && current != NULL; i++)
            current = current->next;

        if (current == NULL)
        {
            cout << "\nInvalid position.\n";
            return;
        }

        if (current->next != NULL)
            current->next->prev = current->prev;

        if (current->prev != NULL)
            current->prev->next = current->next;

        delete current;

        cout << "\nNode at position " << position << " deleted.\n";
    }

    // Delete first occurrence of target - O(n)
    void deleteElement(int target)
    {
        if (head == NULL)
        {
            cout << "\nDoubly Linked List is empty. Underflow!\n";
            return;
        }

        Node* current = head;

        while (current != NULL && current->data != target)
            current = current->next;

        if (current == NULL)
        {
            cout << "\nElement not found.\n";
            return;
        }

        if (current == head)
        {
            deleteFromBeginning();
            return;
        }

        if (current->next != NULL)
            current->next->prev = current->prev;

        current->prev->next = current->next;

        delete current;

        cout << "\nElement " << target << " deleted.\n";
    }

    // Linear search - O(n)
    int search(int key)
    {
        Node* current = head;
        int index = 0;

        while (current != NULL)
        {
            if (current->data == key)
                return index;

            current = current->next;
            index++;
        }

        return -1;
    }

    // Update first occurrence - O(n)
    void update(int oldValue, int newValue)
    {
        Node* current = head;

        while (current != NULL)
        {
            if (current->data == oldValue)
            {
                current->data = newValue;
                cout << "\nNode updated successfully.\n";
                return;
            }

            current = current->next;
        }

        cout << "\nElement not found.\n";
    }
};

int main()
{
    DoublyLinkedList list;

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
        cout << "       DOUBLY LINKED LIST OPERATIONS\n";
        cout << "============================================\n";
        cout << "1.  Display Forward\n";
        cout << "2.  Display Backward\n";
        cout << "3.  Insert at Beginning\n";
        cout << "4.  Insert at End\n";
        cout << "5.  Insert at Position\n";
        cout << "6.  Insert Before an Element\n";
        cout << "7.  Insert After an Element\n";
        cout << "8.  Delete from Beginning\n";
        cout << "9.  Delete from End\n";
        cout << "10. Delete from Position\n";
        cout << "11. Delete an Element\n";
        cout << "12. Search Element\n";
        cout << "13. Update a Node\n";
        cout << "14. Exit\n";
        cout << "============================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.displayForward();
            break;

        case 2:
            list.displayBackward();
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;

        case 4:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 5:
            cout << "Enter position (0-based): ";
            cin >> position;
            cout << "Enter value: ";
            cin >> value;
            list.insertAtPosition(position, value);
            break;

        case 6:
            cout << "Enter target element: ";
            cin >> target;
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertBefore(target, value);
            break;

        case 7:
            cout << "Enter target element: ";
            cin >> target;
            cout << "Enter value to insert: ";
            cin >> value;
            list.insertAfter(target, value);
            break;

        case 8:
            list.deleteFromBeginning();
            break;

        case 9:
            list.deleteFromEnd();
            break;

        case 10:
            cout << "Enter position (0-based): ";
            cin >> position;
            list.deleteFromPosition(position);
            break;

        case 11:
            cout << "Enter element to delete: ";
            cin >> target;
            list.deleteElement(target);
            break;

        case 12:
            cout << "Enter element to search: ";
            cin >> target;

            index = list.search(target);

            if (index == -1)
                cout << "\nElement not found.\n";
            else
                cout << "\nElement found at index: " << index << endl;

            break;

        case 13:
            cout << "Enter old value: ";
            cin >> oldValue;
            cout << "Enter new value: ";
            cin >> newValue;
            list.update(oldValue, newValue);
            break;

        case 14:
            cout << "\nProgram ended.\n";
            break;

        default:
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 14);

    return 0;
}
