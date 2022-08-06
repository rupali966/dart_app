#include <iostream>

class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class linkedlist
{
    node *head;

public:
    linkedlist() { head = NULL; }
    void insert(int);
    void printlist();
    void deletenode(int);
};
void linkedlist::insert(int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void linkedlist::printlist()
{
    node *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data <<" - ";
        temp = temp->next;
    }
    
}

int main()
{
    linkedlist ll = linkedlist();
    ll.insert(5);
    ll.insert(6);
    ll.insert(2);
    ll.insert(7);
    ll.insert(12);
    ll.insert(8);
    ll.printlist();
    return 0;
}