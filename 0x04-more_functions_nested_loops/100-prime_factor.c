#include <stdio.h>
#include <math.h>

long largest_prime_factor(long n)
{
    long largest = -1;
    long i;

    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }

    for (i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }

    if (n > 2) {
        largest = n;
    }

    return largest;
}

int main(void)
{
    long number = 612852475143;
    long largest_prime = largest_prime_factor(number);

    printf("%ld\n", largest_prime);

    return 0;
}
