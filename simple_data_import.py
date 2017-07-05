#example to import and organize data using exampledata file

import csv #for inporting csv files
import numpy as np #for dealing with arrays

#file = open('exampledata') #identify the name of data file
#rawfile = csv.reader(file) #apply csv reader to data file 
#for row in rawfile: #loop through all rows in data file
    #print (row)       #print all rows in data file
    #print (row[0])     #print only row 1

#name the columns as lists in data file and designate that its tab delimited instead of csv
minuteslist = [x[0] for x in csv.reader(open('exampledata','r'),delimiter='\t')]
responselist = [x[1] for x in csv.reader(open('exampledata','r'),delimiter='\t')]
pressurelist = [x[2] for x in csv.reader(open('exampledata','r'),delimiter='\t')]

#convert lists to arrays
myarray = np.asarray(minuteslist)


