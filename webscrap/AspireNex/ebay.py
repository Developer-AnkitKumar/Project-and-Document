from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from webdriver_manager.chrome import ChromeDriverManager
from urllib.parse import quote_plus
import random
import time

USER_AGENTS = [
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:91.0) Gecko/20100101 Firefox/91.0",
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/14.1.2 Safari/605.1.15",
    # Add more user agents as needed
]

def format_price(price_str):
    # Implement your price formatting logic here
    return price_str.strip()  # Example: Remove leading/trailing whitespace

def scrape_ebay(query):
    search_query = quote_plus(query)
    url = f"https://www.ebay.com/sch/i.html?_nkw={search_query}"

    # Configure Selenium WebDriver
    options = Options()
    options.add_argument("--headless")  # Run Chrome in headless mode (no GUI)
    options.add_argument("--no-sandbox")
    options.add_argument("--disable-dev-shm-usage")
    options.add_argument(f"user-agent={random.choice(USER_AGENTS)}")

    # Initialize WebDriver
    driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)
    
    driver.get(url)
    time.sleep(random.uniform(1, 5))  # Random delay between 1 to 5 seconds

    products = []
    items = driver.find_elements(By.CSS_SELECTOR, '.s-item')

    for item in items:
        try:
            title_elem = item.find_element(By.CSS_SELECTOR, '.s-item__title')
            price_elem = item.find_element(By.CSS_SELECTOR, '.s-item__price')
            link_elem = item.find_element(By.CSS_SELECTOR, '.s-item__link')

            if title_elem and price_elem and link_elem:
                products.append({
                    'title': title_elem.text.strip(),
                    'price': format_price(price_elem.text.strip()),
                    'link': link_elem.get_attribute('href')
                })
        except Exception as e:
            print(f"Error scraping item: {e}")
            continue

    driver.quit()
    print(f"Scraped {len(products)} products from eBay with Selenium.")
    return products

# Main function to execute the scraping
if __name__ == "__main__":
    query = input("Enter search query: ").strip()
    
    while not query:
        print("Query cannot be empty. Please enter a valid search query.")
        query = input("Enter search query: ").strip()
    
    products = scrape_ebay(query)
    
    if products:
        for product in products:
            print(f"Title: {product['title']}")
            print(f"Price: {product['price']}")
            print(f"Link: {product['link']}")
            print("=" * 50)
    else:
        print(f"No products found for query: {query}")
