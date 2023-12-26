import sys
import time

from subprocess import run


def check_ans(output_file1, output_file2):
    """
    该函数用于判断两个输入文件是否相同，这里简单比对全文相等，可根据需求修改
    output_file1, output_file2 分别为判断的两个文件的文件名
    函数返回布尔值
    """
    with open(output_file1) as f1, open(output_file2) as f2:
        lineIdx = 0
        while f1.readable() and f2.readable():
            output1 = f1.readline()
            output2 = f2.readline()
            if output1 != output2:
                return (False, lineIdx)
            lineIdx += 1
            if output1 == "" and output2 == "":
                return (True, 0)


if len(sys.argv) != 3:
    print("Usage: %s <program> <makedata>" % sys.argv[0])
    print(
        '    Example on Linux: python3 %s ./a.out "python3 makedata.py"' % sys.argv[0]
    )
    print(
        '    Example on Windows: python %s ./a.exe "python makedata.py"' % sys.argv[0]
    )
    exit(1)

cnt = 0
while cnt<100:
    cnt += 1
    print("Running Case #%d ... " % cnt, end="")

    run(sys.argv[2], stdout=open("input.txt", "w"), shell=True).check_returncode()

    ticks1 = time.perf_counter()
    # print(ticks1)
    run(
        sys.argv[1],
        stdin=open("input.txt"),
        stdout=open("output1.txt", "w"),
        timeout=30.0,
        shell=True,
    ).check_returncode()

    ticks2 = time.perf_counter()
    # print(ticks2)

    res = check_ans("output1.txt", "output.txt")

    if not res[0]:
        print("Wrong Answer, Different at line", res[1])
        break
    print("OK")
    print("Running Time Of Program:", ticks2 - ticks1)
