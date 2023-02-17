import hashlib
import os
for i in os.listdir('build\\mirai'):
    if i.endswith('.jar'):
        sha1=''
        with open('build\\mirai\\' + i, 'rb') as f:
            sha1=hashlib.sha1(f.read()).hexdigest()
        with open('build\\mirai\\' + i + '.sha1', 'w') as f:
            f.write(sha1)