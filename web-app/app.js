const express = require('express');
const mysql = require('mysql2');
const expressLayouts = require('express-ejs-layouts');
require('dotenv').config(); // Load environment variables
const fs = require('fs');

const app = express();

// MySQL Database connection
const db = mysql.createConnection({
    host: process.env.DB_HOST,
    user: process.env.DB_USER,
    password: process.env.DB_PASS,
    database: process.env.DB_NAME
});

db.connect((err) => {
    if (err) {
        throw err;
    }
    console.log('Connected to database');
});

// Middleware
app.use(express.urlencoded({ extended: true }));
app.set('view engine', 'ejs');
app.use(expressLayouts);

// Route to fetch data and save to a local file (e.g., CSV)
app.get('/export', (req, res) => {
    let sql = 'SELECT * FROM users';
    db.query(sql, (err, results) => {
        if (err) throw err;

        // Convert the data into tab-delimited format
        let tabDelimited = 'ID\tName\t\tEmail\n';
        results.forEach((user) => {
            tabDelimited += `${user.id}\t${user.name.trim()}\t\t${user.email.trim()}\n`;
        });

        // Write the tab-delimited data to a file
        fs.writeFile('users.tsv', tabDelimited, (err) => {
            if (err) throw err;
            console.log('Data saved to users.tsv');
        });
        res.send('Data exported to users.tsv');
    });
});

// Route to display users
app.get('/', (req, res) => {
    let sql = 'SELECT * FROM users';
    db.query(sql, (err, results) => {
        if (err) throw err;
        res.render('index', { users: results });
    });
});

// Route to add a new user
app.post('/add', (req, res) => {
    let user = { name: req.body.name, email: req.body.email };
    let sql = 'INSERT INTO users SET ?';
    db.query(sql, user, (err) => {
        if (err) throw err;
        res.redirect('/');
    });
});

// Route to update a user
app.post('/edit/:id', (req, res) => {
    let sql = 'UPDATE users SET name = ?, email = ? WHERE id = ?';
    db.query(sql, [req.body.name, req.body.email, req.params.id], (err) => {
        if (err) throw err;
        res.redirect('/');
    });
});

// Route to delete a user
app.get('/delete/:id', (req, res) => {
    let sql = 'DELETE FROM users WHERE id = ?';
    db.query(sql, [req.params.id], (err) => {
        if (err) throw err;
        res.redirect('/');
    });
});

// Start Server
app.listen(3000, () => {
    console.log('Server running on http://localhost:3000');
});

