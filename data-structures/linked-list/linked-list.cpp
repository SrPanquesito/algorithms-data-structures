#include <iostream>
using namespace std;

struct Node {
  int data;
  Node * link;
};

Node * newNode(Node * temp, Node * node) {
  Node * newNode = new Node();
  node->link = newNode;
  return newNode;
}

Node * newTemp(Node * temp, Node * node, Node * head, int isHeader) {
  int x;
  cout << "Node value: ";
  cin >> x;
  cout << "\n";
  temp->data = x;
  temp->link = NULL;

  if (isHeader == 1) {
    *head = *temp;
  }

  *node = *temp;

  return new Node();
}

void printList(Node * tempNode) {
  cout << "Head: \n";
  cout << tempNode->data << "\n";
  cout << tempNode->link << "\n\n";

  while (tempNode->link != NULL) {
    tempNode = tempNode->link;

    cout << "Node: \n";
    cout << tempNode->data << "\n";
    cout << tempNode->link << "\n\n";
  }
}

int main() {
  Node * temp = new Node();
  Node * node = new Node();
  Node * head = new Node();

  int op;
  int headerSet = 0;
  while(op != 0) {
    cout << "Select an option:" << "\n";
    cout << "1) Set header" << "\n";
    cout << "2) Create new node" << "\n";
    cout << "3) Print list" << "\n";
    cout << "0) Exit" << "\n : ";
    cin >> op;
    cout << "\n";

    if (op == 1) {
      if (headerSet == 0) {
        temp = newTemp(temp, node, head, 1);
        headerSet = 1;
      } else {
        cout << "Header already set. Proceed to create a new node." << "\n";
      }
    }
    else if (op == 2) {
      node = newNode(temp, node);
      if (headerSet == 1) {
        head->link = node;
        headerSet = 2;
      }
      temp = newTemp(temp, node, head, 0);
    }
    else if (op == 3) {
      printList(head);
    }
    else if (op == 0) {

    }
    else {
      cout << "Enter a valid option." << "\n";
    }
  };
  return 0;
}