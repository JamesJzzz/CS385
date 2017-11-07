f = open('input.txt').read().split()
num = 10

total = sum(map(int, f))
print "Full sum:", total
print "First",num,"digits:", str(total)[:num]