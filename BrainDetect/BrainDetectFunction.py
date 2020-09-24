import numpy as np 
import pandas as pd 
from plotly.offline import init_notebook_mode, iplot
import os
from os import listdir
import plotly.graph_objs as go
import tensorflow as tf
from tensorflow.keras.preprocessing.image import ImageDataGenerator
import cv2
'exec(%matplotlib inline)'
#%matplotlib inline
import matplotlib.pyplot as plt
import imutils    
import itertools
from sklearn.metrics import accuracy_score, confusion_matrix
from tensorflow.keras.models import Model,load_model
from tensorflow.keras.layers import Conv2D,Input,ZeroPadding2D,BatchNormalization,Flatten,Activation,Dense,MaxPooling2D
from sklearn.model_selection import train_test_split
from sklearn.utils import shuffle #shuffling the data improves the model
from IPython.display import display
from sklearn.preprocessing import LabelEncoder
from tensorflow.keras import backend as K


class BrainDetectFunction:
    def CreatFolderPaths(self):
        print("Function CreatFolderPaths");
        global augmented_yes;
        global augmented_no;
        global image_dir
        global augmented_data_path;
        global outPutImageDirYes;
        global outPutImageDirNo; 
        global IMG_SIZE;
        global IMAGE_SIZE_FOR_BUILDMODEL;
        global EXAMPLE_IMAGENAME;
        global timerForShowImage
        
        #os.environ['TF_FORCE_GPU_ALLOW_GROWTH'] = 'true'        
        image_dir="data/input/brain-mri-images-for-brain-tumor-detection/"
        augmented_data_path="";
        outPutImageDir= "data/output/kaggle/working/augmented-images/"
        outPutImageDirYes= outPutImageDir+ "yes"
        outPutImageDirNo=outPutImageDir+ "no"
        
        augmented_data_path= outPutImageDir;
        
        augmented_yes =augmented_data_path+'yes'
        augmented_no = augmented_data_path+'no'
        IMG_SIZE = (224,224);  
        IMAGE_SIZE_FOR_BUILDMODEL=180
        timerForShowImage=3
        EXAMPLE_IMAGENAME='/brain_tumor_dataset/yes/Y1.jpg'
        
        if not os.path.isdir(outPutImageDir):
            os.makedirs(outPutImageDir)
        if not os.path.isdir(outPutImageDirYes):
            os.makedirs(outPutImageDirYes)
        if not os.path.isdir(outPutImageDirNo):
            os.makedirs(outPutImageDirNo)
            
            
    def augment_data(self,file_dir, n_generated_samples, save_to_dir):
        print("Function augment_data");
        
        data_gen = ImageDataGenerator(rotation_range=10, 
                                      width_shift_range=0.1, 
                                      height_shift_range=0.1, 
                                      shear_range=0.1, 
                                      brightness_range=(0.3, 1.0),
                                      horizontal_flip=True, 
                                      vertical_flip=True, 
                                      fill_mode='nearest'
                                     )
    
        for filename in listdir(file_dir):
            image = cv2.imread(file_dir + '/' + filename)
            # reshape the image
            image = image.reshape((1,)+image.shape)
            save_prefix = 'aug_' + filename[:-4]
            i=0
            for batch in data_gen.flow(x=image, batch_size=1, save_to_dir=save_to_dir,save_prefix=save_prefix, save_format='jpg'):
                    i += 1
                    if i > n_generated_samples:
                        break
    def LoadAgumentData(self,):
        print("Function LoadAgumentData");
        dir = os.listdir(outPutImageDirYes) 
        
        if len(dir) == 0: 
        
            # augment data for the examples with label equal to 'yes' representing tumurous examples
            self.augment_data(file_dir=image_dir+'yes',n_generated_samples=6, save_to_dir=augmented_data_path+'yes')
            # augment data for the examples with label equal to 'no' representing non-tumurous examples
            self.augment_data(file_dir=image_dir+'no', n_generated_samples=9, save_to_dir=augmented_data_path+'no')
        else:
            print("Number of file in load folder= %d",len(dir))   
            
    def load_data(self,dir_list):
    
        print("Function load_data");
        # load all images in a directory
        x = []
        y = []
    #     image_width, image_height = image_size
        
        for directory in dir_list:
            for filename in listdir(directory):
                image = cv2.imread(directory+'/'+filename)
                x.append(image)
                # append a value of 1 to the target array if the image
                # is in the folder named 'yes', otherwise append 0.
                if directory[-3:] == 'yes':
                    y.append([1])
                else:
                    y.append([0])
                    
        x = np.array(x)
        y = np.array(y)
        
        # Shuffle the data
        x, y = shuffle(x, y)
        
        print (f'Number of examples is: {len(x)}')
        print (f'X shape is: {x.shape}')
        print(f'y shape is: {y.shape}')
        
        return x, y;
    def plot_samples(self,x, y, labels_dict, n=50):
        print("Function plot_samples");
        """
        
        Creates a gridplot for desired number of images (n) from the specified set
        """
        plt.figure(2)
          
        #plt.figure(2)#figsize=(15,6))        
        for index in range(len(labels_dict)):
            print('index=',index)
            imgs = x[np.argwhere(y == index)][:n]
            j = 10
            i = int(n/j)
    
            c = 1
            for img in imgs:
                plt.subplot(i,j,c)
                plt.imshow(img[0])
                plt.xticks([])
                plt.yticks([])
                c += 1    
            plt.suptitle('Tumor: {}'.format(labels_dict[index]))
            print("image show1,Tumor")  
            plt.show(block=False)
            plt.pause(timerForShowImage)
            plt.close()                                  

            
    def LoadDataAndPlotSample(self):
        
        print("Function LoadDataAndPlotSample");
        
        global X_train
        global Y_train 
        X_train, Y_train = self.load_data([augmented_yes, augmented_no])
        self.plot_samples(X_train, Y_train, ['No','Yes'], 20)    
        
    def crop_brain_contour(self,image, plot=False):
        
        print("Function crop_brain_contour");
        # Convert the image to grayscale, and blur it slightly
        gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        gray = cv2.GaussianBlur(gray, (5, 5), 0)
        
        thresh = cv2.threshold(gray, 45, 255, cv2.THRESH_BINARY)[1]
        thresh = cv2.erode(thresh, None, iterations=2)
        thresh = cv2.dilate(thresh, None, iterations=2)
    
        # Find contours in thresholded image, then grab the largest one
        cnts = cv2.findContours(thresh.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        cnts = imutils.grab_contours(cnts)
        c = max(cnts, key=cv2.contourArea)
        # extreme points
        extLeft = tuple(c[c[:, :, 0].argmin()][0])
        extRight = tuple(c[c[:, :, 0].argmax()][0])
        extTop = tuple(c[c[:, :, 1].argmin()][0])
        extBot = tuple(c[c[:, :, 1].argmax()][0])
        
        # crop new image out of the original image using the four extreme points (left, right, top, bottom)
        new_image = image[extTop[1]:extBot[1], extLeft[0]:extRight[0]]            
    
        if plot:
            plt.figure()
            plt.subplot(1, 2, 1)
            plt.imshow(image)
            plt.tick_params(axis='both', which='both', top=False, bottom=False, left=False, right=False,labelbottom=False, labeltop=False, labelleft=False, labelright=False)
            plt.title('Original Image')
            plt.subplot(1, 2, 2)
            plt.imshow(new_image)
            plt.tick_params(axis='both', which='both',top=False, bottom=False, left=False, right=False,labelbottom=False, labeltop=False, labelleft=False, labelright=False)
            plt.title('Cropped Image')
            print("image show2,Original and Cropped image")        
            plt.show()
        #else:
           # print("Not show image show2,Original and Cropped image")        
            
        return new_image
    
    def ImageProccessFuntionc(self,imagePath):
        print("Function ImageProccessFuntionc");
        
        global img;
        global img_cnt;
        global img_pnt;
        global new_img;
        img = cv2.imread(imagePath)#'../input/brain-mri-images-for-brain-tumor-detection/brain_tumor_dataset/yes/Y108.jpg')
        img = cv2.resize(img, dsize=IMG_SIZE,interpolation=cv2.INTER_CUBIC)
        gray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
        gray = cv2.GaussianBlur(gray, (5, 5), 0)
        
        # threshold the image, then perform a series of erosions +
        # dilations to remove any small regions of noise
        thresh = cv2.threshold(gray, 45, 255, cv2.THRESH_BINARY)[1]
        thresh = cv2.erode(thresh, None, iterations=2)
        thresh = cv2.dilate(thresh, None, iterations=2)
        
        # find contours in thresholded image, then grab the largest one
        cnts = cv2.findContours(thresh.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        cnts = imutils.grab_contours(cnts)
        c = max(cnts, key=cv2.contourArea)
        
        # find the extreme points
        extLeft = tuple(c[c[:, :, 0].argmin()][0])
        extRight = tuple(c[c[:, :, 0].argmax()][0])
        extTop = tuple(c[c[:, :, 1].argmin()][0])
        extBot = tuple(c[c[:, :, 1].argmax()][0])
        
        # add contour on the image
        img_cnt = cv2.drawContours(img.copy(), [c], -1, (0, 255, 255), 4)
        
        # add extreme points
        img_pnt = cv2.circle(img_cnt.copy(), extLeft, 8, (0, 0, 255), -1)
        img_pnt = cv2.circle(img_pnt, extRight, 8, (0, 255, 0), -1)
        img_pnt = cv2.circle(img_pnt, extTop, 8, (255, 0, 0), -1)
        img_pnt = cv2.circle(img_pnt, extBot, 8, (255, 255, 0), -1)
        
        # crop
        ADD_PIXELS = 0
        new_img = img[extTop[1]-ADD_PIXELS:extBot[1]+ADD_PIXELS, extLeft[0]-ADD_PIXELS:extRight[0]+ADD_PIXELS].copy()
        return new_img
        
    def ShowImageCropFunction(self):
        
        print("Function Function2");
        plt.figure(figsize=(15,6))
        plt.subplot(141)
        plt.imshow(img)
        plt.xticks([])
        plt.yticks([])
        plt.title('Step 1. Get the original image')
        plt.subplot(142)
        plt.imshow(img_cnt)
        plt.xticks([])
        plt.yticks([])
        plt.title('Step 2. Find the biggest contour')
        plt.subplot(143)
        plt.imshow(img_pnt)
        plt.xticks([])
        plt.yticks([])
        plt.title('Step 3. Find the extreme points')
        plt.imshow(new_img)
        plt.xticks([])
        plt.yticks([])
        plt.title('Step 4. Crop the image')
        print("image show3: original, biggest,extreme, extreme  ")    
        #plt.show()
        plt.show(block=False)
        plt.pause(timerForShowImage)
        plt.close()        
        
    def Croping_Data(self,train):
    
        print("Function Croping_Data");
        # load all images in a directory
        x = []
        y = []
       
        for img in train:
            image = self.crop_brain_contour(img, plot=False)
            x.append(image)
        
        x = np.array(x)
        
       
        return x
        
        
    def Resize_Data(self,train):
        print("Function Resize_Data");
        # load all images in a directory
        x = []
        y = []
    
    
        IMG_WIDTH, IMG_HEIGHT = (IMAGE_SIZE_FOR_BUILDMODEL, IMAGE_SIZE_FOR_BUILDMODEL)
        count=0
        print ("length of image array= ",len(train))   
        for img in train:
            image = cv2.resize(img, dsize=(IMG_WIDTH, IMG_HEIGHT), interpolation=cv2.INTER_CUBIC)
            # normalize values
            image = image / 255.
            # convert image to numpy array and append it to X
            count=count+1
            x.append(image)    
        print("convert image to numpy array  ")            
        x = np.array(x)#.astype(np.float32); #np.array(x)
        print("convert image to numpy array  ")            
    
        return x
    
    def ShowDataTrainingAfterCropFunction(self):
        print("Function Function4");
        global X;
        global Y;
        X = self.Croping_Data(X_train);
        
        print("plot crop image sample");            
        augmented_yes =augmented_data_path+'yes'
        augmented_no = augmented_data_path+'no'
        
        #IMG_WIDTH, IMG_HEIGHT = (240, 240)
        X = self.Resize_Data(X)#,IMG_WIDTH,IMG_HEIGHT)
        Y = Y_train;
        self.plot_samples(X, Y_train, ['No','Yes'],10)
        
    def split_data(self,x, y, test_size=0.2,train_size=None):
    
        print("Function split_data");
        x_train, x_test_val, y_train, y_test_val = train_test_split(x, y, test_size=test_size, train_size=train_size, shuffle=False)
        x_test, x_val, y_test, y_val = train_test_split(x_test_val, y_test_val, test_size=0.5,train_size=train_size)
        
        return x_train, y_train, x_val, y_val, x_test, y_test
    
    def ShowBarChartFunction(self):
        global X_train_
        global Y_train_
        global X_val_
        global Y_val_
        global X_test_
        global Y_test_
        print("Function Function5");
        y=Y;
    
        
        X_train_, Y_train_, X_val_, Y_val_, X_test_, Y_test_ = self.split_data(X, y, test_size=0.3)
        print ("number of training examples = " + str(X_train.shape[0]))
        print ("number of validation examples = " + str(X_val_.shape[0]))
        print ("number of test examples = " + str(X_test_.shape[0]))
        y = dict()
        y[0] = []
        y[1] = []
        for set_name in (Y_train_, Y_val_, Y_test_):
            y[0].append(np.sum(set_name == 0))
            y[1].append(np.sum(set_name == 1))
        
        trace0 = go.Bar(
            x=['Train Set', 'Validation Set', 'Test Set'],
            y=y[0],
            name='No',
            marker=dict(color='#33cc33'),
            opacity=0.7
        )
        trace1 = go.Bar(
            x=['Train Set', 'Validation Set', 'Test Set'],
            y=y[1],
            name='Yes',
            marker=dict(color='#ff3300'),
            opacity=0.7
        )
        data = [trace0, trace1]
        layout = go.Layout(
            title='Count of classes in each set',
            xaxis={'title': 'Set'},
            yaxis={'title': 'Count'}
        )
        fig = go.Figure(data, layout)
        iplot(fig)
        
    def build_model(self,input_shape):
        
        print("Function build_model");
        X_input = Input(input_shape) 
        x = ZeroPadding2D((2, 2))(X_input) 
        
        x = Conv2D(32, (7, 7), strides = (1, 1))(x)
        x = BatchNormalization(axis = 3, name = 'bn0')(x)
        x = Activation('relu')(x) 
        
        x = MaxPooling2D((4, 4))(x) 
        x = MaxPooling2D((4, 4))(x) 
        x = Flatten()(x) 
        x = Dense(1, activation='sigmoid')(x) 
        model = Model(inputs = X_input, outputs = x)
        
        return model
    
    def BuildTrainingModelFunction(self):
        print("Function Function6");
        
        global history
        global model
        physical_devices = tf.config.experimental.list_physical_devices('GPU')
        if len(physical_devices) > 0:
           tf.config.experimental.set_memory_growth(physical_devices[0], True)        
        IMG_WIDTH = IMAGE_SIZE_FOR_BUILDMODEL
        IMG_HEIGHT =IMAGE_SIZE_FOR_BUILDMODEL
          
        IMG_SHAPE = (IMG_WIDTH, IMG_HEIGHT, 3)
        model =self.build_model(IMG_SHAPE)
        model.summary()
        model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])
        print("Xtrain1=", X_train_, "YTrain1=", Y_train_,"X_Val=", X_val_, "Y_Val=",Y_val_)
        #checkpoint_path = "data/output/cp.ckpt"
        #checkpoint_dir = os.path.dirname(checkpoint_path)    
        # Create a callback that saves the model's weights
        #cp_callback = tf.keras.callbacks.ModelCheckpoint(filepath=checkpoint_path, save_weights_only=True, verbose=1)        
        #training data in here out put with the model
        #model.save_weights(checkpoint_path.format(epoch=0))
        
        model.fit(x=X_train_, y=Y_train_, batch_size=12, epochs=22,validation_data=(X_val_, Y_val_))#steps_per_epoch=100, validation_steps=10)
        
        test_loss, test_acc = model.evaluate(X_test_, Y_test_, verbose=2)   
        modelPath="data/output/BrainDetectModel.h5"
        model.save(modelPath) 
        
        history = model.history.history
        self.plot_accuracy_metrics(history)
        
    def plot_accuracy_metrics(self,history):
        
        print("Function plot_metrics");
        train_loss = history['loss']
        val_loss = history['val_loss']
        train_acc = history['accuracy']
        val_acc = history['val_accuracy']
        
        # Loss
        plt.figure(1)
        plt.plot(train_loss, label='Training Loss')
        plt.plot(val_loss, label='Validation Loss')
        plt.title('Loss')
        plt.legend()
        print("image show4: Loss")    
        plt.show(block=False)
        plt.pause(timerForShowImage)
        plt.close() 
        
        # Accuracy
        plt.figure(2)
        plt.plot(train_acc, label='Training Accuracy')
        plt.plot(val_acc, label='Validation Accuracy')
        plt.title('Accuracy')
        plt.legend()
        print("image show5: Accuracy")    
        plt.show(block=False)
        plt.pause(timerForShowImage)
        plt.close()       
        
    def plot_confusion_matrix(self,cm, classes, normalize=False, title='Confusion matrix',cmap=plt.cm.Blues):
        print("Function plot_confusion_matrix");
        """
        This function prints and plots the confusion matrix.
        Normalization can be applied by setting `normalize=True`.
        """
        plt.figure(figsize = (6,6))
        plt.imshow(cm, interpolation='nearest', cmap=cmap)
        plt.title(title)
        plt.colorbar()
        tick_marks = np.arange(len(classes))
        plt.xticks(tick_marks, classes, rotation=90)
        plt.yticks(tick_marks, classes)
        if normalize:
            cm = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]
    
        thresh = cm.max() / 2.
        cm = np.round(cm,2)
        for i, j in itertools.product(range(cm.shape[0]), range(cm.shape[1])):
            plt.text(j, i, cm[i, j],
                     horizontalalignment="center",
                     color="white" if cm[i, j] > thresh else "black")
        plt.tight_layout()
        plt.ylabel('True label')
        plt.xlabel('Predicted label')
        print("image show6, confusion matrix")    
        plt.show(block=False)
        plt.pause(timerForShowImage)
        plt.close()         
        
    def DetectObjectAndShowResultFunction(self): #view result accurary
        print("Function DetectObjectAndShowResultFunction");
        labels = ['yes','no']
        # validate on val set 
        predictions = model.predict(X_val_)
        predictions = [1 if x> 0.5 else 0 for x in predictions]
        
        accuracy = accuracy_score(Y_val_, predictions)
        print('Val Accuracy  = %.2f' % accuracy)
        
        confusion_mtx = confusion_matrix(Y_val_, predictions) 
        cm = self.plot_confusion_matrix(confusion_mtx, classes = labels, normalize=False, title='Confusion matrix With Validation Data')
        
        # validate on val set
        predictions = model.predict(X_test_)
        predictions = [1 if x>0.5 else 0 for x in predictions]
    
        accuracy = accuracy_score(Y_test_, predictions)
        print('Val Accuracy = %.2f' % accuracy)
    
        confusion_mtx = confusion_matrix(Y_test_, predictions) 
        cm = self.plot_confusion_matrix(confusion_mtx, classes = labels, normalize=False, title='Confusion matrix With Test Data')
        
        plt.figure(3)        
        for i in range(20):
            plt.subplot(3, 7, i+1)         
            plt.imshow(X_test_[i])
            plt.xticks([])
            plt.yticks([])
            plt.title(f'Tumor Actual class: {Y_test_[i]}\n Tumor Predicted class: {predictions[i]}')
            print("image show6, Accuracy and Predicted")
        plt.show(block=False)
        plt.pause(timerForShowImage)
        plt.close()         
    #def SaveModelTrained(self, model):
        
        
    def BrainDetectFunction(self):
        print("Function main");
        self.CreatFolderPaths();    
        self.LoadAgumentData();
        self.LoadDataAndPlotSample();
        self.ImageProccessFuntionc(image_dir+EXAMPLE_IMAGENAME);
        self.ShowImageCropFunction();
        self.ShowDataTrainingAfterCropFunction();
        self.ShowBarChartFunction();
        self.BuildTrainingModelFunction();
        self.DetectObjectAndShowResultFunction();
        print("End programs!")    
    def InitialModelTrained(self):
        global new_model
        modelPath="data/output/BrainDetectModel.h5"
        new_model = tf.keras.models.load_model(modelPath)
        # Show the model architecture
        new_model.summary()         
    def DetectSpecialImage(self,imagePath):
        x= []
        y = []        
        
        y.append(1)
        y.append(1)    
        y.append(1) 
        y.append(1) 
        
        imageForDetect= self.ImageProccessFuntionc(imagePath);
        
        x.append(imageForDetect)
        x.append(imageForDetect) 
        x.append(imageForDetect)
        x.append(imageForDetect) 
        x = self.Croping_Data(x)  
        imageForDetectArray2 = self.Resize_Data(x)
       

        
        y = np.array(y)
        imageForDetectArray2, y = shuffle(imageForDetectArray2, y)
   
        X_train_, Y_train_, X_val_, Y_val_, X_test_, Y_test_ = self.split_data(imageForDetectArray2, y, test_size=0.5,train_size=0.5)
        predictions = new_model.predict(X_val_)        
        if predictions>0.4:
           HaveTummor="Detected tumor"
        else:
           HaveTummor="Haven't tumor"           
        plt.figure(4)
        plt.imshow(imageForDetect)
        plt.xticks([])
        plt.yticks([])
        plt.title(f'Tumor Prediction Rate:{predictions} -->{HaveTummor}')      
        plt.show()
        
    def __init__(self):
        print("BrainDetectFunction class init")
        self.CreatFolderPaths()
        self.InitialModelTrained()
        
