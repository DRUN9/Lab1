#pragma once

#include <algorithm>
#include <string>

#include "Sequence.h"
#include "Tree.h"

using namespace std;

// cmp returns 1 if a > b, 0 - if a == b, otherwise - -1

template<typename T> class ISorter {
public:
	virtual void bubbleSort(Sequence<T>& seq, int (*cmp) (T, T)) = 0;
	virtual void shakerSort(Sequence<T>& seq, int (*cmp) (T, T)) = 0;
	virtual void insertionSort(Sequence<T>& seq, int (*cmp) (T, T)) = 0;
	virtual void selectionSort(Sequence<T>& seq, int (*cmp) (T, T)) = 0;
	virtual void binaryInsertionSort(Sequence<T>& seq, int (*cmp) (T, T)) = 0;
	virtual void treeSort(Sequence<T>& seq, int (*cmp) (T, T)) = 0;
	virtual void heapSort(Sequence<T>& seq, int (*cmp) (T, T)) = 0;
	virtual void quickSort(Sequence<T>& seq, int (*cmp) (T, T), int start, int end) = 0;
	virtual void shellSort(Sequence<T>& seq, int (*cmp) (T, T)) = 0;
};

template<typename T> class Sorter : public ISorter<T> {
private:
	void printSeq(Sequence<T>& seq) {
		for (int i = 0; i < seq.getSize(); ++i) {
			cout << seq[i] << ' ';
		}
		cout << '\n';
	}

	void heapify(Sequence<T>& seq, int (*cmp) (T, T), int n, int i) {
		int largest = i;

		int l = 2 * i + 1;
		int r = 2 * i + 2;

		if (l < n && cmp(seq[l], seq[largest]) > 0) {
			largest = l;
		}

		if (r < n && cmp(seq[r], seq[largest]) > 0) {
			largest = r;
		}

		if (largest != i) {
			T tmp = seq[i];
			seq[i] = seq[largest];
			seq[largest] = tmp;

			heapify(seq, cmp, n, largest);
		}

	}

	int binarySearch(Sequence<T>& seq, T item, int low, int high, int (*cmp) (T, T)) {
		if (high <= low) {
			return (cmp(item, seq[low]) > 0) ? (low + 1) : low;
		}

		int mid = low + (high - low) / 2;

		if (item == seq[mid]) {
			return mid + 1;
		}

		if (cmp(item, seq[mid]) > 0) {
			return binarySearch(seq, item, mid + 1, high, cmp);
		}

		return binarySearch(seq, item, low, mid - 1, cmp);
	}

	int partition(Sequence<T>& seq, int (*cmp) (T, T), int start, int end) {
		T pivot = seq[end];
		int i = (start - 1);

		for (int j = start; j <= end - 1; ++j) {
			if (cmp(pivot, seq[j]) > 0) {
				++i;

				T tmp = seq[i];
				seq[i] = seq[j];
				seq[j] = tmp;
			}
		}

		T tmp = seq[i + 1];
		seq[i + 1] = seq[end];
		seq[end] = tmp;

		return i + 1;
	}
public:
	void bubbleSort(Sequence<T>& seq, int (*cmp) (T, T)) override {
		for (int i = 0; i < seq.getSize() - 1; ++i) {
			for (int j = seq.getSize() - 1; j > i; --j) {
				if (cmp(seq[j - 1], seq[j]) > 0) {
					T tmp = seq[j];
					seq[j] = seq[j - 1];
					seq[j - 1] = tmp;
				}
			}
		}
	}

	void shakerSort(Sequence<T>& seq, int (*cmp) (T, T)) override {
		int control = seq.getSize() - 1;
		int left = 0;
		int right = seq.getSize() - 1;

		do {
			for (int i = left; i < right; ++i) {
				if (cmp(seq[i], seq[i + 1]) > 0) {
					T tmp = seq[i];
					seq[i] = seq[i + 1];
					seq[i + 1] = tmp;

					control = i;
				}
			}
			right = control;

			for (int i = right; i > left; --i) {
				if (cmp(seq[i - 1], seq[i]) > 0) {
					T tmp = seq[i];
					seq[i] = seq[i - 1];
					seq[i - 1] = tmp;

					control = i;
				}
			}
			left = control;
		} while (left < right);
	}

	void insertionSort(Sequence<T>& seq, int (*cmp) (T, T)) override {
		for (int i = 1; i < seq.getSize(); ++i) {
			T key = seq[i];
			int j = i - 1;

			while (j >= 0 && cmp(seq[j], key) > 0) {
				seq[j + 1] = seq[j];
				--j;
			}

			seq[j + 1] = key;
		}
	}

	void selectionSort(Sequence<T>& seq, int (*cmp) (T, T)) override {
		for (int i = 0; i < seq.getSize() - 1; ++i) {
			int minIndex = i;

			for (int j = i + 1; j < seq.getSize(); ++j) {
				if (cmp(seq[minIndex], seq[j]) > 0) {
					minIndex = j;
				}
			}

			if (minIndex != i) {
				T tmp = seq[i];
				seq[i] = seq[minIndex];
				seq[minIndex] = tmp;
			}
		}
	}

	void binaryInsertionSort(Sequence<T>& seq, int (*cmp) (T, T)) override {
		for (int i = 1; i < seq.getSize(); ++i) {
			int j = i - 1;

			T selected = seq[i];

			int loc = binarySearch(seq, selected, 0, j, cmp);

			while (j >= loc) {
				seq[j + 1] = seq[j];
				--j;
			}
			seq[j + 1] = selected;
		}
	}

	void treeSort(Sequence<T>& seq, int (*cmp) (T, T)) override {
		BinaryTree<T> tree;

		for (int i = 0; i < seq.getSize(); ++i) {
			tree.insert(seq[i], cmp);
		}

		tree.visit(seq);
	}

	void heapSort(Sequence<T>& seq, int (*cmp) (T, T)) override {
		for (int i = seq.getSize() / 2 - 1; i >= 0; --i) {
			heapify(seq, cmp, seq.getSize(), i);
		}

		for (int i = seq.getSize() - 1; i >= 0; --i) {
			T tmp = seq[0];
			seq[0] = seq[i];
			seq[i] = tmp;

			heapify(seq, cmp, i, 0);
		}
	}

	void quickSort(Sequence<T>& seq, int (*cmp) (T, T), int start, int end) override {
		if (start < end) {
			int pi = partition(seq, cmp, start, end);

			quickSort(seq, cmp, start, pi - 1);
			quickSort(seq, cmp, pi + 1, end);
		}
	}

	void shellSort(Sequence<T>& seq, int (*cmp) (T, T)) override {
		for (int gap = seq.getSize() / 2; gap > 0; gap /= 2) {
			for (int i = gap; i < seq.getSize(); ++i) {
				for (int j = i - gap; j >= 0 && cmp(seq[j], seq[j + gap]) > 0; j -= gap) {
					T tmp = seq[j];
					seq[j] = seq[j + gap];
					seq[j + gap] = tmp;
				}
			}
		}
	}
};