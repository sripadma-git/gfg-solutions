class Solution:
    def palQueries(self, s, queries):
        n = len(s)
        mod = 10**9 + 7
        base = 31

        # Precompute powers of base
        power = [1] * (n + 1)
        for i in range(1, n + 1):
            power[i] = (power[i - 1] * base) % mod

        # Forward hash
        hash_fwd = [0] * (n + 1)
        for i in range(n):
            hash_fwd[i + 1] = (hash_fwd[i] * base + ord(s[i]) - ord('a') + 1) % mod

        # Reverse hash
        hash_rev = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            hash_rev[n - i] = (hash_rev[n - i - 1] * base + ord(s[i]) - ord('a') + 1) % mod

        def get_hash(hash_arr, l, r):
            return (hash_arr[r + 1] - hash_arr[l] * power[r - l + 1] % mod + mod) % mod

        result = []
        for l, r in queries:
            len_sub = r - l + 1
            hash1 = get_hash(hash_fwd, l, r)
            rev_l = n - r - 1
            rev_r = n - l - 1
            hash2 = get_hash(hash_rev, rev_l, rev_r)
            result.append(1 if hash1 == hash2 else 0)
        return result
