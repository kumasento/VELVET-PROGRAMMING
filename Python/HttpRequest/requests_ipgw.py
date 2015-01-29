#-*- coding:utf-8 -*-

import json
import requests
from urllib import unquote, quote

url = "https://its.pku.edu.cn/cas/login"

mid_padd = "%7C%3BkiDrqvfi7d%24v0p5Fg72Vwbv2%3B%7C"
tail_padd = "%7C%3BkiDrqvfi7d%24v0p5Fg72Vwbv2%3B%7C12" 

class IPGWConnect:

    def __init__(self):
        self.uid = ""
        self.passwd = ""

    def login(self, uid, passwd):

        login_info = self.login_bind(uid, passwd)

        print "posting to %s with %s ..." % (url, login_info)

        response = requests.post(url, data=login_info)


    def login_bind(self, uid, passwd):
        login_info = {}
        login_info['username1'] = uid
        login_info['password'] = passwd
        login_info['pwd_t'] = quote('密码')
        login_info['fwrd'] = 'free'
        login_info['username'] = \
                uid + mid_padd + passwd + tail_padd
            
        return json.dumps(login_info)

USERNAME = ""
PASSWORD = ""

if __name__ == '__main__':
    
    ipgw = IPGWConnect()

    ipgw.login(USERNAME, PASSWORD)
