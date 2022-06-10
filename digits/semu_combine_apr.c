unsigned long  klee_semu_GenMu_Mutant_ID_Selector = 2; 
void klee_semu_GenMu_Mutant_ID_Selector_Func (unsigned long fromID, unsigned long toID);
void klee_semu_GenMu_Post_Mutation_Point_Func (unsigned long fromID, unsigned long toID);
int main(int argc, char **argv) 
{ 
	int klee_condition;
	klee_semu_GenMu_Mutant_ID_Selector_Func(1,1);
	switch (klee_semu_GenMu_Mutant_ID_Selector) {
		case 1: klee_condition = 0; break;
		default: klee_condition = 1;
	}
	klee_semu_GenMu_Post_Mutation_Point_Func(0,0);
	klee_semu_GenMu_Post_Mutation_Point_Func(1,1);
  int n ;
  int r ;
  int nn ;

  {
  printf("\nEnter an integer > ");
klee_make_symbolic(& n, sizeof(n), "n");
  if (n == 0 && (klee_condition == 0 ? 0 : 1)) {
    printf("\n0");
  }
  while ((klee_condition == 0 ? 1 : n)) {
    if (n < 0) {
      n = - n;
      while (n) {
        r = n % 10;
        nn = n / 10;
        if (n < 10) {
          printf("\n-%d", r);
        } else
        if (n >= 10) {
          printf("\n%d", r);
        } else {

        }
        n = nn;
      }
    } else {
      r = n % 10;
      nn = n / 10;
      n = nn;
      printf("\n%d", r);
    }
    if ((klee_condition == 0 ? 1 : 0)){
    if (n) {

    } else {
      break;
    }
  }
}
  printf("\nThat\'s all, have a nice day!\n");
  return (0);
}
}
