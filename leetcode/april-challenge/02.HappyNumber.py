class Solution:
    def isHappy(self, n: int) -> bool:
        d = {n}
        while True:
            d.add(n)
            tmp = 0
            for i in map(int, list(str(n))):
                tmp += i ** 2
            n = tmp

            if (n == 1):
                return True

            if n in d:
                return False
