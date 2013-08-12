#!/usr/bin/env python

import sys
from PyQt4  import QtGui
from PyQt4  import QtCore

class Communicate(QtCore.QObject):

    closeApp = QtCore.pyqtSignal()


class Example(QtGui.QMainWindow):
    
    def __init__(self):
        super(Example, self).__init__()

        self.initUI()

    def initUI(self):

        self.c = Communicate()
        self.c.closeApp.connect(self.close)

        self.setGeometry(300, 300, 300, 150)
        self.setWindowTitle('Event Sender')
        self.show()

    def mousePressEvent(self, event):

        self.c.closeApp.emit()

def main():

    app = QtGui.QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
