from ap2024 import PyBubbleSort, PyCombSort, PyIntroSort, PySmoothSort


if __name__ == '__main__':
    t = PyCombSort()
    t.run(1_000_000, "rand")
    print(t)
    t.run(1_000_000, "srt")
    print(t)
    t.run(1_000_000, "rev")
    print(t)

    ttt = PyIntroSort()
    ttt.run(1_000_000, "rand")
    print(ttt)
    ttt.run(1_000_000, "sort")
    print(ttt)
    ttt.run(1_000_000, "rev")
    print(ttt)

    ttt = PySmoothSort()
    ttt.run(1_000_000, "rand")
    print(ttt)
    ttt.run(1_000_000, "sort")
    print(ttt)
    ttt.run(1_000_000, "rev")
    print(ttt)
