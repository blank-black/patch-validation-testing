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
  char inputString[20] ;
  int length ;
  int k ;
  int j ;
  int syl ;
  char vowels[6] ;
  char temp ;

  {
  vowels[0] = (char )'a';
  vowels[1] = (char )'e';
  vowels[2] = (char )'i';
  vowels[3] = (char )'o';
  vowels[4] = (char )'u';
  vowels[5] = (char )'y';
  k = 0;
  j = 0;
  syl = 0;
  printf("Please enter a string > ");
klee_make_symbolic(inputString, sizeof(inputString), "inputString");
  length = strlen(inputString);
  k = 0;
  while (k < length) {
    temp = inputString[k];
    j = 0;
    while ((klee_condition == 0 ? 1 : j < 6)) {
      if ((int )temp == (int )vowels[j]) {
        syl ++;
        j = (klee_condition == 0 ? 5 : 99);
      } else {

      }
      if ((klee_condition == 0 ? 1 : 0)){
      if (j < 5) {

      } else {
        break;
      }
    }
      j ++;
    }
    k ++;
  }
  printf("The number of syllables is %d.", syl);
  return (0);
}
}
