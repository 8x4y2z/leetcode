from typing import List

def div3(n):
    while(n & (~3)):
        res = 0
        while(n):
            res += n & 3        # add last two digits
            n >>= 2             # shift two bits to right
        n = res
    return (n == 0 or n == 3)

lookup = {r:str for r in range(15)}
for r in range(3,15,3):
    lookup[r] = lambda _:"Fizz"
for r in range(5,15,5):
    lookup[r] = lambda _:"Buzz"
lookup[0] = lambda _:"FizzBuzz"

class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        result = []
        for a in range(1,n+1):
            if (a%3 ==0 ) and (a%5==0):
                result.append("FizzBuzz")
            elif(a%3==0):
                result.append("Fizz")
            elif(a%5==0):
                result.append("Buzz")
            else:
                result.append(str(a))
        return result

    def fizzBuzzFast(self, n: int) -> List[str]:
        return [lookup[i%15](i) for i in range(1,n+1)]

def main():
    sol = Solution()
    print(sol.fizzBuzz(3))
    print(sol.fizzBuzzFast(3))
    print("-"*50)

    print(sol.fizzBuzz(5))
    print(sol.fizzBuzzFast(5))
    print("-"*50)

    print(sol.fizzBuzz(15))
    print(sol.fizzBuzzFast(15))
    print("-"*50)
if __name__ == '__main__':
    main()
