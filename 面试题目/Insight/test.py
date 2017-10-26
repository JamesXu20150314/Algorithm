##############################
## Author: Zhimin Xu
## Date  : 20:58 2017/10/26 (Beijing Time)
##############################

# -*- coding: cp936 -*-
import os
import time
import math
import numpy as np
import pylab as pl

class Item:
    CMTE_ID = ''
    ZIP_CODE = ''
    TRANSACTION_DT = ''
    TRANSACTION_AMT = 0
    OTHER_ID = ''

    def __init__(self, vCMTE_ID, vZIP_CODE, vTRANSACTION_DT, vTRANSACTION_AMT, vOTHER_ID):
        self.CMTE_ID = vCMTE_ID
        self.ZIP_CODE = vZIP_CODE
        self.TRANSACTION_DT = vTRANSACTION_DT
        self.TRANSACTION_AMT = vTRANSACTION_AMT
        self.OTHER_ID = vOTHER_ID

Items = []
global Length
Length = 0

def ReadItems():
    f = open("./test.txt", "r")
    count = 0
    global Length
    Length = 0
    while True:
        line = f.readline()
        if line:
            count = count + 1
            colum = 0
            cmteid = ''
            zipcode = ''
            transactiondt = ''
            transactionamt = 0
            otherid = ''
            for word in line.split('|'):
                if colum == 0:
                    cmteid = word
                elif colum == 10:
                    zipcode = word
                elif colum == 13:
                    transactiondt = word
                elif colum == 14:
                    transactionamt = int(word)
                elif colum == 15:
                    otherid = word
                else:
                    pass
                
                colum = colum + 1

            if otherid != '':
                pass
            else:
                Length = Length + 1
                ite = Item(cmteid, zipcode, transactiondt, transactionamt, otherid)
                Items.append(ite)
        else:
            break

    print 'Useful: \t' + str(Length) + ' items.'
    print 'Total : \t' + str(count) + ' items.'
    f.close()
    pass

def printItems():
    for i in range(0,len(Items)):
        print ''
        print 'CMTE_ID: ' + Items[i].CMTE_ID
        print 'ZIP_CODE: ' + Items[i].ZIP_CODE
        print 'TRANSACTION_DT: ' + Items[i].TRANSACTION_DT
        print 'TRANSACTION_AMT: ' + str(Items[i].TRANSACTION_AMT)
        print 'OTHER_ID: ' + Items[i].OTHER_ID
        print ''

def print_medianvals_by_zip():
    print 'To be implemented in future.'
    pass

def print_medianvals_by_date():
    print 'To be implemented in future.'
    pass
       
if __name__ == '__main__':
    ReadItems()
    printItems()
    
