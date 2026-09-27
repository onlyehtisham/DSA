import java.util.Scanner;

public class ArrayOperations {

    // Display all elements of the array
    public static void display(int[] arr, int size) {

        if (size == 0) {
            System.out.println("Array is empty.");
            return;
        }

        System.out.print("Array: ");

        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }

        System.out.println();
    }


    // Insert element at the beginning
    public static int insertAtBeginning(int[] arr, int size, int value) {

        // Shift elements one position to the right
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = value;

        return size + 1;
    }


    // Insert element at the end
    public static int insertAtEnd(int[] arr, int size, int value) {

        arr[size] = value;

        return size + 1;
    }


    // Insert element at a specific position
    public static int insertAtPosition(
            int[] arr,
            int size,
            int position,
            int value) {

        // Shift elements to the right
        for (int i = size; i > position; i--) {
            arr[i] = arr[i - 1];
        }

        arr[position] = value;

        return size + 1;
    }


    // Delete element from beginning
    public static int deleteFromBeginning(int[] arr, int size) {

        if (size == 0) {
            System.out.println("Array is empty.");
            return size;
        }

        // Shift elements to the left
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        return size - 1;
    }


    // Delete element from end
    public static int deleteFromEnd(int[] arr, int size) {

        if (size == 0) {
            System.out.println("Array is empty.");
            return size;
        }

        return size - 1;
    }


    // Delete element from a specific position
    public static int deleteFromPosition(
            int[] arr,
            int size,
            int position) {

        if (size == 0) {
            System.out.println("Array is empty.");
            return size;
        }

        // Shift elements to the left
        for (int i = position; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        return size - 1;
    }


    // Linear search
    public static int search(int[] arr, int size, int value) {

        for (int i = 0; i < size; i++) {

            if (arr[i] == value) {
                return i;
            }
        }

        return -1;
    }


    // Update element
    public static boolean update(
            int[] arr,
            int size,
            int position,
            int value) {

        if (position < 0 || position >= size) {
            return false;
        }

        arr[position] = value;

        return true;
    }


    // Main method
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        // Maximum capacity of array
        int[] arr = new int[100];

        // Number of currently occupied elements
        int size = 0;

        int choice;

        do {

            System.out.println("\n========== ARRAY OPERATIONS ==========");
            System.out.println("1. Insert at Beginning");
            System.out.println("2. Insert at End");
            System.out.println("3. Insert at Position");
            System.out.println("4. Delete from Beginning");
            System.out.println("5. Delete from End");
            System.out.println("6. Delete from Position");
            System.out.println("7. Search");
            System.out.println("8. Update");
            System.out.println("9. Display");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");

            choice = input.nextInt();

            switch (choice) {

                case 1:

                    System.out.print("Enter value: ");
                    int value1 = input.nextInt();

                    if (size == arr.length) {
                        System.out.println("Array is full.");
                    }
                    else {
                        size = insertAtBeginning(arr, size, value1);
                        System.out.println("Element inserted successfully.");
                    }

                    break;


                case 2:

                    System.out.print("Enter value: ");
                    int value2 = input.nextInt();

                    if (size == arr.length) {
                        System.out.println("Array is full.");
                    }
                    else {
                        size = insertAtEnd(arr, size, value2);
                        System.out.println("Element inserted successfully.");
                    }

                    break;


                case 3:

                    System.out.print("Enter position: ");
                    int position1 = input.nextInt();

                    System.out.print("Enter value: ");
                    int value3 = input.nextInt();

                    if (size == arr.length) {
                        System.out.println("Array is full.");
                    }
                    else if (position1 < 0 || position1 > size) {
                        System.out.println("Invalid position.");
                    }
                    else {
                        size = insertAtPosition(
                                arr,
                                size,
                                position1,
                                value3
                        );

                        System.out.println(
                                "Element inserted successfully."
                        );
                    }

                    break;


                case 4:

                    if (size == 0) {
                        System.out.println("Array is empty.");
                    }
                    else {
                        size = deleteFromBeginning(arr, size);
                        System.out.println(
                                "Element deleted successfully."
                        );
                    }

                    break;


                case 5:

                    if (size == 0) {
                        System.out.println("Array is empty.");
                    }
                    else {
                        size = deleteFromEnd(arr, size);
                        System.out.println(
                                "Element deleted successfully."
                        );
                    }

                    break;


                case 6:

                    System.out.print("Enter position: ");
                    int position2 = input.nextInt();

                    if (position2 < 0 || position2 >= size) {
                        System.out.println("Invalid position.");
                    }
                    else {
                        size = deleteFromPosition(
                                arr,
                                size,
                                position2
                        );

                        System.out.println(
                                "Element deleted successfully."
                        );
                    }

                    break;


                case 7:

                    System.out.print("Enter value to search: ");
                    int searchValue = input.nextInt();

                    int index = search(
                            arr,
                            size,
                            searchValue
                    );

                    if (index == -1) {
                        System.out.println("Element not found.");
                    }
                    else {
                        System.out.println(
                                "Element found at index: " + index
                        );
                    }

                    break;


                case 8:

                    System.out.print("Enter position: ");
                    int position3 = input.nextInt();

                    System.out.print("Enter new value: ");
                    int newValue = input.nextInt();

                    if (update(
                            arr,
                            size,
                            position3,
                            newValue
                    )) {

                        System.out.println(
                                "Element updated successfully."
                        );

                    }
                    else {

                        System.out.println(
                                "Invalid position."
                        );
                    }

                    break;


                case 9:

                    display(arr, size);

                    break;


                case 0:

                    System.out.println("Program terminated.");

                    break;


                default:

                    System.out.println("Invalid choice.");
            }

        } while (choice != 0);

        input.close();
    }
}
