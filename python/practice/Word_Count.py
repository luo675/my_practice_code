words = ['python' , 'java','python','c','python','java','c++','c','python']

count ={}

for word in words:
    if word in count:
        count[word]=count[word]+1

    else:
        count[word]=1

print(count)