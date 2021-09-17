

#include <iostream>

struct Node {
  int tag;
  Node *next; // pointer to next node
};

int main() {
  // the head node
  Node *head = new Node;

  head->tag = 0; // set the tag to be 0

  Node *curr = head; // create the current counter

  // Construct ten nodes
  for (int i = 0; i < 10; ++i) {
    curr->next = new Node; // current Node points to a new node address

    curr = curr->next; //

    curr->tag = i + 1;
  }
  curr->next = nullptr;
  // how do we loop through the linked list
  //
  for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
    std::cout << "node:[" << ptr->tag << "]\n";
  }
  // task  add new node between node[3] and node[4]
  //
  // save node[4]
  // node[3]-> next=new Node
  //
  // newNOde->next = node[4]
  //
  curr = head;

  for (int i = 0; i < 3; ++i) {
    curr = curr->next;
  }

  std::cout << "curr points at node[" << curr->tag << "]\n";
}
