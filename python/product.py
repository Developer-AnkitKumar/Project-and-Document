from flask import Flask

app = Flask(__name__)

def home():
    return 'hello, world!'

if __name__ == '__main__':
    app.run(debug=True)

from flask import Flask,jsonify

app = Flask(__name__)

def get_data():
    return jsonify({'data':'hello world!'})

if __name__ == '__main__':
    app.run(debug=True)

def handle_url():
    return 'URL received!'

import requests
from bs4 import BeautifulSoup
url = "https://codeWithHarry.com"
response = requests.get(url)  

def scrape_product(url):
    try:
        response = requests.get(url)
        response.raise_for_status()

        soup = BeautifulSoup(response.content, 'html.parser')

        title = soup.find('h1', class =_'product-specs').text.strip()
        price = soup.find('span', class =_'product-price').text.strip()

        space_table = soup.find('table', class=_'product-specs')
        if specs_table:
            specs = {}
            for row in specs_table.find_all('tr'):
                key, value = row.find_all('td')
                spece[key.text.strip()] = value.text.strip()
            else:
                spece = None

                return {
                    'title': title,
                    'price': price,
                    'specification': specs
                } 
            
except requests.Exceptions.RequestException as e:
       print(f"Error scraping product: {e}")
       return None
