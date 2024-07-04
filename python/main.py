#If you want to scrape a website
# 1. Use the API
# 2. HTML Web scrape using some tool like bs4
#Step 0-
#install all the requerment
#pip install requests
#pip install bs4
#pip install html5lib

import requests
from bs4 import BeautifulSoup
url = "https://codeWithHarry.com"

#step 1- Get the HTML
r = requests.get(url)
htmlContent = r.content
#print(htmlContent)

#step 2- Parse the HTML
soup = BeautifulSoup(htmlContent, 'html.parser')
#print(soup.prettify)

#step 3- HTML tree traversal
title = soup.title
#print(type(title.string))

# comonly used type of object:
#print(type(title)) #1. tag
#print(type(title.string)) #2. Navigable String
#print(type(soup)) #3. BeautifulSoup object
#4. comment

#get the title of the HTML page
title = soup.title

#Get all the paragraph from the page
paras = soup.find_all('p')
#print(paras)

#Get all the Anchor tags from the page
anchors = soup.find_all('a')
#print(anchors)

#print(soup.find('p')) #get the first HTML element

#print(soup.find('p')['class']) #get classes of any element in the HTML page

#print(soup.find_all("p", class_="lead"))

#Get the text from the tags/soup
#print(soup.find('p').get_text())
#print(soup.get_text())

#get all the Link on the page
anchors = soup.find_all('a')
all_link = set()
for link in anchors:
    if(link.get('href')!= '#'):
        linkText = "https://codeWithHarry.com" + link.get('href')
        all_link.add(link)
        #print(linkText)

navbarSupportedContent = soup.find(id = 'navbarSupportedContent')   
#for elem in navbarSupportedContent.children:
    #print(elem)     

for item in navbarSupportedContent.string:
    print(item) 

    # from flask import Flask

# app = Flask(__name__)

# def home():
#     return 'hello, world!'

# if __name__ == '__main__':
#     app.run(debug=True)

# from flask import Flask,jsonify

# app = Flask(__name__)

# def get_data():
#     return jsonify({'data':'hello world!'})

# if __name__ == '__main__':
#     app.run(debug=True)

# def handle_url():
#     return 'URL received!'

# import requests

# url = '(link unavaliable)'
# response = requests.get(url)   