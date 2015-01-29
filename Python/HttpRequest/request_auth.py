#-*- coding=utf-8 -*-

import requests

url = "https://iaaa.pku.edu.cn/iaaa/oauth.jsp"
username = "1200012778"
password = "Mima484860"

response = requests.post(url)#, auth=(username, password))

print response.status_code
#print response.headers['content-type']
print response.content
