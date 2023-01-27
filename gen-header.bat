@echo off
cd build\classes
"D:\Program Files\Java\jdk1.8.0_351\bin\javah" -classpath ".\kotlin\main" org.itxtech.mirainative.Bridge
copy /y org_itxtech_mirainative_Bridge.h ..\..\native
cd ..\..
