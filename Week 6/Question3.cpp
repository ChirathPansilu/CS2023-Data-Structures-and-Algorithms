#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX 100

class StackUsingArray {
	int stack[MAX];
	int top = -1;

public:
	void push(int x)
	{
		top++;

		if (top == MAX)
		{
			top--;
			cerr << "ERROR: Stack Overflow\n";
		}
		else
		{
			stack[top] = x;
		}
	}

	int pop() {
		if (top == -1)
		{
			cerr << "ERROR: Stack Underflow\n";
		}
		else
		{
			int x = stack[top];
			top--;
			return x;
		}
	}

	bool isEmpty() {
		return (top == -1);
	}

	bool isFull() {
		return (top == MAX - 1);
	}

	int stackTop() {
		if (isEmpty())
			cerr << "ERROR: Stack Underflow\n";

		return stack[top];
	}

	void display() {
		if (top == -1)
			cerr << "Stack Underflow\n";

		cout << "[ ";
		for (int i = top; i >= 0; i--)
			cout << stack[i] << ", " << "\n";
		cout << " ]\n";
	}
};

struct Node {
	int data = 0;
	Node* next = nullptr;
};

class StackUsingList {
	Node* top = nullptr;

public:
	void push(int x) {
		Node* newNode = new Node;
		newNode->data = x;
		newNode->next = top;
		top = newNode;
	}

	int pop() {
		if (isEmpty())
			cerr << "ERROR: Stack Underflow\n";

		int x = top->data;
		Node* temp = top;
		top = top->next;
		delete temp;

		return x;
	}

	bool isEmpty() {
		return top == nullptr;
	}

	int stackTop() {
		if (isEmpty())
			cerr << "ERROR: Stack Underflow\n";

		return top->data;
	}

	void display() {
		if (isEmpty())
			cerr << "ERROR: Stack Underflow\n";

		cout << "[ ";
		Node* node = top;
		while (node != nullptr) {
			cout << node->data << ", ";
			node = node->next;
		}
		cout << " ]\n";
	}
};

#define TIMES 1000

int main() {
	//Calculate time for StackUsingArray
	auto start1 = high_resolution_clock::now();
	for (int i = 0; i < TIMES; i++)
	{
		StackUsingArray stackArray;
		
		stackArray.push(8);
		stackArray.push(10);
		stackArray.push(5);
		stackArray.push(11);
		stackArray.push(15);
		stackArray.push(23);
		stackArray.push(6);
		stackArray.push(18);
		stackArray.push(20);
		stackArray.push(17);

		stackArray.display();

		for (int j = 0; j < 5; j++)
			stackArray.pop();

		stackArray.display();

		stackArray.push(4);
		stackArray.push(30);
		stackArray.push(3);
		stackArray.push(1);

		stackArray.display();
	}
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	auto time1 = duration1.count() / TIMES;

	//Calculate time for StackUsingList
	auto start2 = high_resolution_clock::now();
	for (int i = 0; i < TIMES; i++)
	{
		StackUsingList stackList;
		
		stackList.push(8);
		stackList.push(10);
		stackList.push(5);
		stackList.push(11);
		stackList.push(15);
		stackList.push(23);
		stackList.push(6);
		stackList.push(18);
		stackList.push(20);
		stackList.push(17);

		stackList.display();

		for (int j = 0; j < 5; j++)
			stackList.pop();

		stackList.display();

		stackList.push(4);
		stackList.push(30);
		stackList.push(3);
		stackList.push(1);

		stackList.display();
	}
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	auto time2 = duration2.count() / TIMES;

	cout << "Time taken by StackUsingArray: " << time1 << " microseconds" << endl;
	cout << "Time taken by StackUsingList: " << time2 << " microseconds" << endl;
}