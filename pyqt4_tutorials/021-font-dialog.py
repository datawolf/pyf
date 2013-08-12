#!/usr/bin/env python

import sys
from PyQt4  import QtGui

class Example(QtGui.QWidget):
    
    def __init__(self):
        super(Example, self).__init__()

        self.initUI()

    def initUI(self):

        col = QtGui.QColor(0, 0, 0)

        vbox = QtGui.QVBoxLayout()


        btn = QtGui.QPushButton('Dialog', self)
        btn.move(20, 20)
        btn.clicked.connect(self.showDialog)
        btn.setSizePolicy(QtGui.QSizePolicy.Fixed,
                    QtGui.QSizePolicy.Fixed)

        vbox.addWidget(btn)

        self.lbl = QtGui.QLabel('Knowledge only matters', self)
        self.lbl.move(130, 20)


        vbox.addWidget(self. lbl)
        self.setLayout(vbox)

        self.setGeometry(300, 300, 250, 180)
        self.setWindowTitle('Font Dialog')
        self.show()

    def showDialog(self):

        font, ok = QtGui.QFontDialog.getFont()

        if ok:
            self.lbl.setFont(font)

def main():

    app = QtGui.QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
