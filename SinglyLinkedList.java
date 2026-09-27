import java.util.Scanner;

public class SinglyLinkedList {

    // Node class
    static class Node {
        int data;
        Node next;

        // Constructor
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Head pointer
    private Node head;

    // Constructor
    public SinglyLinkedList() {
        head = null;
    }

    // Check whether the linked list is empty
    public boolean isEmpty() {
        return head == null;
    }

    // Display the linked list
    public void display() {

        if (head == null) {
            System.out.println("Linked List is empty.");
            return;
        }

        Node current = head;

        System.out.print("Linked List: ");

        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }

        System.out.println("NULL");
    }

    // Insert at beginning
    public void insertAtBeginning(int value) {

        Node newNode = new Node(value);

        newNode.next = head;
        head = newNode;
    }

    // Insert at end
    public void insertAtEnd(int value) {

        Node newNode = new Node(value);

        // If list is empty
        if (head == null) {
            head = newNode;
            return;
        }

        Node current = head;

        while (current.next != null) {
            current = current.next;
        }

        current.next = newNode;
    }

    // Insert at a specific position
    public void insertAtPosition(int position, int value) {

        // Position 0 means beginning
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }

        Node newNode = new Node(value);

        Node current = head;

        // Move to node before the required position
        for (int i = 0; i < position - 1; i++) {

            if (current == null) {
                System.out.println("Invalid position.");
                return;
            }

            current = current.next;
        }

        if (current == null) {
            System.out.println("Invalid position.");
            return;
        }

        newNode.next = current.next;
        current.next = newNode;
    }

    // Insert before a specific value
    public void insertBefore(int target, int value) {

        // Empty list
        if (head == null) {
            System.out.println("Linked List is empty.");
            return;
        }

        // Target is at head
        if (head.data == target) {
            insertAtBeginning(value);
            return;
        }

        Node current = head;

        while (current.next != null &&
               current.next.data != target) {

            current = current.next;
        }

        if (current.next == null) {
            System.out.println(
                "Target element not found."
            );
            return;
        }

        Node newNode = new Node(value);

        newNode.next = current.next;
        current.next = newNode;
    }

    // Insert after a specific value
    public void insertAfter(int target, int value) {

        Node current = head;

        while (current != null &&
               current.data != target) {

            current = current.next;
        }

        if (current == null) {
            System.out.println(
                "Target element not found."
            );
            return;
        }

        Node newNode = new Node(value);

        newNode.next = current.next;
        current.next = newNode;
    }

    // Delete from beginning
    public void deleteFromBeginning() {

        if (head == null) {
            System.out.println("Linked List is empty.");
            return;
        }

        head = head.next;
    }

    // Delete from end
    public void deleteFromEnd() {

        if (head == null) {
            System.out.println("Linked List is empty.");
            return;
        }

        // Only one node
        if (head.next == null) {
            head = null;
            return;
        }

        Node current = head;

        while (current.next.next != null) {
            current = current.next;
        }

        current.next = null;
    }

    // Delete from a specific position
    public void deleteFromPosition(int position) {

        if (head == null) {
            System.out.println("Linked List is empty.");
            return;
        }

        // Delete first node
        if (position == 0) {
            deleteFromBeginning();
            return;
        }

        Node current = head;

        for (int i = 0; i < position - 1; i++) {

            if (current.next == null) {

                System.out.println("Invalid position.");
                return;
            }

            current = current.next;
        }

        if (current.next == null) {
            System.out.println("Invalid position.");
            return;
        }

        current.next = current.next.next;
    }

    // Delete a specific element
    public void deleteElement(int value) {

        if (head == null) {
            System.out.println("Linked List is empty.");
            return;
        }

        // Element is at head
        if (head.data == value) {
            head = head.next;
            return;
        }

        Node current = head;

        while (current.next != null &&
               current.next.data != value) {

            current = current.next;
        }

        if (current.next == null) {
            System.out.println(
                "Element not found."
            );
            return;
        }

        current.next = current.next.next;
    }

    // Search for an element
    public int search(int value) {

        Node current = head;
        int position = 0;

        while (current != null) {

            if (current.data == value) {
                return position;
            }

            current = current.next;
            position++;
        }

        return -1;
    }

    // Update an element at a specific position
    public void update(int position, int value) {

        Node current = head;

        for (int i = 0; i < position; i++) {

            if (current == null) {
                System.out.println("Invalid position.");
                return;
            }

            current = current.next;
        }

        if (current == null) {
            System.out.println("Invalid position.");
            return;
        }

        current.data = value;
    }


    // Main method
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        SinglyLinkedList list = new SinglyLinkedList();

        int choice;

        do {

            System.out.println(
                "\n========== SINGLY LINKED LIST =========="
            );

            System.out.println("1. Insert at Beginning");
            System.out.println("2. Insert at End");
            System.out.println("3. Insert at Position");
            System.out.println("4. Insert Before");
            System.out.println("5. Insert After");

            System.out.println("6. Delete from Beginning");
            System.out.println("7. Delete from End");
            System.out.println("8. Delete from Position");
            System.out.println("9. Delete Element");

            System.out.println("10. Search");
            System.out.println("11. Update");
            System.out.println("12. Display");

            System.out.println("0. Exit");

            System.out.print("Enter your choice: ");

            choice = input.nextInt();


            switch (choice) {

                case 1:

                    System.out.print(
                        "Enter value: "
                    );

                    int value1 = input.nextInt();

                    list.insertAtBeginning(value1);

                    System.out.println(
                        "Element inserted successfully."
                    );

                    break;


                case 2:

                    System.out.print(
                        "Enter value: "
                    );

                    int value2 = input.nextInt();

                    list.insertAtEnd(value2);

                    System.out.println(
                        "Element inserted successfully."
                    );

                    break;


                case 3:

                    System.out.print(
                        "Enter position: "
                    );

                    int position1 = input.nextInt();

                    System.out.print(
                        "Enter value: "
                    );

                    int value3 = input.nextInt();

                    list.insertAtPosition(
                        position1,
                        value3
                    );

                    break;


                case 4:

                    System.out.print(
                        "Enter target value: "
                    );

                    int target1 = input.nextInt();

                    System.out.print(
                        "Enter new value: "
                    );

                    int value4 = input.nextInt();

                    list.insertBefore(
                        target1,
                        value4
                    );

                    break;


                case 5:

                    System.out.print(
                        "Enter target value: "
                    );

                    int target2 = input.nextInt();

                    System.out.print(
                        "Enter new value: "
                    );

                    int value5 = input.nextInt();

                    list.insertAfter(
                        target2,
                        value5
                    );

                    break;


                case 6:

                    list.deleteFromBeginning();

                    System.out.println(
                        "Element deleted successfully."
                    );

                    break;


                case 7:

                    list.deleteFromEnd();

                    System.out.println(
                        "Element deleted successfully."
                    );

                    break;


                case 8:

                    System.out.print(
                        "Enter position: "
                    );

                    int position2 = input.nextInt();

                    list.deleteFromPosition(
                        position2
                    );

                    break;


                case 9:

                    System.out.print(
                        "Enter value to delete: "
                    );

                    int deleteValue = input.nextInt();

                    list.deleteElement(
                        deleteValue
                    );

                    break;


                case 10:

                    System.out.print(
                        "Enter value to search: "
                    );

                    int searchValue = input.nextInt();

                    int result = list.search(
                        searchValue
                    );

                    if (result == -1) {

                        System.out.println(
                            "Element not found."
                        );

                    } else {

                        System.out.println(
                            "Element found at position: "
                            + result
                        );
                    }

                    break;


                case 11:

                    System.out.print(
                        "Enter position: "
                    );

                    int position3 = input.nextInt();

                    System.out.print(
                        "Enter new value: "
                    );

                    int newValue = input.nextInt();

                    list.update(
                        position3,
                        newValue
                    );

                    break;


                case 12:

                    list.display();

                    break;


                case 0:

                    System.out.println(
                        "Program terminated."
                    );

                    break;


                default:

                    System.out.println(
                        "Invalid choice."
                    );
            }

        } while (choice != 0);

        input.close();
    }
}