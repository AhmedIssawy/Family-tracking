### FAMILY TRACKER
![image](https://github.com/user-attachments/assets/2915f8c9-ad42-421b-b598-95f576ae9c8d)

A simple Express.js application that tracks the countries visited by users. The app stores user data and country information using PostgreSQL.
  
## Features 

- Users can create profiles with custom colors.
- Users can select a country and add it to their visited list.
- Displays the total number of visited countries.
- Users can switch between profiles and view their visited countries.

![image](https://github.com/user-attachments/assets/095dda9e-a78f-49ed-9bfd-39483f83ab82)


## Technologies Used

- **Node.js**: JavaScript runtime for building the backend.
- **Express.js**: Web framework for routing and handling HTTP requests.
- **PostgreSQL**: Database for storing users and country data.
- **EJS**: Template engine for rendering dynamic HTML views.
- **Body-Parser**: Middleware to parse incoming request bodies.

## Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/travel-tracker.git
   cd travel-tracker
   npm i
   ```
2. Make a postgres DB called "world" and paste this in the query
3. Setup .env (make file called ".env" and write your postgres db information inside in this stracture:
4. ```
   DB_USER=
   
   DB_HOST=localhost
   
   DB_NAME=
   
   DB_PASSWORD=
   
   DB_PORT=
   ```


4.  Write these commands in PGADMIN query to create your own tables after making your DB and putting its name in DB_NAME in .env:
    ``` 
    DROP TABLE IF EXISTS visited_countries, users;
    CREATE TABLE users(
    id SERIAL PRIMARY KEY,
    name VARCHAR(15) UNIQUE NOT NULL,
    color VARCHAR(15)
    );
  
    CREATE TABLE visited_countries(
    id SERIAL PRIMARY KEY,
    country_code CHAR(2) NOT NULL,
    user_id INTEGER REFERENCES users(id)
    );
  
    INSERT INTO users (name, color)
    VALUES ('Angela', 'teal'), ('Jack', 'powderblue');
  
    INSERT INTO visited_countries (country_code, user_id)
    VALUES ('FR', 1), ('GB', 1), ('CA', 2), ('FR', 2 );
  
    SELECT *
    FROM visited_countries
    JOIN users
    ON users.id = user_id;
    ```

### Run the project 
```
node index.js
```

  
   
       
