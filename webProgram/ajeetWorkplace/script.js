const form = document.getElementById('url-form');
const urlInput = document.getElementById('product-url');
const submitBtn = document.getElementById('submit-btn');

function validateURL(url) {
  try {
    new URL(url);
    return true;
  } catch(err) {
    return false;
  }
}

form.addEventListener('submit', (e) => {
  e.preventDefault();
  const url = urlInput.value.trim();
  if (validateURL(url)) {
    // Send the URL to the backend using AJAX (e.g., fetch API)
    fetch('/scrape', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ url: url })
    })
    .then(response => response.json())
    .then(data => {
      // Handle the scraped product data from the backend response (e.g., display it on the page)
    })
    .catch(error => {
      console.error(error);
      alert('Error scraping product data.');
    });
  } else {
    alert('Invalid URL. Please enter a valid web address.');
  }
});