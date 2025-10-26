#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int data) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;  
}

Node *insertNode(Node *root, int data) {

  /*when node with data doesnt exist => create it*/  
  if (root == NULL) {
    root = createNode(data);
  }

  /*trying to find node null*/  
  if (data > root->data) {
    root->right = insertNode(root->right, data); //rule in bst: when new data > current data in tree =>go right
  } else if (data < root->data) {
    root->left = insertNode(root->left, data); //same but left, when new data < current data in tree
  }

  return root;  
}

void displayLNR(Node *root) {
  if (root != NULL) {
    displayLNR(root->left);
    printf("%d ", root->data);
    displayLNR(root->right);    
  }    
}

int main() {

  Node *root = NULL;

  root = insertNode(root, 3);
  root = insertNode(root, 6);

  displayLNR(root);  
  
  return EXIT_SUCCESS;  
}  
