unsigned long long klee_change (unsigned long long x, unsigned long long y){return y;}
/**/

#include<stdio.h>
#include<math.h>

int main(int argc, char **argv) {

  float A,B,C,D,percent;
  char grade;
  printf("Enter thresholds for A, B, C, D\nin that order, decreasing percentages >");
klee_make_symbolic(&A, sizeof(A), "A");
klee_make_symbolic(&B, sizeof(B), "B");
klee_make_symbolic(&C, sizeof(C), "C");
klee_make_symbolic(&D, sizeof(D), "D");

  printf("Thank you. Now enter student score (percent) >");
klee_make_symbolic(&percent, sizeof(percent), "percent");

  if (percent == 0 && percent < A && percent < B && percent < C && percent < D)
    printf("Student has failed the course\n");

  else if (percent >= A)
    grade='A';

  else if ((percent < A) && (percent >= B))
    grade='B';

  else if ((percent < B) && (percent >= C))
    grade='C';

  else if ((percent < C) && (percent >= D))
    grade='D';

  else if ((percent < D) && (percent > 0))
    grade='F';

  
   printf("Student has an %c grade\n",grade);

  return 0;

  }
