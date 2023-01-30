@echo off
cd build\classes
javap -p -constants -cp ".\kotlin\main" org.itxtech.mirainative.Bridge > Bridge.java
python ..\..\gen-header.py
javac -h . Bridge.java
copy /y org_itxtech_mirainative_Bridge.h ..\..\native
del Bridge.java
del Bridge.class
cd ..\..