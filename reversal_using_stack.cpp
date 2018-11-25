//Reversing strings and linked list using stacks
#include<iostream>
#include<stack>
#include<cstring>

/*
//For string reversal
void reverse_string(char*, int);
*/

//For LL reversal
void reverse_LL();
void print();
class node
{
public:
	int data;
	node* link = NULL;
};
node* headptr = NULL;


int main()
{
	/*
	std::cout << "Reversing a string using stacks:\n";
	char my_string[51];
	gets(my_string);
	reverse(my_string, strlen(my_string));
	printf("Reversed string = %s\n", my_string);
	*/
	
	std::cout << "\nReversing a linked List using stacks:\n";
	node* temp2		= new node();
	temp2 -> data	= 2;
	temp2 -> link	= NULL;
	headptr			= temp2;
	node* temp3		= new node();
	temp3 -> data	= 3;			
	temp3 -> link	= headptr;
	headptr			= temp3;
	printf("LL before reversal:\n");
	print();
	reverse_LL();
	printf("LL after reversal:\n");
	print();
}

/*
void reverse_string(char* my_string, int length)
{
	std::stack <char> char_stack;
	
	//Pushing chars to stack
	for(int i=0; i<length; i++)
	{
		char_stack.push(my_string[i]);
	}
	
	//Poping chars from stack
	for(int i=0; i<length; i++)
	{
		my_string[i] = char_stack.top();
		char_stack.pop();
	}
}
*/

void reverse_LL()
{
	std::stack <node*> stack_LL;
	
	node* temp = headptr;
	//Pushing LL nodes to stack
	while(temp != NULL)
	{
		stack_LL.push(temp);
		temp = temp->link;
	}
	
	temp	= stack_LL.top();
	headptr		= temp;
	stack_LL.pop();
	//Pushing LL nodes to stack
	while(!stack_LL.empty())
	{
		temp->link	= stack_LL.top();
		stack_LL.pop();
		temp = temp->link;
	}
	temp->link = NULL;
}


void print()
{
	//Traversing and printing
	node* temp1 = headptr;
	int i=0;
	std::cout << "Head:" <<  headptr << std::endl;
	while(temp1 != NULL)
	{
		i++;
		std::cout << i << " Current Addr:" << temp1 << "  Pointed Addr:" << temp1->link << "  Value:" << temp1->data << std::endl;
		temp1 = temp1->link;
	}
}