#include <iostream>
#include <vector>

using namespace std;


class SortAlgorithm {
public:
    virtual void sort(vector<int>& arr) = 0;
};

class BubbleSort : public SortAlgorithm {
public:
    void sort(vector<int>& arr) {
        //  bubble sort
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

class InsertionSort : public SortAlgorithm {
public:
    void sort(vector<int>& arr) {
        // insertion sort
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

class SelectionSort : public SortAlgorithm {
public:
    void sort(vector<int>& arr) {
        // selection sort
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }
};

class MergeSort : public SortAlgorithm {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> leftArr(n1);
        vector<int> rightArr(n2);

        for (int i = 0; i < n1; i++) {
            leftArr[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            rightArr[j] = arr[mid + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }

    void sort(vector<int>& arr) {
        // merge sort
        int n = arr.size();
        mergeSort(arr, 0, n - 1);
    }
};

class QuickSort : public SortAlgorithm {
public:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void sort(vector<int>& arr) {
        // quick sort
        int n = arr.size();
        quickSort(arr, 0, n - 1);
    }
};

class HeapSort : public SortAlgorithm {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void sort(vector<int>& arr) {
        //  heap sort
        int n = arr.size();

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};


class Menu {
public:
    void displayMenu() {
        cout << "1. Bubble Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "6. Heap Sort" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
    }

    void executeAlgorithm(SortAlgorithm* algorithm, vector<int>& arr) {
        algorithm->sort(arr);
        cout << "Sorted array: ";
        displayArray(arr);
        cout << endl;
    }

    void displayArray(const vector<int>& arr) {
        for (int num : arr) {
            cout << num << " ";
        }
    }

    void run() {
        int choice;
        vector<int> arr;
        int size;

        cout << "Enter the size of the array: ";
        cin >> size;

        for (int i = 0; i < size; i++) {
            int num;
            cout << "Enter element " << i + 1 << ": ";
            cin >> num;
            arr.push_back(num);
        }

        SortAlgorithm* algorithm;

        while (true) {
            displayMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    algorithm = new BubbleSort();
                    executeAlgorithm(algorithm, arr);
                    delete algorithm;
                    break;
                case 2:
                    algorithm = new InsertionSort();
                    executeAlgorithm(algorithm, arr);
                    delete algorithm;
                    break;
                case 3:
                    algorithm = new SelectionSort();
                    executeAlgorithm(algorithm, arr);
                    delete algorithm;
                    break;
                case 4:
                    algorithm = new MergeSort();
                    executeAlgorithm(algorithm, arr);
                    delete algorithm;
                    break;
                case 5:
                    algorithm = new QuickSort();
                    executeAlgorithm(algorithm, arr);
                    delete algorithm;
                    break;
                case 6:
                    algorithm = new HeapSort();
                    executeAlgorithm(algorithm, arr);
                    delete algorithm;
                    break;
                case 0:
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main() {
    Menu menu;
    menu.run();

    return 0;
}
