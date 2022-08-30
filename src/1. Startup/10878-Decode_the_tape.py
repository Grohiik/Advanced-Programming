# I googled it gave basically awnser :P
# Is just Ascii in binary (should have guessed), o is 1 space is 0

input()  # first line is just fluff
output = ""
current_line = input()[2:-1]  # remove non information carrying part of line
while current_line != "___________"[2:-1]:
    num = ""
    for i in current_line:
        if i == ".":
            continue
        elif i == "o":
            num += "1"
        else:
            num += "0"
    output += chr(int(num, 2))
    current_line = input()[2:-1]
print(output, end="")
