#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUNNY 0
#define RAINY 1
#define CLOUDY 2

#define STATUS 3

float transition[STATUS][STATUS] = {{0.3, 0.3, 0.4},
                                    {0.2, 0.4, 0.4},
                                    {0.4, 0.4, 0.2}};

char *status[STATUS] = {"sunny", "rainny", "cloudy"};

int changeTransition(int current) {

  float limits = (float)rand() / (float)RAND_MAX;
  float cumulative = 0.0;

  for (int i = 0; i < STATUS; i++) {
    cumulative += transition[current][i];
    if (cumulative > limits) {
      return i;      
    }      
  }     
  return current; //by default
}
int main() {

  srand(time(NULL));
  int current = SUNNY;

  for (int i = 0; i < 10; i++) {
    printf("%s\n", status[current]);
    current = changeTransition(current);
  }
  
  return EXIT_SUCCESS;  
}  
