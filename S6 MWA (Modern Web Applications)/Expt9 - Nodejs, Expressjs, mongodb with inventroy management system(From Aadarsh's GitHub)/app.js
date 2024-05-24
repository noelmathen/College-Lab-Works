const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');
const inventoryRouter = require('./routes/inventory');

const app = express();
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

// Connect to MongoDB
mongoose.connect('mongodb://localhost/inventory', { useNewUrlParser: true, useUnifiedTopology: true });
const db = mongoose.connection;
db.on('error', console.error.bind(console, 'connection error:'));
db.once('open', () => console.log('Connected to MongoDB'));

// Set up static files
app.use(express.static('public'));

// Routes
app.use('/inventory', inventoryRouter);

// Root route handler
app.get('/', (req, res) => {
  res.sendFile(__dirname + '/public/index.html');
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});
