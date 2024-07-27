#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve_of_eratosthenes(int n) {
    vector<bool> is_prime(n + 1, true);

    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;

    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes = sieve_of_eratosthenes(n);

    for (int prime : primes) {
        cout << prime << endl;
    }

    return 0;
}