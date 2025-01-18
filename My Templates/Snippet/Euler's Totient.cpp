const int MAX = 5000000;

vector<ull> phi(MAX + 1);

void computeTotient() {
    for (int i = 0; i <= MAX; i++) {
        phi[i] = i;  // Initialize phi[i] to i
    }

    for (int i = 2; i <= MAX; i++) {
        if (phi[i] == i) {  // i is prime
            for (int j = i; j <= MAX; j += i) {
                phi[j] *= (i - 1);
                phi[j] /= i;
            }
        }
    }
}

