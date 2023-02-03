#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

#include <time.h>
#include <stdlib.h>

#include "Sequence.h"
#include "Sorter.h"

using namespace std;

class TimeSorter {
public:
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

	static void writeFile(ArraySequence<double>& time, string typeSequence, string typeSort) {
		ofstream fout;

		fout.open("Tests\\" + typeSequence + typeSort + ".txt");

		if (!fout) {
			cout << "File not opened\n";
		}

		if (typeSequence == "Array") {
			int amount = 1e3;

			for (int i = 0; i < time.getSize(); ++i) {
				fout << amount << ' ' << time[i] << '\n';

				amount += 1e3;
			}
		}

		else if (typeSequence == "List") {
			int amount = 1e2;

			for (int i = 0; i < time.getSize(); ++i) {
				fout << amount << ' ' << time[i] << '\n';

				amount += 1e2;
			}
		}

		fout.close();
	}

	static void fillSequence(ArraySequence<int>& seq, int size) {
		srand(time(NULL));

		for (int i = 0; i < size; ++i) {
			seq[i] = rand();
		}

	}

	static void fillSequence(ListSequence<int>& seq, int size) {
		srand(time(NULL));

		for (int i = 0; i < size; ++i) {
			seq.append(rand());
		}
	}

	static void getBubbleSortTime() {
		ArraySequence<double> arrTime = ArraySequence<double>();
		ArraySequence<double> listTime = ArraySequence<double>();
		Sorter<int> sorter;

		cout << "BubbleSort:\n";

		cout << "\tArraySequence:\n";
		for (int i = 1e3; i <= 1e4; i += 1e3) {
			ArraySequence<int> arr = ArraySequence<int>(i);

			fillSequence(arr, i);

			auto start = chrono::steady_clock::now();
			sorter.bubbleSort(arr, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			arrTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(arrTime, "Array", "BubbleSort");

		cout << "\tListSequence:\n";
		for (int i = 1e2; i <= 1e3; i += 1e2) {
			ListSequence<int> list = ListSequence<int>();

			fillSequence(list, i);

			auto start = chrono::steady_clock::now();
			sorter.bubbleSort(list, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			listTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(listTime, "List", "BubbleSort");
	}

	static void getShakerSortTime() {
		ArraySequence<double> arrTime = ArraySequence<double>();
		ArraySequence<double> listTime = ArraySequence<double>();
		Sorter<int> sorter;

		cout << "ShakerSort:\n";

		cout << "\tAraySequence:\n";
		for (int i = 1e3; i <= 1e4; i += 1e3) {
			ArraySequence<int> arr = ArraySequence<int>(i);
			fillSequence(arr, i);

			auto start = chrono::steady_clock::now();
			sorter.shakerSort(arr, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			arrTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(arrTime, "Array", "ShakerSort");

		cout << "\tListSequence:\n";
		for (int i = 1e2; i <= 1e3; i += 1e2) {
			ListSequence<int> list = ListSequence<int>();
			fillSequence(list, i);

			auto start = chrono::steady_clock::now();
			sorter.shakerSort(list, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			listTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(listTime, "List", "ShakerSort");
	}

	static void getInsertionSortTime() {
		ArraySequence<double> arrTime = ArraySequence<double>();
		ArraySequence<double> listTime = ArraySequence<double>();
		Sorter<int> sorter;

		cout << "InsertionSort:\n";

		cout << "\tArraySequence:\n";
		for (int i = 1e3; i <= 1e4; i += 1e3) {
			ArraySequence<int> arr = ArraySequence<int>(i);
			fillSequence(arr, i);

			auto start = chrono::steady_clock::now();
			sorter.insertionSort(arr, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			arrTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(arrTime, "Array", "InsertionSort");

		cout << "\tListSequence:\n";
		for (int i = 1e2; i <= 1e3; i += 1e2) {
			ListSequence<int> list = ListSequence<int>();
			fillSequence(list, i);

			auto start = chrono::steady_clock::now();
			sorter.insertionSort(list, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			listTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(listTime, "List", "InsertionSort");
	}

	static void getSelectionSortTime() {
		ArraySequence<double> arrTime = ArraySequence<double>();
		ArraySequence<double> listTime = ArraySequence<double>();
		Sorter<int> sorter;

		cout << "SelectionSort:\n";

		cout << "\tArraySequence:\n";
		for (int i = 1e3; i <= 1e4; i += 1e3) {
			ArraySequence<int> arr = ArraySequence<int>(i);
			fillSequence(arr, i);

			auto start = chrono::steady_clock::now();
			sorter.selectionSort(arr, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			arrTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(arrTime, "Array", "SelectionSort");

		cout << "\tListSequence\n";
		for (int i = 1e2; i <= 1e3; i += 1e2) {
			ListSequence<int> list = ListSequence<int>();
			fillSequence(list, i);

			auto start = chrono::steady_clock::now();
			sorter.selectionSort(list, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			listTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(listTime, "List", "SelectionSort");
	}

	static void getBinaryInsertionSortTime() {
		ArraySequence<double> arrTime = ArraySequence<double>();
		ArraySequence<double> listTime = ArraySequence<double>();
		Sorter<int> sorter;

		cout << "BinaryInsertionSort:\n";

		cout << "\tArraySequence:\n";
		for (int i = 1e3; i <= 1e4; i += 1e3) {
			ArraySequence<int> arr = ArraySequence<int>(i);
			fillSequence(arr, i);

			auto start = chrono::steady_clock::now();
			sorter.binaryInsertionSort(arr, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			arrTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(arrTime, "Array", "BinaryInsertionSort");

		cout << "\tListSequence\n";
		for (int i = 1e2; i <= 1e3; i += 1e2) {
			ListSequence<int> list = ListSequence<int>();
			fillSequence(list, i);

			auto start = chrono::steady_clock::now();
			sorter.binaryInsertionSort(list, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			listTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(listTime, "List", "BinaryInsertionSort");
	}

	static void getTreeSortTime() {
		ArraySequence<double> arrTime = ArraySequence<double>();
		ArraySequence<double> listTime = ArraySequence<double>();
		Sorter<int> sorter;

		cout << "TreeSort:\n";

		cout << "\tArraySequence:\n";
		for (int i = 1e3; i <= 1e4; i += 1e3) {
			ArraySequence<int> arr = ArraySequence<int>(i);
			fillSequence(arr, i);
			cout << "i = " << i << ' ';

			auto start = chrono::steady_clock::now();
			sorter.treeSort(arr, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			arrTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(arrTime, "Array", "TreeSort");

		cout << "\tListSequence:\n";
		for (int i = 1e2; i <= 1e3; i += 1e2) {
			ListSequence<int> list = ListSequence<int>();
			fillSequence(list, i);

			auto start = chrono::steady_clock::now();
			sorter.treeSort(list, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			listTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(listTime, "List", "TreeSort");
	}

	static void getHeapSortTime() {
		ArraySequence<double> arrTime = ArraySequence<double>();
		ArraySequence<double> listTime = ArraySequence<double>();
		Sorter<int> sorter;

		cout << "HeapSort:\n";

		cout << "\tArraySequence:\n";
		for (int i = 1e3; i <= 1e4; i += 1e3) {
			ArraySequence<int> arr = ArraySequence<int>(i);
			fillSequence(arr, i);

			auto start = chrono::steady_clock::now();
			sorter.heapSort(arr, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			arrTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(arrTime, "Array", "HeapSort");

		cout << "\tListSequence:\n";
		for (int i = 1e2; i <= 1e3; i += 1e2) {
			ListSequence<int> list = ListSequence<int>();
			fillSequence(list, i);

			auto start = chrono::steady_clock::now();
			sorter.bubbleSort(list, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			listTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(listTime, "List", "HeapSort");
	}

	static void getQuickSortTime() {
		ArraySequence<double> arrTime = ArraySequence<double>();
		ArraySequence<double> listTime = ArraySequence<double>();
		Sorter<int> sorter;

		cout << "QuickSort:\n";

		cout << "\tArraySequence:\n";
		for (int i = 1e3; i <= 1e4; i += 1e3) {
			ArraySequence<int> arr = ArraySequence<int>(i);
			fillSequence(arr, i);

			auto start = chrono::steady_clock::now();
			sorter.quickSort(arr, cmp, 0, arr.getSize() - 1);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			arrTime.append(chrono::duration<double, milli>(diff).count());
		}

		writeFile(arrTime, "Array", "QuickSort");

		cout << "\tListSequence:\n";
		for (int i = 1e2; i <= 1e3; i += 1e2) {
			ListSequence<int> list = ListSequence<int>();
			fillSequence(list, i);

			auto start = chrono::steady_clock::now();
			sorter.quickSort(list, cmp, 0, list.getSize() - 1);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			listTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(listTime, "List", "QuickSort");
	}

	static void getShellSortTime() {
		ArraySequence<double> arrTime = ArraySequence<double>();
		ArraySequence<double> listTime = ArraySequence<double>();
		Sorter<int> sorter;

		cout << "ShellSort:\n";

		cout << "\tArraySequence:\n";
		for (int i = 1e3; i <= 1e4; i += 1e3) {
			ArraySequence<int> arr = ArraySequence<int>(i);
			fillSequence(arr, i);

			auto start = chrono::steady_clock::now();
			sorter.shellSort(arr, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			arrTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(arrTime, "Array", "ShellSort");

		cout << "\tListSequence:\n";
		for (int i = 1e2; i <= 1e3; i += 1e2) {
			ListSequence<int> list = ListSequence<int>();
			fillSequence(list, i);

			auto start = chrono::steady_clock::now();
			sorter.shellSort(list, cmp);
			auto end = chrono::steady_clock::now();

			auto diff = end - start;

			cout << "\t\ti = " << i << " linkDiff = " << chrono::duration<double, milli>(diff).count() << "ms\n";

			listTime.append(chrono::duration<double, milli>(diff).count());
		}
		writeFile(listTime, "List", "ShellSort");
	}

	static void run() {
		getBubbleSortTime();
		getShakerSortTime();
		getInsertionSortTime();
		getSelectionSortTime();
		getBinaryInsertionSortTime();
		getTreeSortTime();
		getHeapSortTime();
		getQuickSortTime();
		getShellSortTime();

		cout << "All sorting times have been calculated\n";
	}
};