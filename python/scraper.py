from flask import Flask, request, jsonify
import requests
from bs4 import BeautifulSoup

app = Flask(__name__)

@app.route('/', methods=['GET'])
def index():
    return "Welcome to the Multi-E-commerce Product Scraper API!"

@app.route('/scrape', methods=['POST'])
def scrape():
    data = request.json
    url = data.get('url')
    site = data.get('site')  # The site to scrape, e.g., 'amazon', 'flipkart', 'myntra'

    if not url or not site:
        return jsonify({'error': 'URL and site are required'}), 400

    try:
        if site == 'amazon':
            result = scrape_amazon(url)
        elif site == 'flipkart':
            result = scrape_flipkart(url)
        elif site == 'myntra':
            result = scrape_myntra(url)
        else:
            return jsonify({'error': 'Unsupported site'}), 400

        if result:
            return jsonify(result)
        else:
            return jsonify({'error': 'Failed to scrape product data'}), 400
    except Exception as e:
        return jsonify({'error': str(e)}), 500

# Amazon Scraping Function
def scrape_amazon(url):
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    }
    response = requests.get(url, headers=headers)
    if response.status_code == 200:
        soup = BeautifulSoup(response.content, 'html.parser')
        title = soup.find('span', {'id': 'productTitle'}).text.strip()
        price = soup.find('span', {'id': 'priceblock_ourprice'}).text.strip()
        description = soup.find('div', {'id': 'productDescription'}).text.strip() if soup.find('div', {'id': 'productDescription'}) else 'No description available'
        image_url = soup.find('img', {'id': 'imgBlkFront'})['src']

        return {
            'title': title,
            'price': price,
            'description': description,
            'image_url': image_url
        }
    return None

# Flipkart Scraping Function
def scrape_flipkart(url):
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    }
    response = requests.get(url, headers=headers)
    if response.status_code == 200:
        soup = BeautifulSoup(response.content, 'html.parser')
        title = soup.find('span', {'class': 'B_NuCI'}).text.strip()
        price = soup.find('div', {'class': '_30jeq3'}).text.strip()
        description = soup.find('div', {'class': '_1AtVbE'}).text.strip() if soup.find('div', {'class': '_1AtVbE'}) else 'No description available'
        image_url = soup.find('img', {'class': '_396cs4'})['src']

        return {
            'title': title,
            'price': price,
            'description': description,
            'image_url': image_url
        }
    return None

# Myntra Scraping Function
def scrape_myntra(url):
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    }
    response = requests.get(url, headers=headers)
    if response.status_code == 200:
        soup = BeautifulSoup(response.content, 'html.parser')
        title = soup.find('h1', {'class': 'pdp-title'}).text.strip()
        price = soup.find('span', {'class': 'pdp-price'}).text.strip()
        description = soup.find('div', {'class': 'pdp-description'}).text.strip() if soup.find('div', {'class': 'pdp-description'}) else 'No description available'
        image_url = soup.find('img', {'class': 'pdp-productImage'})['src']

        return {
            'title': title,
            'price': price,
            'description': description,
            'image_url': image_url
        }
    return None

if __name__ == '__main__':
    app.run(debug=True)
