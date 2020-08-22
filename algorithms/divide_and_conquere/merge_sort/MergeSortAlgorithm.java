public class MergeSortAlgorithm {
    /*
     * Merges two subarrays of originalArray
     * Left subarray is originalArray[indexOfLeft...indexOfMiddle]
     * Right subarray is originalArray[indexOfMiddle+1...indexOfRight]
     */
    public void merge(int[] originalArray, int indexOfLeft, int indexOfMiddle, int indexOfRight) {
        // Sizes of left and right arrays to be merged
        int sizeOfLeftArray = indexOfMiddle - indexOfLeft + 1;
        int sizeOfRightArray = indexOfRight - indexOfMiddle;

        // Temp left and right arrays
        int[] leftArray = new int [sizeOfLeftArray];
        int[] rightArray = new int [sizeOfRightArray];

        // Init left and right arrays
        for (int i = 0; i < sizeOfLeftArray; ++i) {
            leftArray[i] = originalArray[indexOfLeft + i];
        }
        for (int j = 0; j < sizeOfRightArray; ++j) {
            rightArray[j] = originalArray[indexOfMiddle + 1 + j];
        }

        //Merge the temp arrays
        //Initial indexes of left and right subarrays
        int i = 0;
        int j = 0;

        //Initial index of merged subarray
        int k = indexOfLeft;
        while (i < sizeOfLeftArray && j < sizeOfRightArray) {
            if (leftArray[i] <= rightArray[j]) {
                originalArray[k] = leftArray[i];
                ++i;
            } else {
                originalArray[k] = rightArray[j];
                ++j;
            }
            ++k;
        }
        //Copy remaining elements of left array if any
        while (i < sizeOfLeftArray) {
            originalArray[k] = leftArray[i];
            ++i;
            ++k;
        }
        //Copy remaining elements of right array if any
        while (j < sizeOfRightArray) {
            originalArray[k] = rightArray[j];
            ++j;
            ++k;
        }
    }

    /*
     * Main sort function
     */
    public void sort(int[] originalArray, int indexOfLeft, int indexOfRight) {
        if (indexOfLeft < indexOfRight) {
            // Find the middle point
            int indexOfMiddle = (indexOfLeft + indexOfRight) / 2;

            // Sort first and second halves
            sort(originalArray, indexOfLeft, indexOfMiddle);
            sort(originalArray, indexOfMiddle + 1, indexOfRight);

            // Merge the sorted halves
            merge(originalArray, indexOfLeft, indexOfMiddle, indexOfRight);
        }
    }
}