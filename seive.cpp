const ll N = 2e6 + 5;
vector<bool> prime(N + 1, true);
void seive()
{
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= N / i; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}
