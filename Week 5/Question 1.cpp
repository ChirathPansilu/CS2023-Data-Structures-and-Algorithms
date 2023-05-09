#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>


using namespace std;

#define TIMES 10

using namespace std::chrono;

void recursiveQuickSort(vector<int> &arr, int start, int end);
void iterativeQuickSort(vector<int> &arr, int start, int end);
int paritionArr(vector<int> &arr, int start, int end);

int main() {
  int range_from = 500;
  int range_to = 20000;

  // random number generate
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> distr(range_from, range_to);

  std::vector<int> lengths;

  for (int i = 0; i < 10; i++) {
    std::cout << "Enter array length: ";

    int l = 0;

    std::cin >> l;

    lengths.push_back(l);
  }

  std::cout << "\n\n";

  // create vectors
  std::vector<std::vector<int>> arrs1;
  std::vector<std::vector<int>> arrs2;

  std::uniform_int_distribution<int> arr_distr(-10000, 1000000);

  for (auto l : lengths) {
    std::vector<int> vec1;
    std::vector<int> vec2;

    for (int i = 0; i < l; i++) {
      int num = arr_distr(generator);
      vec1.push_back(num);
      vec2.push_back(num);
    }

    arrs1.push_back(vec1);
    arrs2.push_back(vec2);
  }

  cout << "Recursive Quick Sort:\n";
  for (auto arr : arrs1) {
    std::cout << "Total elements in array: " << arr.size() << "\n";
    vector<int> cpyArr = arr;

    int size = arr.size() - 1;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < TIMES; i++) {
      recursiveQuickSort(arr, 0, size);
      arr.assign(cpyArr.begin(), cpyArr.end());
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    auto time = duration.count() / TIMES;

    std::cout << "Time taken is " << time << "\n\n";
  }

  cout << "\n\n\nIterative Quick Sort:\n";
  for (auto arr : arrs2) {
    std::cout << "Total elements in array: " << arr.size() << "\n";
    vector<int> cpyArr = arr;

    int size = arr.size() - 1;

    auto start = high_resolution_clock::now();
    for (int i = 0; i < TIMES; i++) {
      iterativeQuickSort(arr, 0, size);
      arr.assign(cpyArr.begin(), cpyArr.end());
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    auto time = duration.count() / TIMES;

    std::cout << "Time taken is " << time << "\n\n";
  }
}

int paritionArr(vector<int> &arr, int start, int end) {
  int pIndex = start;
  int pivot = arr[end];

  for (int i = start; i < end; i++) {
    if (arr[i] < pivot) {
      iter_swap(arr.begin() + i, arr.begin() + pIndex);
      pIndex++;
    }
  }

  iter_swap(arr.begin() + end, arr.begin() + pIndex);

  return pIndex;
}

void recursiveQuickSort(vector<int> &arr, int start, int end) {
  if (start < end) {
    int pIndex = paritionArr(arr, start, end);
    recursiveQuickSort(arr, start, pIndex - 1);
    recursiveQuickSort(arr, pIndex + 1, end);
  }
}

void iterativeQuickSort(vector<int> &arr, int start, int end) {
  vector<int> stack(end - start + 1);

  int top = -1;

  stack[++top] = start;
  stack[++top] = end;

  while (top >= 0) {
    end = stack[top--];
    start = stack[top--];

    int part = paritionArr(arr, start, end);

    if (part - 1 > start) {
      stack[++top] = start;
      stack[++top] = part - 1;
    }

    if (part + 1 < end) {
      stack[++top] = part + 1;
      stack[++top] = end;
    }
  }
}