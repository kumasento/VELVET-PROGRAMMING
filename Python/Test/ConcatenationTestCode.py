
from time import time

RANGE = 42

def test_plus():
    t = time()
    s = 'lksdajflakjdsflku09uweoir'
    for x in range(RANGE):
        s += s[len(s)/2:]
    print 'duration:', time() - t

def test_join():
    t = time()
    s = 'lksdajflakjdsflku09uweoir'
    for x in range(RANGE):
        s = "".join((s, s[len(s)/2:]))
    print 'duration:', time() - t

test_join()
test_plus()
