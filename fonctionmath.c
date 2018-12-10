#include <stdio.h>
int main (void) {
	double x,result, n2;
	char yes, ouinon='y';
	printf("Please enter a number wich one you want to f(x)=(2x + 3)(3x² + 2)\n");
	scanf("%lf", &x);
n2 = 3*x;
	result = ((2*x) + 3)*(((3*x)*n2) + 2);

	printf("f(%lf) = %lf\n But do you want the 'dérivée' of f(x)? [Yes or No]\n", x, result);
	puts("sure?\n");
	scanf("%c", &ouinon);

	yes = result*2;

	if(ouinon=='y'){ printf("The dérivée of f(x)=f'(x) is: %d", yes);
	} else { return 0; } 

	return 0;
}
