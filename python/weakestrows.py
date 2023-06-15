from typing import List

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        """
        """
        return sorted(range(len(mat)),key=mat.__getitem__)[:k]
def main():
    mat = [[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]
    k =3
    res = Solution().kWeakestRows(mat,k)
    print(res)

    mat = [[1,0,0,0],[1,1,1,1],[1,0,0,0],[1,0,0,0]]
    k =2
    res = Solution().kWeakestRows(mat,k)
    print(res)


if __name__ == '__main__':
    main()
