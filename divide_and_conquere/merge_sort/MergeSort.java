import java.util.Scanner;

public class MergeSort {
    static Scanner scanInput = new Scanner(System.in);

    public static void initialArray(int[] array, int size) {
        System.out.print("\nInput the integer value as elements of the array: ");
        int element = 0;
        for (int i =0; i < size; ++i) {
            element =  scanInput.nextInt();
            array[i] = element;
        }
        System.out.println();
    }

    public static void printArray(int[] array) {
        System.out.println();
        for (int value : array) {
            System.out.print(value + ", ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        System.out.print("\nInput the size of the array: ");
        int sizeOfArray =  scanInput.nextInt();
        int[] originalArray = new int[sizeOfArray];
        initialArray(originalArray, sizeOfArray);

        System.out.print("\nArray Before Soring: ");
        printArray(originalArray);

        (new MergeSortAlgorithm()).sort(originalArray, 0, originalArray.length - 1);
        System.out.print("\nSorted Array: ");
        printArray(originalArray);
    }
}
