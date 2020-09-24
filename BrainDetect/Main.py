from BrainDetectFunction import BrainDetectFunction
from BraTS2018 import BraTS2018 
from mainwindow import MainScreen
import sys 
from PyQt5.QtWidgets import *
from PyQt5.QtCore import QCoreApplication
from FileManager import FileManager
from tkinter import *
from tkinter import filedialog

import os
class Main:
    def Main(self):
       # global mMainScreen
        app = QApplication(sys.argv) # 
        global mFileManager
        global mMainScreen
        global mBrainDetectFunction
        #folder_path = StringVar()
        mMainScreen = MainScreen()
        mFileManager=FileManager()
        mMainScreen.show()			
        #mBraTS2018 = BraTS2018()
        mMainScreen.ui.label_NotifyStatus.setText( "While training data, please wait until finished")  
        mBrainDetectFunction=BrainDetectFunction()
        #mBrainDetectFunction.BrainDetectFunction()
        mMainScreen.ui.label_NotifyStatus.setText("The training process has been completed, choose a photo to segmentation")        
        mMainScreen.ui.pushButton_OpenFileBroswer.clicked.connect(self.FileBroswer)          
        mMainScreen.ui.pushButton_segmentation.clicked.connect(self.DetectObject)      #  
        
       # print(fileName)
        #fileName=mFileManager.fileName
        sys.exit(app.exec_())
       
        #mBraTS2018.BraTS2018Function()

    def FileBroswer(self):
        # Allow user to select a directory and store it in global var
        # called folder_path
        global filename          
        
        currdir=os.getcwd()
        root =Tk()        
        filename = filedialog.askopenfilename(parent=root, initialdir=currdir, title='Please select a directory')
        #self.lineEdit_FolderPath.setText(_translate("MainWindow", "Type image Path in here"))       
        mMainScreen.ui.lineEdit_FolderPath.setText(filename)
        root.destroy()
        print(filename)
        return filename    
    def DetectObject(self):
        #if filename:
        filename= mMainScreen.ui.lineEdit_FolderPath.text()  
        if filename:
            mBrainDetectFunction.DetectSpecialImage(filename)    
if __name__ == "__main__":    
    main=Main()
    main.Main()
