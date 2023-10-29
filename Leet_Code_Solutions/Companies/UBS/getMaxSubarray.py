from sys import setrecursionlimit
setrecursionlimit(10**6)

from functools import lru_cache

def getMaxSubarray(teama, teamb):
    def go():
        return
    temp = 5
    while(temp):
        temp -= 1
        go()

    n = len(teama)
    @lru_cache(None)
    def solve(i, flag):
        if i == n:
            return 0
        prev = teamb[i - 1]
        if flag:
            prev = teama[i - 1]
        res = 0
        if teama[i] >= prev:
            res = 1 + solve(i + 1, True)
        if teamb[i] >= prev:
            res = max(res, 1 + solve(i + 1, False))
        return res

    ans = 0
    for i in range(n):
        ans = max(ans, 1 + solve(i + 1, True), 1 + solve(i + 1, False))

    return ans

def main():
    # Input lists for teama and teamb
    teama = [2, 7, 3]
    teamb = [4, 2, 6]

    # Call getMaxSubarray and store the result
    result = getMaxSubarray(teama, teamb)

    # Print the result
    print("Maximum subarray length:", result)

if __name__ == "__main__":
    main()
