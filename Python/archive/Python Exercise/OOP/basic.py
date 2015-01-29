#! /usr/local/bin/python

class BasicClass:
    def setx(self, x):
        self.x = x
    def bar(self):
        print self.x

if __name__ == '__main__':
    bc = BasicClass()
    bc.setx(5)
    bc.bar()
    print vars(bc)
    print vars(BasicClass)
