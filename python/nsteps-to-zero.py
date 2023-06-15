
def _numberOfSteps(num,n):
    if not num:
        return n

    if not num%2:
        return _numberOfSteps(num/2,n+1)
    else:
        return _numberOfSteps(num-1,n+1)

class Solution:
    def numberOfSteps(self, num: int) -> int:
        """
        """
        return _numberOfSteps(num,0)

    def numberOfStepsFast(self,num:int) -> int:
        steps:int = 0
        while num:
            steps += 1
            if not num % 2:
                num /= 2
            else:
                num -= 1

        return steps


def main():
    n=14
    print(f"Nsteps to reduce to zero is {Solution().numberOfSteps(n)}")
    print(f"Nsteps to reduce to zero is {Solution().numberOfStepsFast(n)}")

    n=8
    print(f"Nsteps to reduce to zero is {Solution().numberOfSteps(n)}")
    print(f"Nsteps to reduce to zero is {Solution().numberOfStepsFast(n)}")

    n=123
    print(f"Nsteps to reduce to zero is {Solution().numberOfSteps(n)}")
    print(f"Nsteps to reduce to zero is {Solution().numberOfStepsFast(n)}")
if __name__ == '__main__':
    main()
