#include <stdio.h>

main() {
	
	int num2, i;
	float num1, resto;
	
	printf("Informe um n�mero: ");
	scanf("%f", &num1);
	printf("Informe outro n�mero: ");
	scanf("%i", &num2);
	
	for (i = num2; i > 1; i--){
		resto = num1 / i;
		printf("%0.2f / %i = %0.2f\n", num1, i, resto);
		num1 = resto;
	}
}
