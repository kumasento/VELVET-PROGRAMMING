#!/usr/bin/python
#-*- coding: utf-8 -*-

import smtplib
from email.mime.text import MIMEText

from HTMLParser import HTMLParser
from time import sleep

import time
import re
import requests

FROM_EMAIL_HOST = "mail.pku.edu.cn" 
EMAIL_USER = "1200012778" 
EMAIL_PASSWD = "Mima484860" 
TO_EMAIL = "vincentzhaorz@pku.edu.cn" 

url = "http://162.105.146.183/wst/homework/2014/homework.html"
uid = "1200012778"

def get():
    response = requests.get(url)
    status = response.status_code
    if status != 200:
        raise Exception("status code: %d" % status)        

    return response.content

class WSTHTMLParser(HTMLParser):
    def __init__(self):
        HTMLParser.__init__(self)
        self.buf    = []
        self.result = []
    
    def handle_starttag(self, tag, attrs):
        if tag == 'tr':
            self.buf = []
    def handle_endtag(self, tag):
        if tag == 'tr':
            self.result.append(self.buf)
    def handle_data(self, data):
        d = data.rstrip()
        if d != '':
            self.buf.append(d)

class Email:
    def __init__(self):
        self.mail_host = FROM_EMAIL_HOST
        self.mail_user = EMAIL_USER
        self.mail_pass = EMAIL_PASSWD
        self.mail_postfix = FROM_EMAIL_HOST

    def send(self, content, To="", Me="WST Request", Subject=""):
        Me = Me + "<" + self.mail_user + "@" + self.mail_postfix + ">"
        To = TO_EMAIL if To == "" else To
        msg = MIMEText(content, _subtype='plain',_charset='utf-8')
        msg['Subject'] = "[%s] "%(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time()))) + Subject
        msg['From'] = Me
        msg['To'] = To
        for i in range(0, 3):
            try:
                server = smtplib.SMTP()
                server.connect(self.mail_host)
                server.login(self.mail_user,self.mail_pass)
                server.sendmail(Me, To, msg.as_string())
                server.close()
                print "[Info] Send mail %s"%(msg['Subject'])
                return True
            except Exception, e:
                print "[Error]",str(e)
        return False

class Job:
    def __init__(self):
        self.cur_len = 2

    def parse_page(self, page):
        wstparser = WSTHTMLParser()
        wstparser.feed(page)
        
        for item in wstparser.result:
            if len(item) > 2 and item[1] == uid:
                # this is my grades
                if len(item) > self.cur_len:
                    m = Email()
                    m.send( "[%s] New grades! %s" % \
                            (time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()), \
                            str(item[self.cur_len+1:])),
                            Subject = "出成绩了！")

                self.cur_len = len(item)

if __name__ == '__main__':
    page = get()

    job = Job()
    i = 0
    while(True):
        print "Round:", i
        job.parse_page(page)
        
        i += 1
        sleep(120)
