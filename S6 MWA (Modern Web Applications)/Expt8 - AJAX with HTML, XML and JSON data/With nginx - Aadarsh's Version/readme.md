# Literally copy pasted from Aadarsh's github. All credit goes to him.

# Question

Write a program using AJAX to retrieve Book title, Author and Price with HTML, XML and JSON data

# Solution

- index.html
- books.html
- books.xml
- books.json

# Installing NGINX FOR WINDOWS

1. **Download Nginx**: Visit the [official Nginx website](https://nginx.org/en/download.html) and download the Windows version of Nginx.
2. **Extract Files**: Extract the downloaded Nginx files to a directory of your choice.
3. **Configuration**: Edit the `nginx.conf` file located in the `conf` directory to configure Nginx according to your requirements. Find the http block in the nginx.conf file. Inside this block, you'll see a server block. Ensure location root is set to html folder of nginx folder that came upon downloading nginx and index filename is index.html(or just don't do anything - ignore this to be safe).
4. **Files**: Make sure all the HTML, XML, and JSON files are in the html folder of nginx folder
5. **Start Nginx**: Open a command prompt with administrative privileges, navigate to the directory where Nginx is installed, and run `nginx.exe`.
   When navigating to directory use forward slashes for example= C:/path/to/your/files
6. **Run Website**: Open your web browser and navigate to http://localhost to view your HTML page.
7. **Stop Nginx**: To stop Nginx, press `Ctrl + C` in the command prompt where Nginx is running.

## Additional Resources

- [Nginx Documentation](https://nginx.org/en/docs/): Official documentation for Nginx.
- [Nginx Beginner&#39;s Guide](https://www.nginx.com/resources/wiki/start/): A comprehensive guide for beginners to get started with Nginx.
