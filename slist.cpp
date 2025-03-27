
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

typedef string ItemType;
struct NodeType;
typedef NodeType* NodePtr;

struct NodeType {
   ItemType data;
   NodePtr next;
};

// Declare the function "Insert" here
void Insert(NodePtr &head, ItemType data);

// Declare the function "Delete" here
void Delete(NodePtr &head, ItemType data);

// Declare the function "ReleaseList" here
void ReleaseList(NodePtr &head);

bool IsPresent(NodePtr head, ItemType data);
void DisplayList(NodePtr head);
void BuildList(ifstream & myIn, NodePtr & head);

int main()
{
    ifstream myIn;
    ItemType item;
    NodePtr  head = NULL;  // the pointer points to the beginning of the list
    
    myIn.open("grocery.dat");
    assert(myIn);

    BuildList(myIn, head);
    DisplayList(head);

    cout << endl; 
    cout << "Enter an item to be deleted from the list:";  
    cin >> item; 

    if (IsPresent(head, item))
    {
         Delete(head, item);
         cout << item << " deleted from the list." << endl;
         DisplayList(head);
    }
    else
         cout << "Item is not in the list." << endl;

    myIn.close();

    ReleaseList(head);

    return 0;
}

// Define the function "Insert" here. This function inserts a value into a list such that
// the list is always in sorted order, i.e., sorted in alphabetically ascending order
void Insert(NodePtr &head, ItemType data)
{
    NodePtr newNode = new NodeType{data, nullptr};
    if (!head || data < head->data)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        NodePtr cur = head;
        while (cur->next && cur->next->data < data)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

// Define the function "Delete" here. This function deletes a value from the list 
// If the list is empty, show an appropriate message indicating that fact;
// The item to be deleted may be the first item in the list,
// Or it may occur in the middle or at the end of the list.
// If the item is not found in the list, show an appropriate message indicating that;
void Delete(NodePtr &head, ItemType data)
{
    if (!head)
    {
        cout << "The list is empty." << endl;
        return;
    }
    if (head->data == data)
    {
        NodePtr temp = head;
        head = head->next;
        delete temp;
        return;
    }
    NodePtr cur = head;
    while (cur->next && cur->next->data != data)
    {
        cur = cur->next;
    }
    if (!cur->next)
    {
        cout << "Item not found in the list." << endl;
        return;
    }
    NodePtr temp = cur->next;
    cur->next = cur->next->next;
    delete temp;
}

// Define the function "ReleaseList" here. This function releases the memory of all the nodes in the list
void ReleaseList(NodePtr &head)
{
    NodePtr temp;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// function "BuildList" reads the values one by one from the datafile and calls
// the "Insert" function to insert each value into the linked list
void BuildList(ifstream & myIn, NodePtr & head)
{
    string item;
    while (myIn >> item)
    {
         Insert(head, item);
    }
}

// function "DisplayList" prints all the items in the list one by one
void DisplayList(NodePtr head)
{
    NodePtr cur = head;
    cout << "The list of items are:\n";   // Newline after the label 
    cout << endl; 
    while (cur != NULL) 
    {
        cout << cur->data << endl;  
        cur = cur->next;
    }
}

// Function "IsPresent" returns true if the item to search for is 
// in the list, otherwise it returns false
bool IsPresent(NodePtr head, ItemType item)
{
    NodePtr cur = head;
    while (cur != NULL)
    {
       if (cur->data == item)
       {
           return true;
       }
       cur = cur->next;
    }
    
    return false;
}
