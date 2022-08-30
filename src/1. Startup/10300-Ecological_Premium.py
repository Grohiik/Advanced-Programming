# m²/animal
# times degree of eco-friendlyness
# times #of animals

### INPUT
# number of testcases, n < 20

#  0 < f < 20, int number of farmers in this testcase
# one line per farmer, m², #animals, eco-frendliness

### OUTPUT
# summed money for the farmers in each testcase


num_testcases = int(input())
for i in range(num_testcases):
    burden = 0
    num_farmers = int(input())
    for ii in range(num_farmers):
        square_meters, num_animals, eco_friendlyness = [
            int(x) for x in input().split(" ")
        ]
        burden += square_meters * eco_friendlyness
    print(burden)
