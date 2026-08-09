
#include <iostream>
using namespace std;

class Array
{
private:
    static const int CAPACITY = 100;
    int arr[CAPACITY];
    int size;

public:
    Array()
    {
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;
        size = 5;
    }

    bool isFull() { return size == CAPACITY; }
    bool isEmpty() { return size == 0; }

    void display()
    {
        if (isEmpty())
        {
            cout << "\nArray is Empty!\n";
            return;
        }

        cout << "\nArray: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void insertAtBeginning(int value)
    {
        if (isFull())
        {
            cout << "\nArray Overflow!\n";
            return;
        }

        for (int i = size; i > 0; i--)
            arr[i] = arr[i - 1];

        arr[0] = value;
        size++;
    }

    void insertAtEnd(int value)
    {
        if (isFull())
        {
            cout << "\nArray Overflow!\n";
            return;
        }

        arr[size++] = value;
    }

    void insertAtPosition(int position, int value)
    {
        if (isFull())
        {
            cout << "\nArray Overflow!\n";
            return;
        }

        if (position < 0 || position > size)
        {
            cout << "\nInvalid Position!\n";
            return;
        }

        for (int i = size; i > position; i--)
            arr[i] = arr[i - 1];

        arr[position] = value;
        size++;
    }

    void deleteFromBeginning()
    {
        if (isEmpty())
        {
            cout << "\nArray Underflow!\n";
            return;
        }

        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];

        size--;
    }

    void deleteFromEnd()
    {
        if (isEmpty())
        {
            cout << "\nArray Underflow!\n";
            return;
        }

        size--;
    }

    void deleteFromPosition(int position)
    {
        if (isEmpty())
        {
            cout << "\nArray Underflow!\n";
            return;
        }

        if (position < 0 || position >= size)
        {
            cout << "\nInvalid Position!\n";
            return;
        }

        for (int i = position; i < size - 1; i++)
            arr[i] = arr[i + 1];

        size--;
    }

    int search(int key)
    {
        for (int i = 0; i < size; i++)
            if (arr[i] == key)
                return i;

        return -1;
    }

    void update(int index, int value)
    {
        if (index < 0 || index >= size)
        {
            cout << "\nInvalid Index!\n";
            return;
        }

        arr[index] = value;
    }
};

int main()
{
    Array myArray;
    int choice, value, position, key, index;

    do
    {
        cout << "\n========== ARRAY OPERATIONS ==========\n";
        cout << "1. Display Array\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at End\n";
        cout << "4. Insert at Position\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete from Position\n";
        cout << "8. Search Element\n";
        cout << "9. Update Element\n";
        cout << "10. Exit\n";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            myArray.display();
            break;

        case 2:
            cout << "Enter Value: ";
            cin >> value;
            myArray.insertAtBeginning(value);
            break;

        case 3:
            cout << "Enter Value: ";
            cin >> value;
            myArray.insertAtEnd(value);
            break;

        case 4:
            cout << "Enter Position: ";
            cin >> position;
            cout << "Enter Value: ";
            cin >> value;
            myArray.insertAtPosition(position, value);
            break;

        case 5:
            myArray.deleteFromBeginning();
            break;

        case 6:
            myArray.deleteFromEnd();
            break;

        case 7:
            cout << "Enter Position: ";
            cin >> position;
            myArray.deleteFromPosition(position);
            break;

        case 8:
            cout << "Enter Element to Search: ";
            cin >> key;
            index = myArray.search(key);
            if (index == -1)
                cout << "Element Not Found!\n";
            else
                cout << "Element Found at Index: " << index << endl;
            break;

        case 9:
            cout << "Enter Index: ";
            cin >> index;
            cout << "Enter New Value: ";
            cin >> value;
            myArray.update(index, value);
            break;

        case 10:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 10);

    return 0;
}
