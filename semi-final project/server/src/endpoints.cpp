#include "../header/includes.h"

void logRequest(const Request& req, Response& res) {
    cout << "["<< req.method <<"] " << "[" << res.status << "] " << 
    "Request by " << req.remote_addr << " to " << req.target << endl;
}

void loginFunc(const Request& req, Response& res) {
    try {
        if (req.has_param("username") && req.has_param("pass")) {
            string username = req.get_param_value("username");
            string password = req.get_param_value("password");
            res.status = 200;
        } else {
            res.status = 400;
            res.set_content("Invalid request", "json");
        }
    } catch (const exception& e) {
        res.status = 503;
        res.set_content("Request failed", "json");
    }

}

void registerFunc(const Request& req, Response& res) {
    res.set_content("Register", "text/html");
}

void setEndpoints(SSLServer& svr) {
    try {
        svr.Get("/login", [&](const Request& req, Response& res) {
            loginFunc(req, res);
            logRequest(req, res);
        });
        svr.Post("/register", [&](const Request& req, Response& res) {
            registerFunc(req, res);
            logRequest(req, res);
        });
    } catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
