#!/usr/bin/env python

import sys
from PyQt4  import QtGui

class Example(QtGui.QMainWindow):
    
    def __init__(self):
        super(Example, self).__init__()

        self.initUI()

    def initUI(self):
        
        lbl1 = QtGui.QLabel('hello', self)
        lbl1.move(15, 10)

        lbl2 = QtGui.QLabel('world', self)
        lbl2.move(35, 40)

        lbl3 = QtGui.QLabel('for programmers', self)
        lbl3.move(55, 70)

        self.setGeometry(300, 300, 300, 200)
        self.setWindowTitle('Absolute')
        self.show()


def main():

    app = QtGui.QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
