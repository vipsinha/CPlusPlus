// Classes
/* Aut: Vipul Sinha, Date: 2020-02-20 */

#include "iostream"
using namespace std;

struct Node
{
    int data;
    Node* Link;
};

void insertNode(Node* node, int nodeData);
void printNode(Node* node);

int main()
{
    Node headNode;
    headNode.data = 20;
    headNode.Link = NULL; 

    insertNode(&headNode, 30);
    printNode(&headNode);

    return 0;
}

void insertNode(Node* node, int nodeData)
{
    Node tempNode;
    tempNode.data = nodeData;
    tempNode.Link = NULL;
    node->Link = &tempNode;
}

void printNode(Node* node)
{
    Node* tempNode = node;
    while(tempNode->Link != NULL)
    {
        cout << tempNode->data << endl;
        tempNode->Link = tempNode;  
    }
}