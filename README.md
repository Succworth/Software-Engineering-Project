# Cracking ASL
### Developer help/ troubleshooting
- To run/develop in Qt Creator: File>Open File or Project>CrackingASL.pro
- If the db is not working check that path printed in the console is correct. If it is not, use an asbsolute path in ```db.setDatabaseName(dir.path()+"/data.db");```

### Adding assets help ###
- Assets paths and file names are added to Assets.qrc following the exising formatting
- Tip: ```D:\Users\USER\Documents\Software-Engineering-Project\Assets>dir /b /s > files.txt``` will pipe all the directory files and subfiles to a .txt file which can be changed to XML <file></file> entries using an find+replace in an editor of your choice 
- Then the external binary file (Assets.rrc) can be compiled by ```D:\Users\USER\Documents\Software-Engineering-Project>rcc.exe -binary Assets.qrc -o Assets.rcc```
- Tip: rcc.exe will be in a path like: ```D:\Qt\5.15.2\mingw81_32\bin\rcc.exe```, copy it to the previous location temporarily so you dont need a system var
