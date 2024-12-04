```xml

const int MAX = 1000000;
vector<int> primes;

// Function to perform the Sieve of Eratosthenes
void sieve() {
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i*i<=MAX; i++) {
        if (isPrime[i]) {
            for (int j=i*i; j<=MAX; j+=i)
                isPrime[j] = false;
        }
    }
    for (int i=2; i<=MAX; i++) {
        if (isPrime[i])
            primes.push_back(i);
    }
}

// Function to perform prime factorization and count total prime factors
ll primeFactorization(ll n) {
    ll cnt = 0;
    for (int prime : primes) {
        if (prime * prime > n) {
            break;
        }
        while (n%prime==0) {
            cnt++;
            n /= prime;
        }
    }
    if (n>1) cnt++; // If n is a prime number greater than sqrt(n)
    return cnt;
}

//Call the Sieve function in main function

