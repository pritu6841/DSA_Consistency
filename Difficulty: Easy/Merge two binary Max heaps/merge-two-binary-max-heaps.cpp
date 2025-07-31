class Solution {
  public:
    void heapify(vector<int>& arr, int i, int n) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, largest, n);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        a.insert(a.end(), b.begin(), b.end());
        int size = n + m;
        for (int i = size / 2 - 1; i >= 0; --i) {
            heapify(a, i, size);
        }
        return a; // a is now a valid max-heap
    }
};
