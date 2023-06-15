
def minMax(arr,start,end):
    if start == end:
        return arr[start]
    elif (start+1 == end):
        return arr[end] if arr[start] <= arr[end] else arr[start]
    else:
        mid = start + (end-start)//2
        left = minMax(arr,start,mid)
        right = minMax(arr,mid+1,end)
        return left if left>=right else right


class Solution:
    def maximumWealth(self,accountssA):
        accountssA = [sum(a) for a in accountssA]
        return minMax(accountssA,0,len(accountssA) -1)

    def maximumWealthN(self,accountssA):
        accountssA = [sum(a) for a in accountssA]
        a =0
        for aa in accountssA:
            if aa>a:
                a = aa

        return a


def main():
    accountssA = [[1,2,3],[3,2,1]]
    res = Solution().maximumWealth(accountssA)
    print(f"Max value is {res}")

    res = Solution().maximumWealthN(accountssA)
    print(f"Max value is {res}")
if __name__ == '__main__':
    main()
