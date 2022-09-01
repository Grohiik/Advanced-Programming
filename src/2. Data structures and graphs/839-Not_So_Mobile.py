# number of testcases
# wl dl wr dr, if 0 submobile on next line
# easiest with recursion thing


def mobile():
    balancedl = balancedr = True
    (wl, dl, wr, dr) = [int(x) for x in input().split(" ")]
    if wl == 0:
        (balancedl, wl) = mobile()
    if wr == 0:
        (balancedr, wr) = mobile()

    selfbalance = (wl * dl) == (wr * dr)
    weight = wl + wr
    return (balancedl and balancedr and selfbalance, weight)


for i in range(int(input())):
    input()
    if mobile()[0]:
        print("YES\n")
    else:
        print("NO\n")

# If n is number of mobiles then this is O(n)