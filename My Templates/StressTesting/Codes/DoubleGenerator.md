```
// Random Real Number Generator:

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline double gen_random(double l, double r) {
    return uniform_real_distribution<double>(l, r)(rng);
}
