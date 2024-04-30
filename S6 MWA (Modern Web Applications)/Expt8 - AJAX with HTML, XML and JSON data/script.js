document.addEventListener("DOMContentLoaded", function() {
    var xhr = new XMLHttpRequest();
    var urlHTML = "bookInfo.html";
    var urlXML = "bookInfo.xml";
    var urlJSON = "bookInfo.json";
    var bookInfoHTML = "";
    var bookInfoXML = "";
    var bookInfoJSON = "";
  
    // Load HTML data
    xhr.open("GET", urlHTML, true);
    xhr.onreadystatechange = function() {
      if (xhr.readyState === 4 && xhr.status === 200) {
        bookInfoHTML = xhr.responseText;
        displayBookInfo();
      }
    };
    xhr.send();
  
    // Load XML data
    xhr.open("GET", urlXML, true);
    xhr.onreadystatechange = function() {
      if (xhr.readyState === 4 && xhr.status === 200) {
        var xmlDoc = xhr.responseXML;
        var title = xmlDoc.getElementsByTagName("title")[0].childNodes[0].nodeValue;
        var author = xmlDoc.getElementsByTagName("author")[0].childNodes[0].nodeValue;
        var price = xmlDoc.getElementsByTagName("price")[0].childNodes[0].nodeValue;
        bookInfoXML = "<h2>XML Data:</h2>";
        bookInfoXML += "<p>Title: " + title + "</p>";
        bookInfoXML += "<p>Author: " + author + "</p>";
        bookInfoXML += "<p>Price: " + price + "</p>";
        displayBookInfo();
      }
    };
    xhr.send();
  
    // Load JSON data
    xhr.open("GET", urlJSON, true);
    xhr.onreadystatechange = function() {
      if (xhr.readyState === 4 && xhr.status === 200) {
        var jsonData = JSON.parse(xhr.responseText);
        bookInfoJSON = "<h2>JSON Data:</h2>";
        bookInfoJSON += "<p>Title: " + jsonData.title + "</p>";
        bookInfoJSON += "<p>Author: " + jsonData.author + "</p>";
        bookInfoJSON += "<p>Price: " + jsonData.price + "</p>";
        displayBookInfo();
      }
    };
    xhr.send();
  
    // Function to display book information
    function displayBookInfo() {
      if (bookInfoHTML && bookInfoXML && bookInfoJSON) {
        document.getElementById("bookInfo").innerHTML = bookInfoHTML + bookInfoXML + bookInfoJSON;
      }
    }
  });
  