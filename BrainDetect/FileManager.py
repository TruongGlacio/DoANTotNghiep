from tkinter import filedialog
from tkinter import *

class FileManager:
    filename=""
    def FileBroswer(self):
        # Allow user to select a directory and store it in global var
        # called folder_path
        global filename  
        self.filename = filedialog.askdirectory()
        print(self.filename)
        return self.filename
    
    def __init__(self):
        print("FileManager class init")       