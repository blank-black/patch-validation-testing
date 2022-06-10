unsigned long long klee_change (unsigned long long x, unsigned long long y){return y;}
int main(int argc, char **argv) 
{ 
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
    while (1) {
      if ((int )temp == (int )vowels[j]) {
        syl ++;
        j = 5;
      } else {

      }
      if (j < 5) {

      } else {
        break;
      }
      j ++;
    }
    k ++;
  }
  printf("The number of syllables is %d.", syl);
  return (0);
}
}
