# Question
Design a Node.js application for managing a simple inventory system. Implement CRUD operations (Create, Read, Update, Delete) for the inventory items using Express.js as the web framework and MongoDB as the database. Your application should allow users to:Create new inventory items with fields for name and quantity.Retrieve a list of all inventory items.Update the details (name and/or quantity) of an existing inventory item.Delete an inventory item

# Steps
* Install node.js [Node.js — Download Node.js® (nodejs.org)](https://nodejs.org/en/download/)
* * Install mongosh shell [MongoDB Shell Download | MongoDB](https://www.mongodb.com/try/download/shell)
  * Install mongo db community server, including compass
  * 
* Install pacakges....npm install mongoose express body-parser

* Start server in the directory

```bash
node app.js
```

* Access webpage using localhost:3000
* To access the JSON data in mongosh shell

```bash
 use inventory
 db.inventoryitems.find()
```

# Output

### normal
![normal](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20MWA%20(Modern%20Web%20Applications)/Expt9%20-%20Nodejs%2C%20Expressjs%2C%20mongodb%20with%20inventroy%20management%20system(From%20Aadarsh's%20GitHub)/Outputs/1_normal.PNG)

### add 1
![add 1](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20MWA%20(Modern%20Web%20Applications)/Expt9%20-%20Nodejs%2C%20Expressjs%2C%20mongodb%20with%20inventroy%20management%20system(From%20Aadarsh's%20GitHub)/Outputs/2_add.PNG)

### add 2
![add 2](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20MWA%20(Modern%20Web%20Applications)/Expt9%20-%20Nodejs%2C%20Expressjs%2C%20mongodb%20with%20inventroy%20management%20system(From%20Aadarsh's%20GitHub)/Outputs/3_add.PNG)

### update 1
![update 1](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20MWA%20(Modern%20Web%20Applications)/Expt9%20-%20Nodejs%2C%20Expressjs%2C%20mongodb%20with%20inventroy%20management%20system(From%20Aadarsh's%20GitHub)/Outputs/4_update.PNG)

### update 2
![update 2](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20MWA%20(Modern%20Web%20Applications)/Expt9%20-%20Nodejs%2C%20Expressjs%2C%20mongodb%20with%20inventroy%20management%20system(From%20Aadarsh's%20GitHub)/Outputs/5_update.PNG)

### update 3
![update 3](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20MWA%20(Modern%20Web%20Applications)/Expt9%20-%20Nodejs%2C%20Expressjs%2C%20mongodb%20with%20inventroy%20management%20system(From%20Aadarsh's%20GitHub)/Outputs/6_update.PNG)

### delete 1
![delete 1](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20MWA%20(Modern%20Web%20Applications)/Expt9%20-%20Nodejs%2C%20Expressjs%2C%20mongodb%20with%20inventroy%20management%20system(From%20Aadarsh's%20GitHub)/Outputs/7_delete.PNG)

### delete 2
![delete 2](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20MWA%20(Modern%20Web%20Applications)/Expt9%20-%20Nodejs%2C%20Expressjs%2C%20mongodb%20with%20inventroy%20management%20system(From%20Aadarsh's%20GitHub)/Outputs/8_delete.PNG)

### mongo
![mongo](https://github.com/noelmathen/College-Lab-Works/blob/main/S6%20MWA%20(Modern%20Web%20Applications)/Expt9%20-%20Nodejs%2C%20Expressjs%2C%20mongodb%20with%20inventroy%20management%20system(From%20Aadarsh's%20GitHub)/Outputs/9_mongo.PNG)
