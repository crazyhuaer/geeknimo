# -*- coding: utf-8 -*-
#该程序适合Python 2.x版本。
 
import sys
from PyQt4.QtGui import *
#差异1：从转换后的代码里面导入窗体
from ui_pyqt_example import Ui_TestWidget
 
#差异2：需要继承Ui_TestWidget
class TestWidget(QWidget, Ui_TestWidget):
    def __init__(self):
        QWidget.__init__(self)
        #差异3：原来长篇累牍的创建控件的代码不再需要了，取而代之的是一行简单的setupUi()
        self.setupUi(self)
        self.helloButton.clicked.connect(self.sayHello)
 
    def sayHello(self):
        yourName, okay=QInputDialog.getText(self, self.trUtf8("请问你的名字是?"), self.trUtf8(b"名字"))
        if not okay or yourName==u"": #用户没有输入名字，而是点了取消
            self.outputArea.append(self.trUtf8("你好，陌生人！"))
        else:
            self.outputArea.append(self.trUtf8("你好，<b>%1</b>。").arg(yourName))
 
app=QApplication(sys.argv)
testWidget=TestWidget()
testWidget.show()
sys.exit(app.exec_())