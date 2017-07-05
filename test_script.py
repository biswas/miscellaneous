import csv

names=[]
ages=[]
with open('example_file','r') as f:
    next(f) # skip headings
    reader=csv.reader(f,delimiter='\t')
    for name,age in reader:
        names.append(name)
        ages.append(age) 

print(names)
print(ages)
