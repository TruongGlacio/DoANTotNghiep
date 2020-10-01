import numpy as np
import os
import PIL
import PIL.Image
import tensorflow as tf
import tensorflow_datasets as tfds
import matplotlib.pyplot as plt
from tensorflow.keras import layers
import pathlib
import glob
from pathlib import Path
from skimage.data import image_fetcher
#train_ds training data
#val_ds validation data

class BrainTumorMask_RCNN:
    def DefineGlobalPath(self):
        print("Function DefineGlobalPath");
        
        global mInputDir
        global mOutPuDir
        global mLabelClass
        global subInput
        global subOutput
        global img_height
        global img_width
        global batch_size
        subInput= '/input'
        subOutput='/output'
        img_height=180
        img_width=180
        batch_size=32
        
    def LoadDataFroFromDir(self, InputDir):
        print("Function LoadDataFroFromDir");
        
        batch_size = 32
        img_height = 180
        img_width = 180
        labelNumber=0
        validation_split=0.3
        #train_ds = tf.keras.preprocessing.image_dataset_from_directory( InputDir,
                                                                        #validation_split=0.3,
                                                                        #subset="training",
                                                                        #seed=123,
                                                                        #image_size=(img_height, img_width),
                                                                        #batch_size=batch_size)
        #val_ds = tf.keras.preprocessing.image_dataset_from_directory( data_dir,
                                                                      #validation_split=0.3,
                                                                      #subset="validation",
                                                                      #seed=123,
                                                                      #image_size=(img_height, img_width),
                                                                      #batch_size=batch_size)  
        #class_names = train_ds.class_names
        #labelNumber=len(class_names)
        
        #print(class_names)     
        
        #plt.figure(figsize=(10, 10))
        #for images, labels in train_ds.take(1):
            #for i in range(9):
                #ax = plt.subplot(3, 3, i + 1)
                #plt.imshow(images[i].numpy().astype("uint8"))
                #plt.title(class_names[labels[i]])
                #plt.axis("off")    
        #for image_batch, labels_batch in train_ds:
            #print(image_batch.shape)
            #print(labels_batch.shape)
            #break        
        #image_count = len(glob.glob(InputDir+'**\*{}.jpg',recursive=True))                
        InputDir = pathlib.Path(InputDir)     
        image_count = len(list(InputDir.glob('*/*.jpg')))        
        list_ds = tf.data.Dataset.list_files(str(InputDir/'*/*'), shuffle=False)
        print("list_ds=",list_ds, "image_count=",image_count)  
        
        list_ds = list_ds.shuffle(image_count, reshuffle_each_iteration=False)
        for f in list_ds.take(5):
            print(f.numpy())  
        
        class_names = np.array(sorted([item.name for item in InputDir.glob('*')]))
        
        labelNumber=len(class_names)
        
        print("class_names=",class_names, "labelNumber=",labelNumber)  
        
        val_size = int(image_count * 0.3)
        train_ds = list_ds.skip(val_size)
        val_ds = list_ds.take(val_size)    
        
        print("train_ds=",tf.data.experimental.cardinality(train_ds).numpy())
        print("val_ds=",tf.data.experimental.cardinality(val_ds).numpy())
        
        
        return train_ds,val_ds,class_names,labelNumber
    
    def get_label(self,file_path):
        print("Function get_label");
        
        # convert the path to a list of path components
        parts = tf.strings.split(file_path, os.path.sep)
        print("parts=",parts)
        # The second to last is the class-directory
        one_hot = parts[-2] == mclass_names
        # Integer encode the label
        return mclass_names#tf.argmax(one_hot)
    
    def decode_img(self,img):
        print("Function decode_img");
        
        # convert the compressed string to a 3D uint8 tensor
        img = tf.image.decode_jpeg(img, channels=3)
        # resize the image to the desired size
        return tf.image.resize(img, [img_height, img_width])    
    
    def process_path(self,file_path):
        print("Function process_path");
        
        label = self.get_label(file_path)
        # load the raw data from the file as a string
        img = tf.io.read_file(file_path)
        img =self.decode_img(img)
        return img, label
    
    def MapData(self, train_ds, val_ds):
        print("Function MapData ");
        
        global AUTOTUNE
        # Set `num_parallel_calls` so multiple images are loaded/processed in parallel.
        AUTOTUNE = tf.data.experimental.AUTOTUNE
        
        #train_ds = train_ds.cache().prefetch(buffer_size=AUTOTUNE)
        #val_ds = val_ds.cache().prefetch(buffer_size=AUTOTUNE)        
        train_ds = train_ds.map(self.process_path, num_parallel_calls=AUTOTUNE)
        val_ds = val_ds.map(self.process_path, num_parallel_calls=AUTOTUNE)   
        
        for image, label in train_ds.take(1):
            print("Image shape: ", image.numpy().shape)
            print("Label: ", label.numpy())
        return train_ds,val_ds
    
    def configure_for_performance(self,train_ds):
        print("Function configure_for_performance ");
        
        train_ds = train_ds.cache()
        train_ds = train_ds.shuffle(buffer_size=1000)
        train_ds = train_ds.batch(batch_size)
        train_ds = train_ds.prefetch(buffer_size=AUTOTUNE)
        return train_ds        
    def PlotSample(self, train_ds,class_names):
        print("Function PlotSample ");
        
        image_batch, label_batch = next(iter(train_ds))
        print("label_batch",label_batch)
        plt.figure(figsize=(10, 10))
        for i in range(9):
            ax = plt.subplot(3, 3, i + 1)
            plt.imshow(image_batch[i].numpy().astype("uint8"))
            label = label_batch[i]
            print ("mclass_names[label]=",label[0])
            plt.title(label[0])
            plt.axis("off")
        plt.show()
    
    
    def ReScaleImage(self,train_ds):
        print("Function ReScaleImage ");
        
        normalization_layer = tf.keras.layers.experimental.preprocessing.Rescaling(1./255)
        normalized_ds = train_ds.map(lambda x, y: (normalization_layer(x), y))
        image_batch, labels_batch = next(iter(normalized_ds))
        first_image = image_batch[0]
        # Notice the pixels values are now in `[0,1]`.
        print(np.min(first_image), np.max(first_image))  
        return normalized_ds

    def BuildDataModel(self,LabelClass,train_ds,val_ds):
        print("Function BuildDataModel ");
        
       
            
        model = tf.keras.Sequential([
          tf.keras.layers.experimental.preprocessing.Rescaling(1./255),
          tf.keras.layers.Conv2D(32, 3, activation='relu'),
          tf.keras.layers.MaxPooling2D(),
          tf.keras.layers.Conv2D(32, 3, activation='relu'),
          tf.keras.layers.MaxPooling2D(),
          tf.keras.layers.Conv2D(32, 3, activation='relu'),
          tf.keras.layers.MaxPooling2D(),
          tf.keras.layers.Flatten(),
          tf.keras.layers.Dense(128, activation='relu'),
          tf.keras.layers.Dense(len(LabelClass))
        ])   
        physical_devices = tf.config.experimental.list_physical_devices('GPU')
        if len(physical_devices) > 0:
            tf.config.experimental.set_memory_growth(physical_devices[0], True)            
        model.compile( optimizer='adam',loss=tf.losses.SparseCategoricalCrossentropy(from_logits=True), metrics=['accuracy'])  
       
        model.fit(train_ds, validation_data=val_ds, epochs=22)#,steps_per_epoch=10)#batch_size=12, )
        probability_model = tf.keras.Sequential([model, tf.keras.layers.Softmax()])        
        probability_model.summary()                
        
        

    def SaveModel(self,model,modelSavePath):
        print("Function SaveModel ");
        
        model.save(modelSavePath) 
        
        
  
    def TrainingDataModel(self):
        print("Function TrainingDataModel ");
        
        imagePath=mInputDir
        global mclass_names
        train_ds,val_ds,mclass_names,labelNumber = self.LoadDataFroFromDir(imagePath)
        train_ds_AfterMap,val_ds_AfterMap=self.MapData(train_ds,val_ds)
        
        train_ds_AfterMap = self.configure_for_performance(train_ds_AfterMap)
        val_ds_AfterMap = self.configure_for_performance(val_ds_AfterMap)  
        self.PlotSample(val_ds_AfterMap,mclass_names)
        
        val_ds_AfterMap= self.ReScaleImage(val_ds_AfterMap)
        val_ds_AfterMap=self.ReScaleImage(val_ds_AfterMap)
        print("len(mclass_names)=",len(mclass_names))
        
        self.BuildDataModel(mclass_names,train_ds_AfterMap,val_ds_AfterMap)
        
        
    def DetectSpecialImage(self,imagePath):
        print("Function DetectSpecialImage ");
        
        return True
    
    def SetInputDataPath(self, InputDir):
        print("Function SetInputDataPath ");
        
        global mInputDir
        mInputDir=InputDir+subInput
    def SetOutputPath(seft, OutputPath):
        mOutPuDir=OutputPath+subOutput
        
        
    def __init__(self):
        print("BrainDetectFunction class init")
        self.DefineGlobalPath()
        #self.InitialModelTrained()