#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void sortElem(int n, vector<int>& arr);

int main() {
    int n = 0;
	cout << "Input the array size: ";
	cin >> n;

    vector<int> array;

    int elem = 0;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter the " << i << " element: ";
        cin >> elem;
        array.push_back(elem);

        sortElem(i + 1, array);

        cout << "Sorted\t\t\tMedian\n";
        cout << "[ ";
        for (int j = 0; j < i + 1; j++)
            cout << array[j] << ", ";
        cout << "]\t";

        double median = 0.0;
        int m_elem = (i+1) / 2;

        if ((i + 1) % 2 != 0) {
            median = array[m_elem];
        }
        else {
            median = (array[m_elem-1] + array[m_elem]) / 2.0;
        }
        cout << "\t   " << fixed << setprecision(1) << median << "\n";
    }
}

void sortElem(int n, vector<int>& arr) {
    int unsortedElement = arr[n - 1];
    int currentIndex = n - 1;

    while (currentIndex > 0 && arr[currentIndex - 1] > unsortedElement) {
        arr[currentIndex] = arr[currentIndex - 1];
        currentIndex--;
    }

    arr[currentIndex] = unsortedElement;
}
