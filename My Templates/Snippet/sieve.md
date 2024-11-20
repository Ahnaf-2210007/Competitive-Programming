```
vi sieve(int n) {
    vector<bool> is_prime(n+1,true); // Create a boolean array
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not primes
    
    for(int p=2; p*p<=n; p++) {
        if(is_prime[p]) { // If p is a prime
            for (int multiple = p*p; multiple<=n; multiple += p) {
                is_prime[multiple] = false; // Mark multiples of p
            }
        }
    }
    
    // Extract all prime numbers
    vi primes;
    for(int i=2; i<=n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}
