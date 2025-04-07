# Use the official Python image from DockerHub
FROM python:3.9-slim

# Set the working directory
WORKDIR /app

# Copy all the project files into the container
COPY . .

# Install dependencies
RUN pip install -r requirements.txt

# Expose the port the app runs on
EXPOSE 5000

# Define environment variable
ENV FLASK_APP=app.py

# Run the application
CMD ["python", "app.py"]