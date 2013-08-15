#!/usr/bin/env python

import sys
import random
from PyQt4  import QtCore, QtGui


class   Tetris(QtGui.QMainWindow):
    def __init__(self):
        QtGui.QMainWindow.__init__(self)

        self.setGeometry(300, 300, 180, 380)
        self.setWindowTitle('Tetris')
        self.tetrisboard = Board(self)

        self.setCentralWidget(self.tetrisboard)

        self.statusbar = self.statusBar()
        self.connect(self.tetrisboard, QtCore.SIGNAL("messageToStatusbar(QString)"),
                    self.statusbar, QtCore.SLOT("showMessage(QString)"))

        self.tetrisboard.start()
        self.center()

    def center(self):
        screen = QtGui.QDesktopWidget().screenGeometry()
        size = self.geometry()
        self.move((screen.width()-size.width())/2,
                    (screen.height()-size.height())/2)


class   Board(QtGui.QFrame):
    BoardWidth = 10
    BoardHeight = 22
    Speed = 300

    def __init__(self, parent):
        QtGui.QFrame.__init__(self, parent)

        self.timer = QtCore.QBasicTimer()
        self.isWaitingAfterLine = False
        self.curPiece = Shape()
        self.nextPiece = Shape()
        self.curX = 0
        self.curY = 0
        self.numLinesRemoved = 0
        self.board = []

        self.setFocusPolicy(QtCore.Qt.StrongFocus)
        self.isStarted = False
        self.isPaused = False
        self.clearBoard()
        self.nextPiece.setRandomShape()



app = QtGui.QApplication(sys.argv)
tetris = Tetris()
tetris.show()
sys.exit(app.exec_())


