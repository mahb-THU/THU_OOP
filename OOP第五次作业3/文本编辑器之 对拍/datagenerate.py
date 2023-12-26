from random import randint
import sys
N = 100
DATA = [""]
cursor0 = [0, 0]
cursor1 = [0, 0]
isSelect = False
clipboard = []
idx = 0

cin = open("input.txt", "w")
cout = open("output.txt", "w")

cin.write("{}\n".format(N * 2))
for _ in range(N):
    op = randint(0, 9)
    if len(DATA) == 1 and len(DATA[0]) == 0:
        op = 4
    if op <= 1:
        X = randint(0, len(DATA) - 1)
        Y = randint(0, len(DATA[X]))
        cin.write("MOVE {} {}".format(X, Y) + "\n")
        print("MOVE {} {}".format(X, Y))
        isSelect = False
        cursor0 = [X, Y]
    elif op <= 3:
        X1 = randint(0, len(DATA) - 1)
        X2 = randint(0, len(DATA) - 1)
        if X1 > X2:
            X1, X2 = X2, X1
        Y1 = randint(0, len(DATA[X1]))
        Y2 = randint(0, len(DATA[X2]))
        if X1 == X2 and Y1 > Y2:
            Y1, Y2 = Y2, Y1
        cin.write("SELECT {} {} {} {}".format(X1, Y1, X2, Y2) + "\n")
        print("SELECT {} {} {} {}".format(X1, Y1, X2, Y2))
        isSelect = True
        cursor0 = [X1, Y1]
        cursor1 = [X2, Y2]

    elif op <= 5:
        lenStr = randint(1, 10)
        strToWrite = ""
        for _ in range(lenStr):
            strToWrite += chr(randint(0, 25) + ord("a"))
        if isSelect:
            DATA[cursor0[0]] = (
                DATA[cursor0[0]][: cursor0[1]] + DATA[cursor1[0]][cursor1[1] :]
            )
            for i in range(cursor1[0] - cursor0[0]):
                DATA.pop(cursor0[0] + 1)
            isSelect = False
        DATA[cursor0[0]] = (
            DATA[cursor0[0]][: cursor0[1]] + strToWrite + DATA[cursor0[0]][cursor0[1] :]
        )
        cin.write("WRITE {}".format(strToWrite) + "\n")
        print("WRITE {}".format(strToWrite))
        cursor0[1] += lenStr

    elif op <= 6:
        cin.write("NEWLINE\n")
        print("NEWLINE")
        if isSelect:
            DATA[cursor0[0]] = (
                DATA[cursor0[0]][: cursor0[1]] + DATA[cursor1[0]][cursor1[1] :]
            )
            for i in range(cursor1[0] - cursor0[0]):
                DATA.pop(cursor0[0] + 1)
            isSelect = False
        str0 = DATA[cursor0[0]][: cursor0[1]]
        str1 = DATA[cursor0[0]][cursor0[1] :]
        DATA[cursor0[0]] = str0
        DATA.insert(cursor0[0] + 1, str1)
        cursor0 = [cursor0[0] + 1, 0]
    elif op <= 7:
        cin.write("DELETE\n")
        print("DELETE")
        if isSelect:
            DATA[cursor0[0]] = (
                DATA[cursor0[0]][: cursor0[1]] + DATA[cursor1[0]][cursor1[1] :]
            )
            for i in range(cursor1[0] - cursor0[0]):
                DATA.pop(cursor0[0] + 1)
            isSelect = False
        else:
            if cursor0[1] != len(DATA[cursor0[0]]):
                DATA[cursor0[0]] = (
                    DATA[cursor0[0]][: cursor0[1]] + DATA[cursor0[0]][cursor0[1] + 1 :]
                )
            else:
                if cursor0[0] != len(DATA) - 1:
                    DATA[cursor0[0]] += DATA[cursor0[0] + 1]
                    DATA.pop(cursor0[0] + 1)
    elif op <= 8:
        cin.write("COPY\n")
        print("COPY")
        if isSelect:
            clipboard = []
            for i in range(cursor0[0], cursor1[0] + 1):
                if i == cursor0[0] and i == cursor1[0]:
                    clipboard.append(DATA[i][cursor0[1] : cursor1[1]])
                elif i == cursor0[0]:
                    clipboard.append(DATA[i][cursor0[1] :])
                elif i == cursor1[0]:
                    clipboard.append(DATA[i][: cursor1[1]])
                else:
                    clipboard.append(DATA[i])
    elif op <= 9:
        cin.write("PASTE\n")
        print("PASTE")
        if isSelect:
            DATA[cursor0[0]] = (
                DATA[cursor0[0]][: cursor0[1]] + DATA[cursor1[0]][cursor1[1] :]
            )
            for i in range(cursor1[0] - cursor0[0]):
                DATA.pop(cursor0[0] + 1)
            isSelect = False
        if len(clipboard) > 0:
            lastLine = DATA[cursor0[0]][cursor0[1] :]
            DATA[cursor0[0]] = DATA[cursor0[0]][: cursor0[1]] + clipboard[0]
            for i in range(1, len(clipboard)):
                DATA.insert(cursor0[0] + i, clipboard[i])
            DATA[cursor0[0] + len(clipboard) - 1] += lastLine
            if len(clipboard) > 1:
                cursor0 = [cursor0[0] + len(clipboard) - 1, len(clipboard[-1])]
            else:
                cursor0[1] += len(clipboard[0])

    cin.write("SCREEN\n")
    print("SCREEN")
    idx += 1
    cout.write("#{}:\n".format(idx))

    for i in range(cursor0[0]):
        cout.write(DATA[i] + "\n")
    if isSelect:
        if cursor0[0] == cursor1[0]:
            cout.write(
                DATA[cursor0[0]][: cursor0[1]]
                + "*"
                + DATA[cursor0[0]][cursor0[1] : cursor1[1]]
                + "*"
                + DATA[cursor0[0]][cursor1[1] :]
                + "\n"
            )
        else:
            cout.write(
                DATA[cursor0[0]][: cursor0[1]]
                + "*"
                + DATA[cursor0[0]][cursor0[1] :]
                + "\n"
            )
            for i in range(cursor0[0] + 1, cursor1[0]):
                cout.write(DATA[i] + "\n")
            cout.write(
                DATA[cursor1[0]][: cursor1[1]]
                + "*"
                + DATA[cursor1[0]][cursor1[1] :]
                + "\n"
            )
        for i in range(cursor1[0] + 1, len(DATA)):
            cout.write(DATA[i] + "\n")
    else:
        cout.write(
            DATA[cursor0[0]][: cursor0[1]] + "*" + DATA[cursor0[0]][cursor0[1] :] + "\n"
        )
        for i in range(cursor0[0] + 1, len(DATA)):
            cout.write(DATA[i] + "\n")
sys.exit(0)