#include "SequenceTests.h"
#include "SorterTests.h"
#include "SortTime.h"

using namespace std;

int main() {
	int sortResponse = -1;

	while (true) {

		cout << "Choose the option\n";

		cout << "1 - BubbleSort\n";
		cout << "2 - ShakerSort\n";
		cout << "3 - InsertionSort\n";
		cout << "4 - SelectionSort\n";
		cout << "5 - BinaryInsertionSort\n";
		cout << "6 - TreeSort\n";
		cout << "7 - Heapsort\n";
		cout << "8 - Quicksort\n";
		cout << "9 - ShellSort\n";
		cout << "10 - All sorts\n";
		cout << "11 - Make graph images\n";
		cout << "12 - Run unit tests\n";
		cout << "13 - Exit\n";
		cin >> sortResponse;

		if (sortResponse < 1 || sortResponse > 13) {
			while (sortResponse < 1 || sortResponse > 13) {
				cout << "Wrong option, try again\n";

				cin >> sortResponse;
			}
		}

		if (sortResponse == 13) {
			return 0;
		}

		switch (sortResponse) {
		case 1:
			TimeSorter::getBubbleSortTime();

			break;
		case 2:
			TimeSorter::getShakerSortTime();

			break;
		case 3:
			TimeSorter::getInsertionSortTime();

			break;
		case 4:
			TimeSorter::getSelectionSortTime();

			break;
		case 5:
			TimeSorter::getBinaryInsertionSortTime();

			break;
		case 6:
			TimeSorter::getTreeSortTime();

			break;
		case 7:
			TimeSorter::getHeapSortTime();

			break;
		case 8:
			TimeSorter::getQuickSortTime();

			break;
		case 9:
			TimeSorter::getShellSortTime();

			break;
		case 10:
			TimeSorter::run();

			break;
		case 11:
			cout << "Making graph images... ";
			system("graphics");
			cout << "Done\n";

			break;
		case 12:
			unittest_DynamicArray::run();
			unittest_LinkedList::run();
			unittest_ArraySequence::run();
			unittest_ListSequence::run();
			unittest_Sorter::run();

			break;
		}
	}

	return 0;
}