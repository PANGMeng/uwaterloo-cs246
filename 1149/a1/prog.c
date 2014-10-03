#include <stdio.h>

int main(int argc, char *argv[]) {
  int x;
  if (argc > 1) {
    fprintf(stderr, "This program was not meant to take command line arguments!\n");
    return 1;
  }
  scanf("%d", &x);
  printf("%d\n", x+1);
  return 0;
}
