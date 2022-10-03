/*
gfg link - https://practice.geeksforgeeks.org/problems/modified-numbers-and-queries0904/1
*/

unordered_set<int> sieveOfEratosthenes(int n)
{
    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (!isPrime[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            isPrime[j] = false;
    }
    unordered_set<int> primes;
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            primes.insert(i);
    return primes;
}
int sumOfAll(int l, int r)
{
    // code here
    int sum = 0;
    if (l == 1)
        sum += 1, l++;
    auto primes = sieveOfEratosthenes(r);
    for (int i = l; i <= r; i++)
    {
        int res = 0;
        if (primes.find(i) != primes.end())
            res += i;
        else
            for (auto it : primes)
                if (i % it == 0)
                    res += it;
        sum += res;
    }
    return sum;
}
