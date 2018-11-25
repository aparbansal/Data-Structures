//Implements Stacks or LIFO structure
#include<iostream>

//Class for stacks using LL
class stack_node_class
{
public:
	int data;							//Stores data for node
	stack_node_class* link = NULL;		//Points to next node of stack
};



//Head pointer (global)
stack_node_class* tos = NULL;



//Functions
void push_to_top(int data)				//It's like inserting at head
{
	stack_node_class* temp	= new stack_node_class();
	temp->data				= data;
	temp->link				= tos;
	tos						= temp;
}

void pop_from_top()
{
	if(tos==NULL)
	{
		std::cout << "ERROR: No element to pop\nExiting...\n";
		exit(0);
	}
	stack_node_class* temp	= tos;
	tos						= temp->link;
	delete temp;
}

int top_of_stack()
{
	stack_node_class* temp	= tos;
	return (temp->data);
}

bool isEmpty()
{
	if(tos == NULL)
	{
		return (true);
	}
	return (false);
}

void Print()
{
	stack_node_class* temp	= tos;
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->link;
	}
	std::cout << std::endl;
}



int main()
{
	// Code to test the implementation.
	// calling Print() after each push or pop to see the state of stack.
	push_to_top(2);
	Print();
	push_to_top(5);
	Print();
	push_to_top(10);
	Print();
	pop_from_top();
	Print();
	push_to_top(12);
	Print();
}

/*
#define MAX_SIZE 101

class stack_array
{
	//Private data members
private:
	int s[MAX_SIZE];		//Stack using arrays
	int top;				//Points to Top Of Stack(TOS)

	//Public functions
public:
	stack_array()
	{
		top = -1;
	}
	void push_to_top(int);
	void pop_from_top();
	int top_of_stack();
	bool isEmpty();
	friend void Print(stack_array);
};


void stack::push_to_top(int data)
{
	if(top == MAX_SIZE-1)
	{
		std::cout << "ERROR: STACK OVERFLOW\nExiting...\n";
		exit(0);
	}
	top++;
	s[top] = data;
}

void stack::pop_from_top()
{
	if(top == -1)
	{
		std::cout << "ERROR: No element to pop\nExiting...\n";
		exit(0);
	}
	top--;	//No need to overwrite data. Just decrement TOS
}

int stack::top_of_stack()
{
	return s[top];
}

bool stack::isEmpty()
{
	if(top == -1)
	{
		return true;
	}
	return false;
}

void Print(stack_array passed_stack_object)
{
	for(int i=(passed_stack_object.top); i>=0; i--)
	{
		if(i == passed_stack_object.top)
			printf("stack[%d]	= %d		<--TOS\n", i, passed_stack_object.s[i]);
		else
			printf("stack[%d]	= %d\n", i, passed_stack_object.s[i]);
	}
	std::cout << std::endl;
}

int main()
{
	// Code to test the implementation.
	// calling Print() after each push or pop to see the state of stack.
	stack_array my_stack_object;
	my_stack_object.push_to_top(2);
	Print(my_stack_object);
	my_stack_object.push_to_top(5);
	Print(my_stack_object);
	my_stack_object.push_to_top(10);
	Print(my_stack_object);
	my_stack_object.pop_from_top();
	Print(my_stack_object);
	my_stack_object.push_to_top(12);
	Print(my_stack_object);
}

*/
