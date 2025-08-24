🛫 Airline Management System

A modular, class-based Airline Management System built using **C++ (CGI)** for backend logic and a vibrant, responsive **HTML/CSS/JS** frontend. Designed to simulate core airline operations like booking ,flight management.


 🚀 Features

- ✈️ Flight booking 
- 👤 Passenger details and ticket generation  
- 🧮 Backend logic in C++ using class-based structure  
- 🌐 CGI integration with Apache/XAMPP  
- 🎨 Rich, glowing UI with Font Awesome icons and gradients  
- 📱 Responsive design for desktop 




 ⚙️ Setup Instructions

 1. Install XAMPP or Apache
Make sure CGI is enabled in your server config.

 2. Place Files in `htdocs`
Copy the repo into your `htdocs` folder (or configured web root).

 3. Configure CGI
Enable `.cgi` or `.exe` execution for C++ backend:
```apache
ScriptAlias /cgi-bin/ "C:/xampp/cgi-bin/"
AddHandler cgi-script .cgi .exe
Options +ExecCGI
```

 4. Compile C++ Code
Use `g++` to compile:
```bash
g++ book.cpp -o book.cgi
```

5. Run Locally
Visit `http://localhost/pages/index.html` to start using the system.

 
 📌 Notes

- Backend is written in C++ for performance and control  
- Frontend is styled with glowing effects and icon-rich layout  
- Designed for educational and demo purposes

