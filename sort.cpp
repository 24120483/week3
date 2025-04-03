#include<iostream>
using namespace std;

void insertion_sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heap_sort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int partition(int a[], int l, int r) {
	int pivot = a[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (a[j] <= pivot) {
			++i;
			swap(a[i], a[j]);
		}
	}
	++i;
	swap(a[i], a[r]);
	return i;
}

void quick_sort(int a[], int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		int p = partition(a, l, r);
		quick_sort(a, l, p - 1);
		quick_sort(a, p + 1, r);
	}
}