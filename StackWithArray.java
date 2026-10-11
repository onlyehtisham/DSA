import java.util.Scanner;

public class StackWithArray {
    private static final int SIZE = 5;
    private final int[] arr = new int[SIZE];
    private int top;

    public StackWithArray() {
        top = -1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == SIZE - 1;
    }

    public void push(int value) {
        if (isFull()) {
            System.out.println("\nStack Overflow!");
            return;
        }

        top++;
        arr[top] = value;
        System.out.println("\n" + value + " pushed into Stack.");
    }

    public int pop() {
        if (isEmpty()) {
            System.out.println("\nStack Underflow!");
            return -1;
        }

        int value = arr[top];
        top--;
        return value;
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("\nStack is empty.");
            return -1;
        }
        return arr[top];
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("\nStack is empty.");
            return;
        }

        System.out.println("\nStack:");
        for (int i = top; i >= 0; i--) {
            System.out.println(arr[i]);
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StackWithArray s = new StackWithArray();

        int choice;
        int value;

        do {
            System.out.println("\n===== STACK MENU =====");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peek");
            System.out.println("4. Is Empty");
            System.out.println("5. Is Full");
            System.out.println("6. Display");
            System.out.println("7. Exit");

            System.out.print("Enter choice: ");
            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter value: ");
                    value = input.nextInt();
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
                    if (s.isEmpty()) {
                        System.out.println("Stack is empty.");
                    } else {
                        System.out.println("Stack is not empty.");
                    }
                    break;
                case 5:
                    if (s.isFull()) {
                        System.out.println("Stack is full.");
                    } else {
                        System.out.println("Stack is not full.");
                    }
                    break;
                case 6:
                    s.display();
                    break;
                case 7:
                    System.out.println("Program ended.");
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        } while (choice != 7);

        input.close();
    }
}
