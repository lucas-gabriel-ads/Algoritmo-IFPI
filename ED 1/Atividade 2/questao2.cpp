#include <stdio.h>

main() {
	
	int num1, num2, a, b, resto;
	
	printf("Informe um n�mero: ");
	scanf("%i", &num1);
	printf("Informe outro n�mero: ");
	scanf("%i", &num2);
	
	do {
        resto = a % b;

        a = b;
        b = resto;
	
	} while (resto != 0);
	
	
	printf("O MMC de %i %i � %i", num1, num2, ((num1 * num2) / a));
}
