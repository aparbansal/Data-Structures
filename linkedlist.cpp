
#include<iostream>
//using namespace std;

class node
{
public:
	int data;
	node* next = NULL;
};


void print(node**);					//Prints LL. 	 Passing address of node that points to head
void reversePrint(node**);					//Recursively reverse prints LL. 	 Passing address of head
void insert(int, int, node**);		//Inserts nodes. Passing Data, Position of element and Head's address
void deleter(int, node**);			//Deletes nodes. Position of element and head
void reverse(node**);				//Reverses LL

int main()
{

	//Node creation
	node* head = NULL;		//This is not the head of LL. It is pointer to head node.
	node* temp = new node();
	temp -> data = 2;
	temp -> next = NULL;
	head = temp;

	std::cout << "Before inserting node: \n";
	print(&head);

	//Inserting node at the beginning
	node* temp2 = new node();
	temp2 -> data = 3;			//Any value
	temp2 -> next = head;
	head = temp2;

	std::cout << "\nAfter inserting node: \n";
	print(&head);

	insert(10, 1, &head);		//Insert 2 at 1st index. Also calling head
	insert(1000, 2, &head);
	insert(11, 2, &head);
	std::cout << "\nAfter inserting node by insert function: \n";
	print(&head);

	deleter(2, &head);
	std::cout << "\nAfter deleting node: \n";
	print(&head);

	reverse(&head);
	std::cout << "\nAfter reversing LL: \n";
	print(&head);

	std::cout << "\nJust recursive reverse printing LL: \n";
	reversePrint(&head);
/*	//Traversing and printing
	node* temp1 = head;
	int i=0;
	//cout <<"null=" << NULL << endl;
while(temp1->next != NULL)
	{
		i++;
		cout << i << "	Current Address:" << temp1 << "	Pointed Address:" << temp1->next << "	Value:" << temp1->data << endl;

		temp1 = temp1->next;
	}

	//Traversing
	node* temp1 = head;
	int i=0;
	//cout <<"null=" << NULL << endl;
while(temp1->next != NULL)
	{
		i++;
		std::cout << i << "	Current Address:" << temp1 << "	Pointed Address:" << temp1->next << "	Value:" << temp1->data << std::endl;

		temp1 = temp1->next;
	}	*/
}


void print(node** x)
{

	//Traversing and printing
	node* temp1 = *x;
	int i=0;
	std::cout << "Head:" <<  *x << std::endl;
	while(temp1 != NULL)
	{
		i++;
		std::cout << i << " Current Addr:" << temp1 << "  Pointed Addr:" << temp1->next << "  Value:" << temp1->data << std::endl;
		temp1 = temp1->next;
	}

/*
	//Printing using recursion
	if(*x == NULL)		//Breaks out of recursion
	{
		return;
	}
	std::cout << " Current Addr:" << *x << "  Pointed Addr:" << (*x)->next << "  Value:" << (*x)->data << std::endl;
	print(&((*x)->next));			//Print function accepts addresses to pointers to arguments. That is why the complex thing.
	*/
}

void reversePrint(node** x)
{
	//Reverse recursive printing
	if(*x == NULL)
	{
		return;
	}
	reversePrint(&((*x)->next));	//Think of this as one function inside another (like a serial code) and you will get it.
	std::cout << " Current Addr:" << *x << "  Pointed Addr:" << (*x)->next << "  Value:" << (*x)->data << std::endl;
}

void insert(int data_in, int location, node** x)  //location should be valid
{
	node* temp1 = new node();
	temp1 -> data = data_in;
	temp1 -> next = NULL;

	if(location == 1)	//Head
	{
		temp1 -> next = *x;
		*x = temp1;
		return;
	}

	node* temp2 = *x;
	for(int i=0; i<location-2; i++)		//This takes us to the (n-1)th node
	{
		temp2 = temp2 -> next;
	}
	temp1 -> next = temp2 -> next;
	temp2 -> next = temp1;
}

void deleter(int loc, node** x)
{
	node* temp1 = *x;

	if(loc == 1)		//When first node is to be deleted
	{
		*x = temp1 -> next;		//Head points to 2nd node
		delete temp1;
		return;
	}

	for(int i = 0; i < loc-2; i++)
	{
		temp1 = temp1->next;		//Temp1 is (n-1)th node
	}
	node* temp2 = temp1->next;		//temp2 is the node to be deleted
	temp1->next = temp2->next;		//temp1 points to (n+1)th node now
	delete temp2;
}

void reverse(node** x)
{
	node* current	= *x;
	node* next_node	= NULL;
	node* prev_node	= NULL;

	while(current != NULL)
	{
		next_node		= current->next;	//point to node next to current
		current->next	= prev_node;		//current node points to previous node (link reversal)
		prev_node		= current;			//move previous node up
		current			= next_node;				//move current node to next. If this is not done, the first statement in next iteration of while() would have no effect
	}
	*x = prev_node;		//Head points to last node now
}
