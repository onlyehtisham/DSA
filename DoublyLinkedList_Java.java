import java.util.Scanner;

public class DoublyLinkedList {
    static class Node {
        int data;
        Node prev, next;
        Node(int value) {
            data = value;
            prev = next = null;
        }
    }

    private Node head;

    public boolean isEmpty() {
        return head == null;
    }

    public void displayForward() {
        if (isEmpty()) {
            System.out.println("\nDoubly Linked List is empty.");
            return;
        }
        Node temp = head;
        System.out.print("\nForward: NULL <- ");
        while (temp != null) {
            System.out.print(temp.data);
            if (temp.next != null) System.out.print(" <-> ");
            temp = temp.next;
        }
        System.out.println(" -> NULL");
    }

    public void displayBackward() {
        if (isEmpty()) {
            System.out.println("\nDoubly Linked List is empty.");
            return;
        }
        Node temp = head;
        while (temp.next != null) temp = temp.next;

        System.out.print("\nBackward: NULL <- ");
        while (temp != null) {
            System.out.print(temp.data);
            if (temp.prev != null) System.out.print(" <-> ");
            temp = temp.prev;
        }
        System.out.println(" -> NULL");
    }

    public void insertAtBeginning(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            head = newNode;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
        System.out.println("\nNode inserted at beginning.");
    }

    public void insertAtEnd(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            head = newNode;
            System.out.println("\nNode inserted at end.");
            return;
        }

        Node temp = head;
        while (temp.next != null) temp = temp.next;

        temp.next = newNode;
        newNode.prev = temp;
        System.out.println("\nNode inserted at end.");
    }

    public void insertAtPosition(int position, int value) {
        if (position < 0) {
            System.out.println("\nInvalid position.");
            return;
        }

        if (position == 0) {
            insertAtBeginning(value);
            return;
        }

        Node current = head;
        for (int i = 0; i < position && current != null; i++)
            current = current.next;

        if (current == null) {
            if (head == null) {
                System.out.println("\nInvalid position.");
                return;
            }

            Node last = head;
            int lastIndex = 0;
            while (last.next != null) {
                last = last.next;
                lastIndex++;
            }

            if (position == lastIndex + 1)
                insertAtEnd(value);
            else
                System.out.println("\nInvalid position.");
            return;
        }

        Node newNode = new Node(value);
        newNode.prev = current.prev;
        newNode.next = current;
        current.prev.next = newNode;
        current.prev = newNode;

        System.out.println("\nNode inserted at position " + position + ".");
    }

    public void insertBefore(int target, int value) {
        if (head == null) {
            System.out.println("\nDoubly Linked List is empty.");
            return;
        }

        Node current = head;
        while (current != null && current.data != target)
            current = current.next;

        if (current == null) {
            System.out.println("\nTarget element not found.");
            return;
        }

        if (current == head) {
            insertAtBeginning(value);
            return;
        }

        Node newNode = new Node(value);
        newNode.prev = current.prev;
        newNode.next = current;
        current.prev.next = newNode;
        current.prev = newNode;

        System.out.println("\nNode inserted before " + target + ".");
    }

    public void insertAfter(int target, int value) {
        if (head == null) {
            System.out.println("\nDoubly Linked List is empty.");
            return;
        }

        Node current = head;
        while (current != null && current.data != target)
            current = current.next;

        if (current == null) {
            System.out.println("\nTarget element not found.");
            return;
        }

        Node newNode = new Node(value);
        newNode.prev = current;
        newNode.next = current.next;

        if (current.next != null)
            current.next.prev = newNode;

        current.next = newNode;
        System.out.println("\nNode inserted after " + target + ".");
    }

    public void deleteFromBeginning() {
        if (head == null) {
            System.out.println("\nDoubly Linked List is empty. Underflow!");
            return;
        }

        Node temp = head;
        head = head.next;

        if (head != null) head.prev = null;

        temp.next = null;
        temp.prev = null;

        System.out.println("\nFirst node deleted.");
    }

    public void deleteFromEnd() {
        if (head == null) {
            System.out.println("\nDoubly Linked List is empty. Underflow!");
            return;
        }

        if (head.next == null) {
            head = null;
            System.out.println("\nLast node deleted.");
            return;
        }

        Node temp = head;
        while (temp.next != null) temp = temp.next;

        temp.prev.next = null;
        temp.prev = null;
        System.out.println("\nLast node deleted.");
    }

    public void deleteFromPosition(int position) {
        if (head == null) {
            System.out.println("\nDoubly Linked List is empty. Underflow!");
            return;
        }

        if (position < 0) {
            System.out.println("\nInvalid position.");
            return;
        }

        if (position == 0) {
            deleteFromBeginning();
            return;
        }

        Node current = head;
        for (int i = 0; i < position && current != null; i++)
            current = current.next;

        if (current == null) {
            System.out.println("\nInvalid position.");
            return;
        }

        if (current.next != null)
            current.next.prev = current.prev;

        if (current.prev != null)
            current.prev.next = current.next;

        current.prev = null;
        current.next = null;

        System.out.println("\nNode at position " + position + " deleted.");
    }

    public void deleteElement(int target) {
        if (head == null) {
            System.out.println("\nDoubly Linked List is empty. Underflow!");
            return;
        }

        Node current = head;
        while (current != null && current.data != target)
            current = current.next;

        if (current == null) {
            System.out.println("\nElement not found.");
            return;
        }

        if (current == head) {
            deleteFromBeginning();
            return;
        }

        if (current.next != null)
            current.next.prev = current.prev;

        current.prev.next = current.next;
        current.prev = null;
        current.next = null;

        System.out.println("\nElement " + target + " deleted.");
    }

    public int search(int key) {
        Node current = head;
        int index = 0;

        while (current != null) {
            if (current.data == key) return index;
            current = current.next;
            index++;
        }
        return -1;
    }

    public void update(int oldValue, int newValue) {
        Node current = head;

        while (current != null) {
            if (current.data == oldValue) {
                current.data = newValue;
                System.out.println("\nNode updated successfully.");
                return;
            }
            current = current.next;
        }

        System.out.println("\nElement not found.");
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        DoublyLinkedList list = new DoublyLinkedList();

        // Initial data for demonstration.
        list.insertAtEnd(10);
        list.insertAtEnd(20);
        list.insertAtEnd(30);
        list.insertAtEnd(40);
        list.insertAtEnd(50);

        int choice, value, target, position, oldValue, newValue, index;

        do {
            System.out.println("\n\n============================================");
            System.out.println("       DOUBLY LINKED LIST OPERATIONS");
            System.out.println("============================================");
            System.out.println("1.  Display Forward");
            System.out.println("2.  Display Backward");
            System.out.println("3.  Insert at Beginning");
            System.out.println("4.  Insert at End");
            System.out.println("5.  Insert at Position");
            System.out.println("6.  Insert Before an Element");
            System.out.println("7.  Insert After an Element");
            System.out.println("8.  Delete from Beginning");
            System.out.println("9.  Delete from End");
            System.out.println("10. Delete from Position");
            System.out.println("11. Delete an Element");
            System.out.println("12. Search Element");
            System.out.println("13. Update a Node");
            System.out.println("14. Exit");
            System.out.println("============================================");

            System.out.print("Enter your choice: ");
            choice = input.nextInt();

            switch (choice) {
                case 1:
                    list.displayForward();
                    break;
                case 2:
                    list.displayBackward();
                    break;
                case 3:
                    System.out.print("Enter value: ");
                    value = input.nextInt();
                    list.insertAtBeginning(value);
                    break;
                case 4:
                    System.out.print("Enter value: ");
                    value = input.nextInt();
                    list.insertAtEnd(value);
                    break;
                case 5:
                    System.out.print("Enter position (0-based): ");
                    position = input.nextInt();
                    System.out.print("Enter value: ");
                    value = input.nextInt();
                    list.insertAtPosition(position, value);
                    break;
                case 6:
                    System.out.print("Enter target element: ");
                    target = input.nextInt();
                    System.out.print("Enter value to insert: ");
                    value = input.nextInt();
                    list.insertBefore(target, value);
                    break;
                case 7:
                    System.out.print("Enter target element: ");
                    target = input.nextInt();
                    System.out.print("Enter value to insert: ");
                    value = input.nextInt();
                    list.insertAfter(target, value);
                    break;
                case 8:
                    list.deleteFromBeginning();
                    break;
                case 9:
                    list.deleteFromEnd();
                    break;
                case 10:
                    System.out.print("Enter position (0-based): ");
                    position = input.nextInt();
                    list.deleteFromPosition(position);
                    break;
                case 11:
                    System.out.print("Enter element to delete: ");
                    target = input.nextInt();
                    list.deleteElement(target);
                    break;
                case 12:
                    System.out.print("Enter element to search: ");
                    target = input.nextInt();
                    index = list.search(target);
                    if (index == -1)
                        System.out.println("\nElement not found.");
                    else
                        System.out.println("\nElement found at index: " + index);
                    break;
                case 13:
                    System.out.print("Enter old value: ");
                    oldValue = input.nextInt();
                    System.out.print("Enter new value: ");
                    newValue = input.nextInt();
                    list.update(oldValue, newValue);
                    break;
                case 14:
                    System.out.println("\nProgram ended.");
                    break;
                default:
                    System.out.println("\nInvalid choice. Please try again.");
            }
        } while (choice != 14);

        input.close();
    }
}
