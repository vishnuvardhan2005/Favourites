# Sendmail utility

import smtplib
#import pdb; pdb.set_trace()

def send(rEmailId, mesg):
    server = smtplib.SMTP('smtp.gmail.com',587)
    server.ehlo()
    server.starttls()
    server.ehlo()
    sEmailId = 'vishnuvardhan.2005@gmail.com'
    pwd = '10904258'
    server.login(sEmailId,pwd)
    server.sendmail(sEmailId,rEmailId,mesg)
    server.close()

if __name__== "__main__":
    print "Enter email id :",
    rEmailId = raw_input()
    print "Enter message :",
    mesg = raw_input()
    send(rEmailId,mesg)
