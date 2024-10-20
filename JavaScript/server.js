const http = require("http");

// Create a server object
const server = http.createServer((req, res) => {
  // Set the response HTTP header with status and content type
  res.writeHead(200, { "Content-Type": "text/plain" });

  // Send the response body as "Hello World"
  res.end("Hello World! Welcome to my server.\n");
});

// The server listens on port 3000
server.listen(3000, () => {
  console.log("Server is running at http://localhost:3000/");
});
