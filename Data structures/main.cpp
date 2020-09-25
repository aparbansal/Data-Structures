
#include<iostream>
//using namespace std;

class node
{
public:
	int data;
	node* next = NULL;
};

void print_fn(node*);
void insert_element_in_ll(int, int, node**);

int main()
{
	std::cout << "Welcome back Apar Bansal ~/-|" << std::endl;

	node* temp = new node();
	temp -> data = 1;
	temp -> next = NULL;

	node* head = temp;

	print_fn(head);
	insert_element_in_ll(2, 1, &head);
	print_fn(head);
	insert_element_in_ll(3, 0, &head);
	print_fn(head);

	return 0;
}


void print_fn(node* head)
{
	int i=0;
	std::cout << "Head: " << head << std::endl;
	while(head != NULL)
	{
		std::cout << i << ":	Data: " << head->data << "	Address: " << head << std::endl;
		head = head -> next;
		i++;
	}
	std::cout << std::endl;
}

void insert_element_in_ll(int data, int loc, node** head)			//passing address of head to make it passed by reference , instead of value to actually bring in the change
{
	int i=0;
	node* new_node = new node();
	new_node -> data = data;
	node* head_ptr = *head;
	if(head_ptr->next == NULL)
	{
		if(loc==0)
		{
			new_node->next	= head_ptr;
			head_ptr		= new_node;
		}
		else
		{
			head_ptr->next = new_node;
		}
		return;
	}
	while(head_ptr != NULL)
	{
		if(i==loc)
		{
			new_node->next	= head_ptr;
			*head			= new_node; //head_ptr		= new_node;
		}
		head_ptr = head_ptr->next;
		i++;
	}

}








//class node
//{
//public:
//	int data;
//	node* next = NULL;
//};
//
//
//void print(node**);
//void insert(int, int, node**);		//Data and position of element
//
//
//int main()
//{
//
//	//Node creation
//	node* head = NULL;
//	node* temp = new node();
//	temp -> data = 2;
//	temp -> next = NULL;
//	head = temp;
//
//	std::cout << "Before inserting node: \n";
//	print(&head);
//
//	//Inserting node at the beginning
//	node* temp2 = new node();
//	temp2 -> data = 3;			//Any value
//	temp2 -> next = head;
//	head = temp2;
//
//	std::cout << "\nAfter inserting node: \n";
//	print(&head);
//
//	insert(10,1,&head);		//Insert 2 at 1st index. Also calling head
//	std::cout << "\nAfter inserting node by insert function: \n";
//	print(&head);
//
///*	//Traversing and printing
//	node* temp1 = head;
//	int i=0;
//	//cout <<"null=" << NULL << endl;
//while(temp1->next != NULL)
//	{
//		i++;
//		cout << i << "	Current Address:" << temp1 << "	Pointed Address:" << temp1->next << "	Value:" << temp1->data << endl;
//
//		temp1 = temp1->next;
//	}
//
//	//Traversing
//	node* temp1 = head;
//	int i=0;
//	//cout <<"null=" << NULL << endl;
//while(temp1->next != NULL)
//	{
//		i++;
//		std::cout << i << "	Current Address:" << temp1 << "	Pointed Address:" << temp1->next << "	Value:" << temp1->data << std::endl;
//
//		temp1 = temp1->next;
//	}	*/
//}
//
//
//void print(node** x)
//{
//	//Traversing and printing
//	node* temp1 = *x;
//	int i=0;
//	std::cout << "Head:" <<  *x << std::endl;
//	while(temp1 != NULL)
//	{
//		std::cout << i << " Current Addr:" << temp1 << "  Pointed Addr:" << temp1->next << "  Value:" << temp1->data << std::endl;
//		temp1 = temp1->next;
//		i++;
//	}
//}
//
//void insert(int data_in, int location, node** x)
//{
//	node* temp1 = new node();
//	temp1 -> data = data_in;
//	temp1 -> next = NULL;
//
//	if(location == 1)	//Head
//	{
//		temp1 -> next = *x;
//		*x = temp1;
//		return;
//	}
//
//	node* temp2 = *x;
//	for(int i=0; i<location-2; i++)
//	{
//		temp2 = temp2 -> next;
//	}
//	temp1 -> next = temp2 -> next;
//	temp2 -> next = temp1;
//}
//
//