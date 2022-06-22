#include<stdio.h>

void moveX(char *str, int i) {
  if(str[i] !='\0') {
    if(str[i] != 'x') {
      printf("%c", str[i]);
      moveX(str, i+1);
    } else {
      moveX(str, i+1);
      printf("%c", str[i]);
    }

  }
}
int main() {
  char str[101];

  scanf("%s", str);
  moveX(str, 0);
  printf("\n");
  return 0;
}