unsigned long  klee_semu_GenMu_Mutant_ID_Selector = 2; 
void klee_semu_GenMu_Mutant_ID_Selector_Func (unsigned long fromID, unsigned long toID);
void klee_semu_GenMu_Post_Mutation_Point_Func (unsigned long fromID, unsigned long toID);
int main(int argc, char **argv) {
	int klee_condition;
	klee_semu_GenMu_Mutant_ID_Selector_Func(1,1);
	switch (klee_semu_GenMu_Mutant_ID_Selector) {
		case 1: klee_condition = 0; break;
		default: klee_condition = 1;
	}
	klee_semu_GenMu_Post_Mutation_Point_Func(0,0);
	klee_semu_GenMu_Post_Mutation_Point_Func(1,1);

  float A,B,C,D,percent;
  char grade;
  printf("Enter thresholds for A, B, C, D\nin that order, decreasing percentages >");
klee_make_symbolic(&A, sizeof(A), "A");
klee_make_symbolic(&B, sizeof(B), "B");
klee_make_symbolic(&C, sizeof(C), "C");
klee_make_symbolic(&D, sizeof(D), "D");

  printf("Thank you. Now enter student score (percent) >");
klee_make_symbolic(&percent, sizeof(percent), "percent");

  if (percent == 0 && percent < A && percent < B && percent < C && percent < D && (klee_condition == 0 ? 1 : 0))
    printf("Student has failed the course\n");

  else if (percent >= A)
    grade='A';

  else if ((percent < A) && (percent >= B))
    grade='B';

  else if ((percent < B) && (percent >= C))
    grade='C';

  else if ((percent < C) && (percent >= D))
    grade='D';

  else if ((percent < D) && (percent > 0) && (klee_condition == 0 ? 1 : 0))
    grade='F';

  else if ((percent < D) && (klee_condition == 0 ? 0 : 1))
    printf("Student has failed the course\n");

  if ((klee_condition == 0 ? 1 : 0) || percent >= D)
   printf("Student has an %c grade\n",grade);

  return 0;

  }
