#pragma once

#include <cassert>
#include <iostream>

#include "Sorter.h"
#include "Sequence.h"

using namespace std;

class unittest_Sorter {
public:
	template<typename T> static void printSeq(Sequence<T>& seq) {
		for (int i = 0; i < seq.getSize(); ++i) {
			cout << seq[i] << ' ';
		}
		cout << '\n';
	}

	static int cmp(int a, int b) {
		if (a > b) {
			return 1;
		}
		else if (a == b) {
			return 0;
		}
		else {
			return -1;
		}
	}

	static void testBubbleSort() {
		Sorter<int> sorter;
		int testn[10] = { 4, 6, 2, 2, 7, 8, 1, 0, 9, 9 };

		ArraySequence<int> arrSeq = ArraySequence<int>(testn, 10);
		ListSequence<int> listSeq = ListSequence<int>(testn, 10);

		sorter.bubbleSort(arrSeq, cmp);
		sorter.bubbleSort(listSeq, cmp);

		for (int i = 0; i < 9; ++i) {
			assert(arrSeq[i] <= arrSeq[i + 1]);
			assert(arrSeq[i] <= arrSeq[i + 1]);
		}
	}

	static void testShakerSort() {
		Sorter<int> sorter;
		int testn[10] = { 4, 6, 2, 2, 7, 8, 1, 0, 9, 9 };

		ArraySequence<int> arrSeq = ArraySequence<int>(testn, 10);
		ListSequence<int> listSeq = ListSequence<int>(testn, 10);

		sorter.shakerSort(arrSeq, cmp);
		sorter.shakerSort(listSeq, cmp);

		for (int i = 0; i < 9; ++i) {
			assert(arrSeq[i] <= arrSeq[i + 1]);
			assert(arrSeq[i] <= arrSeq[i + 1]);
		}
	}

	static void testInsertionSort() {
		Sorter<int> sorter;
		int testn[10] = { 4, 6, 2, 2, 7, 8, 1, 0, 9, 9 };

		ArraySequence<int> arrSeq = ArraySequence<int>(testn, 10);
		ListSequence<int> listSeq = ListSequence<int>(testn, 10);

		sorter.insertionSort(arrSeq, cmp);
		sorter.insertionSort(listSeq, cmp);

		for (int i = 0; i < 9; ++i) {
			assert(arrSeq[i] <= arrSeq[i + 1]);
			assert(arrSeq[i] <= arrSeq[i + 1]);
		}
	}

	static void testSelectionSort() {
		Sorter<int> sorter;
		int testn[10] = { 4, 6, 2, 2, 7, 8, 1, 0, 9, 9 };

		ArraySequence<int> arrSeq = ArraySequence<int>(testn, 10);
		ListSequence<int> listSeq = ListSequence<int>(testn, 10);

		sorter.selectionSort(arrSeq, cmp);
		sorter.selectionSort(listSeq, cmp);

		for (int i = 0; i < 9; ++i) {
			assert(arrSeq[i] <= arrSeq[i + 1]);
			assert(arrSeq[i] <= arrSeq[i + 1]);
		}
	}

	static void testBinaryInsertionSort() {
		Sorter<int> sorter;
		int testn[10] = { 4, 6, 2, 2, 7, 8, 1, 0, 9, 9 };

		ArraySequence<int> arrSeq = ArraySequence<int>(testn, 10);
		ListSequence<int> listSeq = ListSequence<int>(testn, 10);

		sorter.binaryInsertionSort(arrSeq, cmp);
		sorter.binaryInsertionSort(listSeq, cmp);

		for (int i = 0; i < 9; ++i) {
			assert(arrSeq[i] <= arrSeq[i + 1]);
			assert(arrSeq[i] <= arrSeq[i + 1]);
		}
	}

	static void testTreeSort() {
		Sorter<int> sorter;
		int testn[10] = { 4, 6, 2, 2, 7, 8, 1, 0, 9, 9 };

		ArraySequence<int> arrSeq = ArraySequence<int>(testn, 10);
		ListSequence<int> listSeq = ListSequence<int>(testn, 10);

		sorter.treeSort(arrSeq, cmp);
		sorter.treeSort(listSeq, cmp);

		for (int i = 0; i < 9; ++i) {
			assert(arrSeq[i] <= arrSeq[i + 1]);
			assert(arrSeq[i] <= arrSeq[i + 1]);
		}
	}

	static void testHeapSort() {
		Sorter<int> sorter;
		int testn[10] = { 4, 6, 2, 2, 7, 8, 1, 0, 9, 9 };

		ArraySequence<int> arrSeq = ArraySequence<int>(testn, 10);
		ListSequence<int> listSeq = ListSequence<int>(testn, 10);

		sorter.heapSort(arrSeq, cmp);
		sorter.heapSort(listSeq, cmp);

		for (int i = 0; i < 9; ++i) {
			assert(arrSeq[i] <= arrSeq[i + 1]);
			assert(arrSeq[i] <= arrSeq[i + 1]);
		}
	}

	static void testQuickSort() {
		Sorter<int> sorter;
		int testn[10] = { 4, 6, 2, 2, 7, 8, 1, 0, 9, 9 };

		ArraySequence<int> arrSeq = ArraySequence<int>(testn, 10);
		ListSequence<int> listSeq = ListSequence<int>(testn, 10);

		sorter.quickSort(arrSeq, cmp, 0, arrSeq.getSize() - 1);
		sorter.quickSort(listSeq, cmp, 0, listSeq.getSize() - 1);

		for (int i = 0; i < 9; ++i) {
			assert(arrSeq[i] <= arrSeq[i + 1]);
			assert(arrSeq[i] <= arrSeq[i + 1]);
		}
	}

	static void testShellSort() {
		Sorter<int> sorter;
		int testn[10] = { 4, 6, 2, 2, 7, 8, 1, 0, 9, 9 };

		ArraySequence<int> arrSeq = ArraySequence<int>(testn, 10);
		ListSequence<int> listSeq = ListSequence<int>(testn, 10);

		sorter.shellSort(arrSeq, cmp);
		sorter.shellSort(listSeq, cmp);

		for (int i = 0; i < 9; ++i) {
			assert(arrSeq[i] <= arrSeq[i + 1]);
			assert(arrSeq[i] <= arrSeq[i + 1]);
		}
	}

	static void run() {
		testBubbleSort();
		testShakerSort();
		testInsertionSort();
		testSelectionSort();
		testBinaryInsertionSort();
		testTreeSort();
		testHeapSort();
		testQuickSort();
		testShellSort();

		cout << "All Sorter tests finished successfully\n";
	}
};