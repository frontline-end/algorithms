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

void displayLRN(Node *root) {
  if (root != NULL) {
    displayLRN(root->left);
    displayLRN(root->right);
    printf("%d ", root->data);    
  }
}

void displayNLR(Node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    displayNLR(root->left);
    displayNLR(root->right);
  }
}


int main() {

  Node *root = NULL;

  root = insertNode(root, 3);
  root = insertNode(root, 6);
  root = insertNode(root, 1);
  root = insertNode(root, 2);
  root = insertNode(root, 8);
  root = insertNode(root, 5);
  root = insertNode(root, 0);

  displayLNR(root);
  
  printf("\n");
  
  displayNLR(root);

  printf("\n");

  displayLRN(root);
  
  return EXIT_SUCCESS;  
}  
