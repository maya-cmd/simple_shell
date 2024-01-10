#include "shell.h"

/**
 * betty_example - A function that demonstrates Betty-compliant code.
 *
 * Description: This function takes two integers as inpu
 * and returns their sum.
 *
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The sum of the two integers.
 */
int betty_example(int a, int b)
{
	int sum;

	/* Check if either integer is zero */
	if (a == 0 || b == 0)

	{
		return (0);
	}

	/* Calculate the sum of the two integers */
	sum = a + b;

	return (sum);
}
/**
 * main - The main function to test the betty_example function.
 *
 * Return: Always 0.
 */

int main(void)

{
	int result;

	/* Call the betty_example function with two integers */
	result = betty_example(5, 10);

	/* Print the result */
	printf("The sum is: %d\n", result);

	return (0);

}
