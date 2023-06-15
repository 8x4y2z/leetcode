from itertools import combinations
from pprint import pprint

def uniquePairs(arr,n,l,m=set(),seen=None):
    if n == 1:
        # seen += (tuple(sorted(arr)),)
        ft = seen + (tuple(sorted(arr)),)
        m.add(tuple(sorted(ft,key=lambda x : x[0])))

    else:
        for tup in combinations(arr,2):
            rem = list(set(arr) - set(tup))
            if l == n:
                seen = (tuple(sorted(tup)),)
                uniquePairs(rem,n-1,l,m,seen)
            else:
                # seen += (tuple(sorted(tup)),)
                uniquePairs(rem,n-1,l,m,seen + (tuple(sorted(tup)),))


def uniquePairsSlow(arr):
    final_ = []
    twosA = combinations(arr,2)
    allCombs = combinations(twosA,len(arr)//2)
    for arr_ in allCombs:
        isVal = 1
        tmpA = [a for tup in arr_ for a in tup]
        mask = 0xFFFF
        for a in tmpA:
            if mask & (1 << a):
                mask ^= (1<<a)
            else:
                isVal = 0
        if isVal:
            # print(1)
            final_.append(arr_)

    return final_










def maxVal(nums,inds,memo):
    if (tuple(nums[:2]),inds[0]) in memo:
        result = memo[nums]



def maxScore(nums):
    inds = list(range(len(nums)))
    memo = set()
    uniquePairs(inds,len(nums)//2,len(nums)//2,memo)

    print(len(memo))
    pprint(memo)

    r = uniquePairsSlow(inds)
    print(len(r))
    pprint(r)

    # return maxVal(nums,inds,memo)



if __name__ == '__main__':
    # nums = [3,4,6,8]
    # print(maxScore(nums))

    nums2=[1,2,3,4,5,6]
    print(maxScore(nums2))
    print("*"*50)

    # nums3=[1,2]
    # print(maxScore(nums3))
    # print("*"*50)

    # nums4=[171651,546244,880754,412358]
    # print(maxScore(nums4))
    # print("*"*50)

    nums5=[370435,481435,953948,282360,691237,574616,638525,764832]
    print(maxScore(nums5))
    print("*"*50)

    nums6=[995853,58850,504472,912272,382454,597688,581332,209547]
    print(maxScore(nums6))
    print("*"*50)

    nums7=[679690,746157,308799,476790,736757,337644,520612,496785,119738,24783]
    print(maxScore(nums7))
    print("*"*50)
