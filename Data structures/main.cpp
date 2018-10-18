
#include<iostream>
//using namespace std;

class node
{
public:
	int data;
	node* next = NULL;
};


void print(node**);
void insert(int, int, node**);		//Data and position of element


int main()
{

	//Node creation
	node* head = NULL;
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

	insert(10,1,&head);		//Insert 2 at 1st index. Also calling head
	std::cout << "\nAfter inserting node by insert function: \n";
	print(&head);

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
		std::cout << i << " Current Addr:" << temp1 << "  Pointed Addr:" << temp1->next << "  Value:" << temp1->data << std::endl;
		temp1 = temp1->next;
		i++;
	}
}

void insert(int data_in, int location, node** x)
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
	for(int i=0; i<location-2; i++)
	{
		temp2 = temp2 -> next;
	}
	temp1 -> next = temp2 -> next;
	temp2 -> next = temp1;
}

