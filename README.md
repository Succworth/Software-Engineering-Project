# Cracking ASL
### Developer Documentation
#### Getting Started 
- To run/develop in Qt Creator: File>Open File or Project>CrackingASL.pro
- Within the app directory:
	-  files with a ```.ui``` extension can be edited in Qt Creator's design tab to change elements of the GUI
	-  files with a ```.cpp``` and ```.h``` extension are Qt flavor C++ source and header files respectively and control the functionality of the program

#### Project Layout

- The project structure contains two sub directories ```app``` and ```test```
- Within the ```app``` directory:
	-  ```app.pro``` is the Qt project file for the app where build rules and resources are defined
	-  ```main.cpp``` is the main class for Qt
	-  ```user(.h)(.cpp)``` is a class for the user object
	-  ```answerkey(.h)(.cpp)``` is a class to get questions, answers, and choices
	-  ```crackingasl(.h)(.cpp)(.ui)``` are the files related to the initial login window
	-  ```mainmenu(.h)(.cpp)(.ui)``` are the files related to the mainmenu window, displayed after login
	-  ```gamewindow(.h)(.cpp)(.ui)``` are the files related to the lessons window
	-  ```benchmarkwindow(.h)(.cpp)(.ui)``` are the files related to the benchmarks window
- Within the ```test``` directory:
	-  ```tests.pro``` is the Qt project file for the tests
	-  ```tst_login.cpp``` is class all of the tests


#### Developer Test Logins 
There are two developer logins in the database that may be useful:
- ID: ```12345678``` Name: ```aye```
- ID: ```88888888``` Name: ```bee```

#### Adding assets help 
- Assets paths and file names are added to app/Assets.qrc following the existing XML style formatting 
- Tip: ```D:\Users\USER\Documents\Software-Engineering-Project\Assets>dir /b /s > files.txt``` in windows cmd will pipe all the directory files and subfiles to a .txt file which can be changed to XML entries using find+replace in an editor of your choice
- Assets from app/Assets.qrc are compiled as Qt resources automatically during every build

#### Deploying
- In the GitHub project page go to the actions tab
- Click on the "Build & Deploy Installer" workflow and click run workflow
- After the workflow completes, click on it and you can find a zip file of the installer under "Artifacts"
