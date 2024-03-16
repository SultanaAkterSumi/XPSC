typedef long long ll;
typedef vector<ll> vl;
vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    vl ans;
    ll neg = N, i, j;
    for (i = 0; i < N; i++)
    {
        if (A[i] < 0)
        {
            neg = i;
            break;
        }
    }
    ll t1 = 0;
    for (i = K - 1; i < N; i++, t1++)
    {
        if (neg >= t1 && neg <= i)
            ans.push_back(A[neg]);
        else if (neg > i)
            ans.push_back(0);
        else
        {
            for (j = neg + 1; j < N; j++)
            {
                if (A[j] < 0)
                {
                    neg = j;
                    break;
                }
            }
            if (j == N)
                neg = N;
            if (neg >= t1 && neg <= i)
                ans.push_back(A[neg]);
            else if (neg > i)
                ans.push_back(0);
        }
    }
    return ans;
}