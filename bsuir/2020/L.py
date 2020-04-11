n = int(input())

q = int(input())

M = 1000000007
answer = n % M
s = list(str(n))

for i in range(q):
	op = input().split()
	if len(op) == 1:
		tmp = 0
		if len(s) > 0:
			tmp = int(s.pop())
		
		answer = ((((answer % M - tmp % M + M) + M) % M) * (700000005 % M)) % M
	else:
		answer *= 10
		answer += int(op[1])
		answer %= M
		s.append(op[1])
	print(answer)

