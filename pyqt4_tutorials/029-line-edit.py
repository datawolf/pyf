#!/usr/bin/env python

import sys
from PyQt4  import QtGui
from PyQt4  import QtCore

class Example(QtGui.QWidget):
    
    def __init__(self):
        super(Example, self).__init__()

        self.initUI()

    def initUI(self):

        self.lbl = QtGui.QLabel(self)
        qle = QtGui.QLineEdit(self)

        qle.move(60, 100)
        self.lbl.move(60, 40)

        qle.textChanged[str].connect(self.onChanged)

        self.setGeometry(300, 300, 280, 170)
        self.setWindowTitle('QtGui.QLineEdit')
        self.show()

    def onChanged(self, text):

        self.lbl.setText(text)
        self.lbl.adjustSize()


def main():

    app = QtGui.QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
