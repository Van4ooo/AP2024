from ap2024 import PyBubbleSort, PyCombSort, PyIntroSort


if __name__ == '__main__':
    t = PyCombSort()
    t.run(10_000_000, "rand")
    print(t)
    t.run(10_000_000, "rev")
    print(t)
    t.run(10_000_000, "sort")
    print(t)

    tt = PyIntroSort()
    tt.run(10_000_000, "rand")
    print(tt)
    tt.run(10_000_000, "rev")
    print(tt)
    tt.run(10_000_000, "sort")
    print(tt)
