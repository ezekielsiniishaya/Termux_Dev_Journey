const express = require("express");
const path = require("path");
const bodyParser = require("body-parser");
const app = express();
const port = 5000;

// Middleware to parse form data
app.use(bodyParser.urlencoded({ extended: true }));

// Serve static files from the "public" folder
app.use(express.static("public"));

// Route to serve the index.html file
app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "public", "index.html"));
});

// Route to serve the forms.html file
app.get("/forms", (req, res) => {
  res.sendFile(path.join(__dirname, "public", "forms.html"));
});

// Route to handle form submission and send JSON response
app.post("/submit", (req, res) => {
  const name = req.body.name; // Get the name from the form
  const email = req.body.email; // Get the email from the form

  // Create a JSON object
  const response = {
    success: true,
    message: "Data received successfully",
    data: {
      name: name,
      email: email,
    },
  };

  // Log the JSON response to the console
  console.log("Form Submission Data:", JSON.stringify(response, null, 2));

  // Send a user-friendly response to the browser
  res.send(
    `<h1>Thank you!</h1><p>Your name: ${name}</p><p>Your email: ${email}</p>`
  );
});

// Route to serve the video file
app.get("/video", (req, res) => {
  const videoPath =
    "C:\\Users\\Ezekiel\\Downloads\\Malcolm_In_The_Middle_-_S4_-_E13_a1e7aab4f15430eccd932e2fcb716bf0.mp4";

  res.sendFile(videoPath, (err) => {
    if (err) {
      console.error("File not found:", err);
      res.status(err.status).end(); // Handle the error appropriately
    }
  });
});

// Start the server
app.listen(port, () => {
  console.log(`Express app listening at http://localhost:${port}`);
});
