"""
/* Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * Return the answer in any order.
 * */
"""

NUM_MAP = {
    2:"abc",
    3:"def",
    4:"ghi",
    5:"jkl",
    6:"mno",
    7:"pqrs",
    8:"tuv",
    9:"wxyz"
}

def lettComb(string):
    nos = []
    res = []
    pos = []
    lens = []

    points = 0
    n = 0
    prd = 1
    for ii,s in enumerate(string):
        i = int(s)
        nos.append(NUM_MAP[i])
        n += 1
        pos.append(0)
        lens.append(len(NUM_MAP[i]))
        prd *= lens[ii]

    print(f"Nos are --{nos}")
    for _ in range(prd):
        res.append([-1]*n)

    def innerComb(nn,ind=0):
        """
        @param: nn is used to iterate over the numbers
        @param: ind is used to track which of the inner array indexing into
        @param: pos is used to track position from which to iterate
        """
        nonlocal points
        # nonlocal pos

        # if points == 3**n:
            # return              # we're done
        ind += 1
        # print(f"Points={points}--ind={ind}--pos={pos}")
        # print("-"*30)

        for i in range(lens[ind - 1]):
            if (ind) % n ==0: # Time to add
                pos[ind - 1] = i
                loc1 = points // 3
                loc2 = points % 3
                for ii in range(n):
                    # print(f"\t\tloc1={loc1}--loc2={loc2}--ii={ii}")
                    res[3*loc1+loc2 ][ii] = nos[ii][pos[ii]]
                    # print(f"\t\tResult is {res}")
                points += 1
            else:
                pos[ind - 1] = i
                innerComb(nn,ind)




    innerComb(n)
    print("----------------xxxxxxxxxx--------------------------")
    return ["".join(aa) for aa in res]

def iterletComb(n=3):
    nos = []
    res = []
    points = []

    for i in range(n):
        nos.append(list(range(3*i,3*i+3)))
        points.append(0)

    for i in range(3**n):
        res.append([-1,-1,-1])

    points = 0
    for ii in range(3):
        for jj in range(3):
            for kk in range(3):
                loc1 =  points // 3
                loc2 = points % 3
                res[3*loc1+loc2 ][0] = nos[0][ii]
                res[3*loc1+loc2][1] = nos[1][jj]
                res[3*loc1+loc2][2] = nos[2][kk]
                points += 1


    return res



if __name__ == '__main__':

    res = iterletComb()
    res = lettComb("23")
    print(res,len(res),sep='\n')
    print("*"*50)

    res = lettComb("27")
    print(res,len(res),sep='\n')
    print("*"*50)

    res = lettComb("2")
    print(res,len(res),sep='\n')
    print("*"*50)

    res = lettComb("2476")
    print(res,len(res),sep='\n')
    print("*"*50)
