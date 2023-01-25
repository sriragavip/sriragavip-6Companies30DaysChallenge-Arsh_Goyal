class Solution {
       public int[] sortArray(int[] nums) {
// we can check if our array is sorted or not by O(N) time.
    if (nums.length < 25) {
        insertionSort(nums);
    } else if (nums.length > 25 && nums.length < 1000 ) {
       quickSort(nums, 0, nums.length - 1);
    } else {
	    mergeSort(nums, 0, nums.length - 1);
    }
    return nums;
}
 static void mergeFun(int[] arr, int l, int m, int r) {
    int n1 = m + 1 - l;
    int n2 = r - m;
    int[] left = new int[n1];
    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    int[] right = new int[n2];
    for (int i = 0; i < n2; i++) {
        right[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 || j < n2) {
        if (j == n2 || i < n1 && left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
}

static void mergeSort(int[] arr, int low, int high) {
    if (low < high) {
        int middle = (high - low) / 2 + low;
        mergeSort(arr, low, middle);
        mergeSort(arr, middle + 1, high);
        mergeFun(arr, low, middle, high);
    }
}

static int partitionUsingHoare(int[] arr, int l, int h) {
    int pivot = arr[l];
    int i = l - 1;
    int j = h + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(arr, i, j);
    }
}

static void swap(int[] arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

static void quickSort(int[] arr, int low, int high) {
    if (low < high) {
        int p = partitionUsingHoare(arr, low, high);
        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
    }
}

static void insertionSort(int[] nums) { 
    for (int i = 0; i < nums.length; i++) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}
}