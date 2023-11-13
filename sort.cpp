//
// Created by 陈鹏宇 on 2023/11/13.
//
#include <iostream>

class sort1 {
public:
    static void sortTheArray(int *array, int len) {
        for (int i = 1; i < len; i++) {
            int major = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > major) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = major;
        }
    }
};

class sort2 {
public:
    static void sortTheArray(int *array, int len) {
        int gap;
        for (gap = len / 2; gap > 0; gap /= 2) {
            for (int i = 0; i < gap; ++i) {
                for (int j = i + gap; j < len; j += gap) {
                    int major = array[j];
                    int k = j - gap;
                    while (k >= 0 && array[k] > major) {
                        array[k + gap] = array[k];
                        k -= gap;
                    }
                    array[k + gap] = major;
                }
            }
        }
    }
};

class sort3 {
public:
    static int *sortTheArray(int *array, int len) {
        merageSort(array, 0, len);
    }

    static void merageSort(int *array, int low, int high) {
        if (high - low + 1 <= 16) {
            for (int i = low + 1; i < high; i++) {
                int major = array[i];
                int j = i - 1;
                while (j >= low && array[j] > major) {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = major;
            }
            return;
        }

        int mid = (high + low) / 2;
        merageSort(array, low, mid + 1);
        merageSort(array, mid + 1, high);
        merage(array, low, mid, high);
    }

    static void merage(int *array, int low, int mid, int high) {
        int *work = new int[high - low + 1];
        int i = low;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j < high) {
            if (array[i] < array[j]) {
                work[k] = array[i];
                k++;
                i++;
            } else {
                work[k] = array[j];
                k++;
                j++;
            }
        }

        while (i <= mid) {
            work[k] = array[i];
            k++;
            i++;
        }
        while (j < high) {
            work[k] = array[j];
            k++;
            j++;
        }
        for (i = low, k = 0; i < high; i++) {
            array[i] = work[k++];
        }
        delete[] work;
    }
};

class sort4 {
public:
    static void sortTheArray(int *array, int n) {
        quickSort(array, 0, n);
    }

    static void quickSort(int *array, int low, int high) {
        int mid;
        if (high - low + 1 <= 16) {
            for (int i = low + 1; i < high; i++) {
                int major = array[i];
                int j = i - 1;
                while (j >= low && array[j] > major) {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = major;
            }
        } else {
            mid = swapSort(array, low, high);
            quickSort(array, low, mid);
            quickSort(array, mid + 1, high);
        }
    }

    static int swapSort(int *array, int low, int high) {
        int pro = array[low];
        int i = low;
        int j = high - 1;
        while (i < j) {
            while (i < j && array[j] > pro)
                j--;
            if (i < j) {
                int t = array[i];
                array[i] = array[j];
                array[j] = t;
                i++;
            }
            while (i < j && array[i] < pro)
                i++;
            if (i < j) {
                int t = array[i];
                array[i] = array[j];
                array[j] = t;
                j--;
            }
        }
        return i;
    }
};

class sort5 {
public:
    static void sortTheArray(int *array, int len) {
        for (int i = len / 2 - 1; i >= 0; i--) {
            deepDive(array, i, len);
        }
        for (int i = len - 1; i > 0; i--) {
            std::swap(array[0], array[i]);
            deepDive(array, 0, i);
        }
    }

    static void deepDive(int *array, int begin, int end) {
        int up = begin;
        int down = begin * 2 + 1;
        while (down < end) {
            if (down + 1 < end && array[down] < array[down + 1])
                down++;
            if (array[up] > array[down])
                return;
            else {
                std::swap(array[up], array[down]);
                up = down;
                down = up * 2 + 1;
            }
        }
    }
};

