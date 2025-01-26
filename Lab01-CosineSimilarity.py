import nltk
from nltk.corpus import stopwords
nltk.download('stopwords')

eng_stops=set(stopwords.words('english'))

fileA=open("C:\\Users\\HP\\Desktop\\FileA.txt","r")
fileB=open("C:\\Users\\HP\\Desktop\\FileB.txt","r")

# print("FileA :",fileA.read())
# print()
# print("FileB :",fileB.read())
contentA=fileA.read()
contentB=fileB.read()

fileA.close()
fileB.close()
A=''
B=''

for word in contentA.split():
    if word.lower() not in eng_stops:
        w=''
        for letter in word:
            if(letter!=',' and letter!='.'and letter!='!'):
               w+=letter
        A=A+' '+w


# print("A"+"\n"+A)

for word in contentB.split():
    if word.lower() not in eng_stops:
        w=''
        for letter in word:
            if(letter!=',' and letter!='.'and letter!='!'):
               w+=letter
        B=B+' '+w
# print( "B\n"+B)

dictA= dict()
dictB= dict()


for word in A.split():
    if(word==' '):
        continue
    flag= False
    for key in dictA:
        if(key==word.lower()):
            dictA[key]+=1
            flag=True
            break
    if(flag==False):
        dictA[word.lower()]=1

for word in B.split():
    if(word==' '):
        continue
    flag= False
    for key in dictB:
        if(key==word.lower()):
            dictB[key]+=1
            flag=True
            break
    if(flag==False):
        dictB[word.lower()]=1

Grand=dict()

for keyA in dictA:
    for keyB in dictB:
        if(keyA==keyB):
            Grand[keyA]=dictA[keyA]*dictB[keyB]

print("dictA:\n",dictA)
print("dictB:\n",dictB)
print("Grand dictionary:\n",Grand)

AdotB=0
for key in Grand:
    AdotB+=Grand[key]

modA=0
sumA=0
for key in dictA:
    sumA+= int(dictA[key])**2
modA=sumA**(0.5)
print("sum a  ",sumA ," modA ",modA)

modB=0
sumB=0
for key in dictB:
    sumB+= int(dictB[key])**2
modB=sumB**(0.5)
print("sum b ",sumB," modB ",modB )
print("A.B= ",AdotB)

answer=AdotB/(modA*modB)
print("consine = ",answer)




    
    

