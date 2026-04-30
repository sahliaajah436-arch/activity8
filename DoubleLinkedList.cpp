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

        
    }
};