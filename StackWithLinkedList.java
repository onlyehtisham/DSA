import java.util.Scanner;

public class StackWithLinkedList {

    // Node class is nested so the runner cannot mistakenly select Node
    // as the program's main class.
    static class Node {
        int data;
        Node next;

        Node(int value) {
            data = value;
            next = null;
        }
    }

    // Stack implemented using a singly linked list.
    static class Stack {
        private Node top;

        Stack() {
            top = null;
        }

        boolean isEmpty() {
            return top == null;
        }

        // Push: O(1)
        void push(int value) {
            Node newNode = new Node(value);
            newNode.next = top;
            top = newNode;
            System.out.println("\n" + value + " pushed into Stack.");
        }

        // Pop: O(1)
        int pop() {
            if (isEmpty()) {
                System.out.println("\nStack Underflow!");
                return -1;
            }
            int value = top.data;
            top = top.next;
            return value;
        }

        // Peek: O(1)
        int peek() {
            if (isEmpty()) {
                System.out.println("\nStack is empty.");
                return -1;
            }
            return top.data;
        }

        // Display: O(n)
        void display() {
            if (isEmpty()) {
                System.out.println("\nStack is empty.");
                return;
            }
            Node current = top;
            System.out.println("\nStack:");
            while (current != null) {
                System.out.println(current.data);
                current = current.next;
            }
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Stack s = new Stack();
        int choice;

        do {
            System.out.println("\n=================================");
            System.out.println("       STACK USING LINKED LIST");
            System.out.println("=================================");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peek");
            System.out.println("4. Is Empty");
            System.out.println("5. Display");
            System.out.println("6. Exit");
            System.out.println("=================================");
            System.out.print("Enter your choice: ");
            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value: ");
                    int value = input.nextInt();
                    s.push(value);
                    break;
                case 2:
                    value = s.pop();
                    if (value != -1) {
                        System.out.println("Popped value: " + value);
                    }
                    break;
                case 3:
                    value = s.peek();
                    if (value != -1) {
                        System.out.println("Top element: " + value);
                    }
                    break;
                case 4:
                    System.out.println(s.isEmpty()
                            ? "\nStack is empty."
                            : "\nStack is not empty.");
                    break;
                case 5:
                    s.display();
                    break;
                case 6:
                    System.out.println("\nProgram ended.");
                    break;
                default:
                    System.out.println("\nInvalid choice.");
            }
        } while (choice != 6);

        input.close();
    }
}
