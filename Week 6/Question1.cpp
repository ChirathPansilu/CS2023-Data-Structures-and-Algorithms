#include <iostream>
using namespace std;

#define MAX 100

class Stack {
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

		for (int i = top; i >= 0; i--)
			cout << stack[i] << "\n";
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