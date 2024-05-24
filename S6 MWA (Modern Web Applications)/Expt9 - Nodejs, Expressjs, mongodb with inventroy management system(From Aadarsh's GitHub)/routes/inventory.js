const express = require('express');
const router = express.Router();
const InventoryItem = require('../models/InventoryItem');

// Create a new inventory item
router.post('/', async (req, res) => {
  try {
    const { name, quantity } = req.body;
    const newItem = new InventoryItem({ name, quantity });
    await newItem.save();
    res.redirect('/');
  } catch (err) {
    res.status(400).json({ message: err.message });
  }
});

// Get all inventory items
router.get('/', async (req, res) => {
  try {
    const items = await InventoryItem.find();
    res.json(items);
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
});

// Update an inventory item
router.patch('/:id', async (req, res) => {
  try {
    const { name, quantity } = req.body;
    const item = await InventoryItem.findById(req.params.id);
    if (name) item.name = name;
    if (quantity) item.quantity = quantity;
    await item.save();
    res.redirect('/');
  } catch (err) {
    res.status(400).json({ message: err.message });
  }
});

// Delete an inventory item
router.delete('/:id', async (req, res) => {
  try {
    await InventoryItem.findByIdAndDelete(req.params.id);
    res.redirect('/');
  } catch (err) {
    res.status(500).json({ message: err.message });
  }
});

module.exports = router;
