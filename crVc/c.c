#include <stdio.h>
#include <stdbool.h>

#define SIZE 10000

int toSort[SIZE];

void build(int l[]);
void sort(int l[]);

int main(void) {
  build(toSort);
  sort(toSort);

  return 0;

}

void build(int l[]) {
  int num = SIZE;
  for (int i = 0; i < SIZE; i++) {
    l[i] = num;
    num--;
  }
}

void sort(int l[]) {
  bool sorted = false;
  while (!sorted) {
    sorted = true;
    for (int i = 0; i < SIZE - 1; i++) {
      if (l[i] > l[i + 1]) {
        int temp = l[i + 1];
        l[i + 1] = l[i];
        l[i] = temp;
        sorted = false;
      }
    }
  }

}
