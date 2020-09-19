from BrainDetectFunction import BrainDetectFunction
from BraTS2018 import BraTS2018 
from mainwindow import MainScreen
import sys 
from PyQt5.QtWidgets import *
from PyQt5.QtCore import QCoreApplication

def Main():
   # global mMainScreen
    app = QApplication(sys.argv) # 
    
    mMainScreen = MainScreen()
    mMainScreen.show()			
    #mBraTS2018 = BraTS2018()    
    mBrainDetectFunction=BrainDetectFunction()
    
    mMainScreen.ui.pushButton_segmentation.clicked.connect(mBrainDetectFunction.BrainDetectFunction)      #  
    
    
    sys.exit(app.exec_())
   
    #mBrainDetectFunction.BrainDetectFunction()
    #mBraTS2018.BraTS2018Function()
    
if __name__ == "__main__":    
    Main()
