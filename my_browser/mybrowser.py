import  sys
from PyQt4.QtCore    import  *
from PyQt4.QtGui     import  *
from PyQt4.QtWebKit  import  *

class MyBrowser(QWidget):

    def __init__(self, parent = None):
        super(MyBrowser, self).__init__(parent)
        self.createLayout()
        self.createConnection()

    def search(self):
        address = str(self.addressBar.text())
        if address:
            if address.find('://') == -1:
                address =  'http://' + address
            url = QUrl(address)
            self.webView.load(url)

    def createLayout(self):
        self.setWindowTitle("Drabbit's Browser")

        self.addressBar = QLineEdit();
        self.goButton = QPushButton('&GO')
        bl = QHBoxLayout()
        bl.addWidget(self.addressBar)
        bl.addWidget(self.goButton)

        self.webView = QWebView();

        layout = QVBoxLayout()
        layout.addLayout(bl)
        layout.addWidget(self.webView)

        self.setLayout(layout);

    def createConnection(self):
        self.connect(self.addressBar, SIGNAL('returnPressed()'), self.search)
        self.connect(self.addressBar, SIGNAL('returnPressed()'), self.addressBar, SLOT('selectAll()'))
        self.connect(self.goButton, SIGNAL('clicked()'), self.search)
        self.connect(self.goButton, SIGNAL('clicked()'), self.addressBar, SLOT('selectAll()'))

app = QApplication(sys.argv)

brower = MyBrowser()
brower.show()

sys.exit(app.exec_())
