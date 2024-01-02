# Hash Table Strategies Implementation Project

This project showcases the implementation of various hash table strategies using the BankData class. The strategies covered include Chaining, Linear Probing, Quadratic Probing, Cubic Probing, and a Competitive Part where i have devised my own optimized strategies.

## Project Overview

In the BankData class, two vectors, `bankStorage1d` and `bankStorage2d`, play crucial roles in different strategies. `bankStorage2d` facilitates the Chaining strategy, while `bankStorage1d` serves probing strategies. The primary goal is to implement efficient hash table strategies, adept at handling collisions, and ensuring organized data storage.

## Functions Implemented

The project involves the implementation of essential functions within the BankData class:

1. `void createAccount(string id, int count)`: Creates a new account with a unique id and an initial balance.

2. `vector<int> getTopK(int k)`: Retrieves the top k balance values from the database.

3. `int getBalance(string id)`: Returns the current balance of the account identified by the provided id.

4. `void addTransaction(string id, int count)`: Adds a transaction of count value to the specified account.

5. `bool doesExist(string id)`: Checks if an account with the given id exists in the database.

6. `int databaseSize()`: Returns the total number of accounts currently stored in the database.

7. `int hash(string id)`: Computes the hash value for the given id, used within the implemented strategies.

8. `bool delete(string id)`: Deletes the key stored in the database.

## Implemented Strategies

### 3.1 Chaining 
Chaining involves creating linked lists at each hash table index to manage collisions, ensuring organized and accessible data.

### 3.2 Linear Probing 
Linear Probing navigates hash table slots linearly to find the next available space when a collision occurs, emphasizing proximity.

### 3.3 Quadratic Probing 
Quadratic Probing introduces a sophisticated approach using quadratic increments to find the next available slot.

### 3.4 Cubic Probing 
Cubic Probing employs cubic increments to search for open slots, aiming to distribute data evenly and mitigate clustering.

### 3.5 Competitive Part 
