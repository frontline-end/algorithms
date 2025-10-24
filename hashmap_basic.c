#ifdef _WIN32
-#define _strdup strdup //windows 
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 53 //prime number is better
#define LOAD_FACTOR 0.85 //for resize map when total existed nodes > 85%

/*declaration what node's inside*/
typedef struct Node {
  char *key;
  int data;
  struct Node *next; //same linked list
} Node;

typedef struct HashMap {
  Node **table;
  int capacity;
  int size;
} HashMap;

/*create map*/
HashMap *createMap() {
  HashMap *newMap = malloc(sizeof(HashMap));
  if (newMap == NULL) {
    fprintf(stderr, "createMap()\n");
    return NULL;    
  }    
  newMap->capacity = INITIAL_SIZE;
  newMap->size = 0;
  newMap->table = calloc(newMap->capacity, sizeof(Node *));  
  return newMap;
}

/*create node with key n data*/
Node *createNode(char *key, int data) {
  Node *newNode = malloc(sizeof(Node));
  newNode->key = strdup(key);
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

/*djb2's hash*/
unsigned long hash(char *key, int capacity) {
  unsigned long hash = 5381;
  int c;
  while ((c = *key++)) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash % capacity;
}

/*insert time*/
void insert(HashMap *map, char *key, int data) {
  unsigned long index = hash(key, map->capacity);
  Node *entry = map->table[index];
  while (entry) {
    if (strcmp(entry->key, key) == 0) {
      entry->data = data;
      return; //no more run
    }
    entry = entry->next; //what if current node's next has da same key?
  }
  // when some datas that doesnt exist => create it
  Node *newNode = createNode(key, data);
  newNode->next = map->table[index];
  map->table[index] = newNode;
}

/*delete some node by key, its just skip node and free() at prev*/
void deleteNode(HashMap *map, char *key) {
  unsigned long index = hash(key, map->capacity);
  Node *entry = map->table[index];
  Node *prev = NULL;
  while (entry) {
    if (strcmp(entry->key, key) == 0) {
      if (prev) {
	prev->next = entry->next;
      } else {
	map->table[index] = entry->next;
      }
      free(entry->key);
      free(entry);
      return;      
    }
    prev = entry;
    entry = entry->next;    
  }
}

/*display all table for debug?*/
void displayAll(HashMap *map) {
  for (int i = 0; i < map->capacity; i++) {
    Node *entry = map->table[i];
    while (entry) {
      printf("at %d: %s, %d->\n", i, entry->key, entry->data);
      entry = entry->next;
    }
    printf("NULL->\n");    
  }
}

int main() {

  HashMap *myMap;
  myMap = createMap();

  insert(myMap, "chanh", 20);
  insert(myMap, "vy", 20);

  deleteNode(myMap, "vy");
  
  displayAll(myMap);  
  
  return EXIT_SUCCESS;  
}  
