import json

out = "out.txt"
my_out = "my_out.txt"

def readF(path):
    with open(path,"r") as s:
        l = json.loads(s.read())
    return l

def convertToSet(l):
    l = [tuple(sorted(a)) for a in l]
    return set(l)

def main():
    l = readF(out)
    ll = readF(my_out)

    l = convertToSet(l)
    ll = convertToSet(ll)

    diff = tuple((l -ll))
    return diff
