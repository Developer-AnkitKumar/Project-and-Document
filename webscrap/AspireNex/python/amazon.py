import requests
from bs4 import BeautifulSoup
import pandas as pd
import time
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# Scraping functions
def scrape_using_requests(search_query):
    url = f"https://www.amazon.com/s?k={search_query}"
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3"}
    response = requests.get(url, headers=headers)
    soup = BeautifulSoup(response.content, "html.parser")
    
    products = []
    
    for item in soup.select(".s-result-item"):
        title = item.select_one("h2 .a-link-normal")
        price = item.select_one(".a-price .a-offscreen")
        
        if title and price:
            products.append({
                "title": title.get_text(strip=True),
                "price": price.get_text(strip=True)
            })
    
    return products

def scrape_using_selenium(search_query):
    chrome_options = Options()
    chrome_options.add_argument("--headless")
    chrome_options.add_argument("--no-sandbox")
    chrome_options.add_argument("--disable-dev-shm-usage")
    
    driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=chrome_options)
    url = f"https://www.amazon.com/s?k={search_query}"
    driver.get(url)
    
    products = []
    
    try:
        WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.CSS_SELECTOR, ".s-main-slot")))
        
        items = driver.find_elements(By.CSS_SELECTOR, ".s-main-slot .s-result-item")
        
        for item in items:
            try:
                title_element = item.find_element(By.CSS_SELECTOR, "h2 .a-link-normal")
                price_element = item.find_element(By.CSS_SELECTOR, ".a-price .a-offscreen")
                
                title = title_element.text
                price = price_element.text
                
                products.append({
                    "title": title,
                    "price": price
                })
            except Exception as e:
                print(f"Error scraping item: {e}")
                
    finally:
        driver.quit()
    
    return products
def scrape_amazon(search_query, use_selenium=False):
    if use_selenium:
        return scrape_using_selenium(search_query)
    else:
        return scrape_using_requests(search_query)
# Main execution
if __name__ == "__main__":
    search_query = "laptop"
    
    # Using Requests and BeautifulSoup
    print("Scraping using Requests and BeautifulSoup...")
    products_bs = scrape_using_requests(search_query)
    df_bs = pd.DataFrame(products_bs)
    print(f"Scraped {len(products_bs)} products from Amazon with Requests.")
    print(df_bs)
    
    # Using Selenium
    print("Scraping using Selenium...")
    products_selenium = scrape_using_selenium(search_query)
    df_selenium = pd.DataFrame(products_selenium)
    print(f"Scraped {len(products_selenium)} products from Amazon with Selenium.")
    print(df_selenium)
