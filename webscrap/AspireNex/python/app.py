from flask import Flask, render_template, request
from AspireNex.python.amazon import scrape_amazon
from AspireNex.ebay import scrape_ebay

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/results', methods=['POST'])
def results():
    query = request.form['query']
    amazon_products = scrape_amazon(query)
    ebay_products = scrape_ebay(query)
    return render_template('results.html', query=query, amazon_products=amazon_products, ebay_products=ebay_products)

if __name__ == '__main__':
    app.run(debug=True)
