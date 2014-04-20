#include <stdio.h>

int main(){
	char *p = 
		"int main(){ \ 
		char *p = %c%s%c;\
		(void) printf(p, 34, p, 34, 10);} %c";
	
	/* 
	 * int main(){ : easy to understand
	 * char *p =: easy to understand
	 * %c%s%c; This will match the "string"
	 * %c will be the "
	 * and %s will be this "string" itself
	 * so the printf needs "p" as a parameter;
	 * and the last %c is " also
	 *
	 * The hardest part is: we need to let a pattern string to print itself
	 * that is:
	 *	printf(p, p)
	 * and printf will translate these two p differently.
	 */
	
	(void) printf(p, 34, p, 34, 10);
}
