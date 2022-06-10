unsigned long long klee_change (unsigned long long x, unsigned long long y){return y;}
/**/

#include <stdio.h>
#include <math.h>


int main(int argc, char **argv) {
	int n, r, nn;
	
	printf("\nEnter an integer > ");
klee_make_symbolic(&n, sizeof(n), "n");
	if ( n==0)
		printf("\n0");
	while( n ){
		if ( n < 0){
			n= -n;
				while (n){
					r = n % 10;
					nn= n / 10;
					if ( n < 10 ){
						printf("\n-%d", r);
					}
					else if ( n >= 10){
						printf("\n%d", r);
					}
					n= nn;
				}
		}
		else {	
		r = n % 10;
		nn= n / 10;
		n= nn;
		printf("\n%d", r);
		}
	}
	
	printf("\nThat's all, have a nice day!\n");
	
	return 0;
	
}
