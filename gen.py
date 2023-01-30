f=open(r"build\classes\Bridge.java","r")
lines=f.readlines()
f.close()
java="package org.itxtech.mirainative;"
java+='\n'
java+="public class Bridge {"
java+='\n'
for i in lines:
    if ' native ' in i:
        if '()' in i:
            java+=i
            java+='\n'
        else:
            tmp=i.split(',')
            for j in range(len(tmp)-1):
                java+=tmp[j]+' arg'+str(j)+','
            tmp1=tmp[-1].split(')')
            java+=tmp1[0]+' arg'+str(len(tmp)-1)+')'+tmp1[1]
            java+='\n'
java+="}"
f=open(r"build\classes\Bridge.java","w")
f.write(java)
f.close()