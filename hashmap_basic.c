#ifdef _WIN32
#define _strdup strdup //windows 
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 13 //prime number is better
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

/*resize map when existed node cross 85%*/
/*send a warning message when capacity > 1051, no pc can handle that lol*/
int primes[] = {107, 211, 443, 839, 1051};

int nextCapacity(int current) {
  int size = sizeof(primes) / sizeof(primes[0]);
  for (int i = 0; i < size; i++) {    
    if (*(primes + i) > current) {
      return *(primes + i);      
    }
  }
  printf("warning: capacity over 1051, remember free it when no longer use!\n");  
  return current * 2 - 1; // not a prime number but ok i will find the way out
}

/*resize map for sure*/
void resizeMap(HashMap *map) {
  int oldCapacity = map->capacity;
  int newCapacity = nextCapacity(oldCapacity);
  
  Node **newTable = calloc(newCapacity, sizeof(Node*));  
  
  for (int i = 0; i < oldCapacity; i++) {
    Node *entry = map->table[i];
    while (entry) {
      Node *next = entry->next; //keep all node from old table
      unsigned long index = hash(entry->key, newCapacity);
      
      entry->next = newTable[index]; //connect from oldtable's node to new map 
      newTable[index] = entry;
      
      entry = next;
    }
  }
  
  free(map->table);
  map->capacity = newCapacity;
  map->table = newTable;
  printf("bfdf");  
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
  map->size++;

  /*resize map*/  
  if ((float)(map->size) / (map->capacity) > LOAD_FACTOR) {
    resizeMap(map);
  }
  
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
      map->size--;      
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

/*how about look up by data => print key?*/
void lookUpByData(HashMap *map, int data) {
  for (int i = 0; i < map->capacity; i++) {
    Node *entry = map->table[i];
    while (entry) {
      if (entry->data == data) {
	printf("%s ", entry->key);
      }
      entry = entry->next;      
    }      
  }
}

/*delete all map*/
void deleteMap(HashMap *Map) {
  for (int i = 0; i < Map->capacity; i++) {
    Node *entry = Map->table[i];
    while (entry) {
      Node *temp = entry->next;
      free(entry->key);
      free(entry);
      entry = temp;      
    }
  }
  free(Map->table);
  free(Map);
}

int main() {

  HashMap *myMap;
  myMap = createMap();

  insert(myMap, "chanh", 20);
  insert(myMap, "vy", 20);
  insert(myMap, "tram", 20);
  insert(myMap, "thoai", 20);
  insert(myMap, "khoi", 20);
  insert(myMap, "khang", 20);
  insert(myMap, "khuem", 20);
  insert(myMap, "hung", 20);
  insert(myMap, "tin", 20);

  //printf("%d\n", myMap->capacity);

  //lookUpByData(myMap, 20);  
  
  //displayAll(myMap);

  deleteMap(myMap);
  
  return EXIT_SUCCESS;  
}  
