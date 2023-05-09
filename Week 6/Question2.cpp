#include <iostream>

using namespace std;

struct Node {
	int data = 0;
	Node* next = nullptr;
};

class Stack {
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
			cerr << "[ ]\n";
		

		Node* node = top;
		while (node != nullptr) {
			cout << node->data << "\n";
			node = node->next;
		}
	}
};

int main() {
	Stack stack;

	stack.push(8);
	stack.push(10);
	stack.push(5);
	stack.push(11);
	stack.push(15);
	stack.push(23);
	stack.push(6);
	stack.push(18);
	stack.push(20);
	stack.push(17);

	stack.display();

	for (int j = 0; j < 5; j++)
		stack.pop();

	stack.display();

	stack.push(4);
	stack.push(30);
	stack.push(3);
	stack.push(1);
	
	stack.display();

	return 0;
}
