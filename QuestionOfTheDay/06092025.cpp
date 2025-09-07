//https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/?envType=daily-question&envId=2025-09-06
long long get_prefix_cost(long long n) {
    if (n <= 0) {
        return 0;
    }
    
    long long cost = 0;
    long long i = 1;
    long long base = 1;

    while (base <= n) {
        long long range_end = min((long long)n, base * 2 - 1);
        long long count = range_end - base + 1;
        cost += ((i + 1) / 2) * count;
        i++;
        base *= 2;
    }
    return cost;
}

long long minOperations(vector<vector<int>>& queries) {
    long long res = 0;
    for (auto& q : queries) {
        long long l = q[0], r = q[1];
        long long range_cost = get_prefix_cost(r) - get_prefix_cost(l - 1);
        res += (range_cost + 1) / 2;
    }
    return res;
}