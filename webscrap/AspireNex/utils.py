# scraper/utils.py

def format_price(price_str):
    """
    Utility function to format the price string.
    For example, it can remove unwanted characters or convert the price to a float.
    """
    return price_str.replace('$', '').replace(',', '').strip()

def validate_query(query):
    """
    Utility function to validate the search query.
    """
    if not query:
        return False, "Query cannot be empty"
    if len(query) < 3:
        return False, "Query should be at least 3 characters long"
    return True, ""
