#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }
    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // Step 1: Allocate memory for new node
        Node *newNode = new Node();

        // Step 2: Assign values
        newNode->noMhs = nim;

        // Step 3: Insert at beginning if list empty or first element
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate roll numbers not allowed" << endl;
                return;
            }
             newNode->next = START;

            if (START != NULL)
                START->prev = newNode;

            newNode->prev = NULL;
            START = newNode;
            return;
        }
        // Step 4: Traverse to find position
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && current->next->noMhs == nim)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        // Step 5: Insert between nodes
        newNode->next = current->next;

        if (current->next != NULL)
            current->next->prev = newNode;

        current->next = newNode;
        newNode->prev = current;
    }

    void delNode()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to delete: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "\nRecord not found" << endl;
            return;
        }

        if (current == START)
        {
            START = current->next;
            if (START != NULL)
                START->prev = NULL;
        }
        

    }
};