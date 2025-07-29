class Solution:
    def primeFactors(self, n):
        factors = []
        
        # First divide out the 2s
        while n % 2 == 0:
            factors.append(2)
            n //= 2

        # Try all odd numbers starting from 3
        i = 3
        while i * i <= n:
            while n % i == 0:
                factors.append(i)
                n //= i
            i += 2

        # If n is a prime number greater than 2
        if n > 2:
            factors.append(n)

        return factors
