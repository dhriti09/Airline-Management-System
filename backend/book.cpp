#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>

using namespace std;

// Utility to parse GET parameters
string getParam(const string& data, const string& key) {
    size_t start = data.find(key + "=");
    if (start == string::npos) return "";
    start += key.length() + 1;
    size_t end = data.find("&", start);
    return data.substr(start, end - start);
}

// Generate random Customer ID
string generateCustomerID() {
    srand(time(0));
    int id = rand() % 1000000; // 6-digit ID
    return to_string(id);
}

// Map destination ID to name and charges
map<string, pair<string, int>> destinationMap = {
    {"1", {"Dubai", 10000}},
    {"2", {"India", 12000}},
    {"3", {"Canada", 15000}},
    {"4", {"UK", 14000}},
    {"5", {"USA", 16000}},
    {"6", {"Australia", 16000}},
    {"7", {"Africa", 13000}},
    {"8", {"China", 12000}},
    {"9", {"Japan", 11000}},
    {"10", {"Brazil", 17000}},
    {"11", {"Germany", 15000}},
    {"12", {"Europe", 15200}}
};

int main() {
    cout << "Content-type: text/html\n\n";

    string query = getenv("QUERY_STRING");

    string name = getParam(query, "name");
    string age = getParam(query, "age");
    string gender = getParam(query, "gender");
    string email = getParam(query, "email");
    string phone = getParam(query, "phone");
    string destinationID = getParam(query, "destination");
    string flight = getParam(query, "flight");

    string customerID = generateCustomerID();
    string destination = destinationMap[destinationID].first;
    int charges = destinationMap[destinationID].second;

    cout << "<!DOCTYPE html><html><head><title>Booking Confirmation</title><style>";

    // ✅ Updated CSS with nav ul li fix
    cout << "body{background:#000;color:#fff;font-family:sans-serif;margin:0;padding-top:80px}";
    cout << "nav{position:fixed;top:0;width:100%;background:#000;padding:15px 30px;display:flex;justify-content:space-between;align-items:center;border-bottom:1px solid #fff;z-index:1000}";
    cout << "nav .logo{color:#fff;font-size:1.5em;font-weight:bold}";
    cout << "nav ul{list-style:none;display:flex;gap:15px;margin:0}";
    cout << "nav ul li{display:inline-block}"; // ✅ Fix added here
    cout << "nav ul li a{color:#fff;text-decoration:none;font-size:1em;padding:5px 10px;border:1px solid transparent}";
    cout << "nav ul li a:hover{border:1px solid #fff}";
    cout << "h2{text-align:center;font-size:2.5em;color:#fff;border-bottom:2px solid #fff;padding-bottom:10px;animation:zoomNotice 1.5s ease-in-out infinite}";
    cout << "@keyframes zoomNotice{0%{transform:scale(1)}50%{transform:scale(1.1)}100%{transform:scale(1)}}";
    cout << ".ticket{background:#000;padding:30px;width:50%;margin:30px auto;border-radius:10px;border:1px solid #fff}";
    cout << "p{font-size:18px;margin:10px 0} .highlight{color:#fff;font-weight:bold;border-bottom:1px dashed #fff}";
    cout << "button{padding:10px 20px;background:#000;color:#fff;border:1px solid #fff;border-radius:5px;cursor:pointer;margin-top:20px}";
    cout << "button:hover{background:#fff;color:#000}";
    cout << "</style></head><body>";

    cout << "<nav><div class='logo'>XYZ Airlines</div><ul>";
   cout << "<li><a href='/airline/index.html'>Home</a></li>";
cout << "<li><a href='/airline/destinations.html'>Destinations</a></li>";
cout << "<li><a href='/airline/about.html'>About</a></li>";
cout << "<li><a href='/airline/contact.html'>Contact</a></li>";

    cout << "</ul></nav>";

    cout << "<h2>Your Ticket - XYZ Airlines</h2>";
    cout << "<div class='ticket'>";
    cout << "<p>Customer ID: <span class='highlight'>" << customerID << "</span></p>";
    cout << "<p>Name: " << name << "</p>";
    cout << "<p>Gender: " << gender << "</p>";
    cout << "<p>Age: " << age << "</p>";
    cout << "<p>Phone No: " << phone << "</p>";
    cout << "<p>Email: " << email << "</p>";
    cout << "<p>Flight: " << flight << "</p>";
    cout << "<p>Destination: " << destination << "</p>";
    cout << "<p>Charges: <span class='highlight'>Rs." << charges << "</span></p>";
    cout << "<br><p>Thank you for booking with XYZ Airlines!</p>";
    cout << "<button onclick='window.print()'>Print Ticket</button>";
    cout << "</div></body></html>";

    return 0;
}
