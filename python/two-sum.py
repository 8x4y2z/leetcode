from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        """
        d = {}
        for i,v in enumerate(nums):
            if v in d:
                d[v].append(i)
            else:
                d[v] = [i]

        for v in d:
            if target-v in d:
                if v == target-v:
                    if len(d[v])>1:
                        return d[v]
                else:
                    return [d[v][0], d[target-v][0]]
        return []
    def twoSumFast(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i in range(len(nums)):
            if target - nums[i] in d:
                return [i,d[target-nums[i]]]
            d[nums[i]] = i
        return []
def main():
    """
    """
    nums = [2,7,11,15]
    tar = 9
    print(f"Indices are {Solution().twoSum(nums,tar)} ")
    print(f"Indices are {Solution().twoSumFast(nums,tar)} ")

    nums = [3,2,4]
    tar = 6
    print(f"Indices are {Solution().twoSum(nums,tar)} ")
    print(f"Indices are {Solution().twoSumFast(nums,tar)} ")

    nums = [3,3]
    tar = 6
    print(f"Indices are {Solution().twoSum(nums,tar)} ")
    print(f"Indices are {Solution().twoSumFast(nums,tar)} ")

if __name__ == '__main__':
    main()
