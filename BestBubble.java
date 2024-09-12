import java.util.Scanner;

public class BestBubble {

    // Function to perform bubble sort and return the swap count
    public static int bubbleSortSwaps(int[] arr, boolean ascending) {
        int swapCount = 0;
        int n = arr.length;
        int[] tempArr = arr.clone(); // Clone the original array to preserve it

        // Bubble sort logic
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                // Compare based on ascending or descending order
                if (ascending) {
                    if (tempArr[j] > tempArr[j + 1]) {
                        // Swap if the current element is greater
                        swap(tempArr, j, j + 1);
                        swapCount++;
                    }
                } else {
                    if (tempArr[j] < tempArr[j + 1]) {
                        // Swap if the current element is smaller
                        swap(tempArr, j, j + 1);
                        swapCount++;
                    }
                }
            }
        }
        return swapCount;
    }

    // Helper function to swap elements in an array
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of elements in the array
        int N = sc.nextInt();
        int[] arr = new int[N];

        // Read the elements of the array
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }

        // Count the number of swaps for ascending and descending order
        int ascendingSwaps = bubbleSortSwaps(arr, true); // Ascending order
        int descendingSwaps = bubbleSortSwaps(arr, false); // Descending order

        // Output the minimum number of swaps
        System.out.println(Math.min(ascendingSwaps, descendingSwaps));
    }
}