#include <stdio.h>
int main(void) {
  int score;
  printf("Enter student score\n");
  scanf("%d", &score);
  if(score >= 41) {
    printf("Passed. Congrats! \n");
  }
  else {
    printf("Failed. See you next year. \n");
  }
  return 0;
}
