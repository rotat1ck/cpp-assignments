#include "../header/includes.h"

#include "dbContoller.cpp"

Database db("users.db", OPEN_READWRITE|OPEN_CREATE);

void logRequest(const Request& req, Response& res) {
    cout << "["<< req.method <<"] " << "[" << res.status << "] " << 
    "Request by " << req.remote_addr << " to " << req.target << endl;
}

void loginFunc(const Request& req, Response& res) {
    try {
        if (req.has_param("username") && req.has_param("pass")) {
            string username = req.get_param_value("username");
            string pass = req.get_param_value("pass");
            try {
                dbSelectUser(db, username, pass);
                res.status = 200;
                res.set_content("Successful login", "json");
            } catch (const exception& ex) {
                res.status = 404;
                res.set_content("User not found", "json");
            }
        } else {
            res.status = 400;
            res.set_content("Invalid request", "json");
        }
    } catch (const exception& ex) {
        res.status = 503;
        res.set_content("Request failed", "json");
    }

}

void registerFunc(const Request& req, Response& res) {
    try {
        if (req.has_param("username") && req.has_param("pass") && req.has_param("email")) {
            string username = req.get_param_value("username");
            string pass = req.get_param_value("pass");
            string email = req.get_param_value("email");
            try {
                if (dbDoesUserExist(db, username, email)) {
                    res.status = 400;
                    res.set_content("User with this username or email already exists", "json");
                }
            } catch (const SQLite::Exception& ex) {
                dbCreateUser(db, username, pass, email);
                res.status = 200;
                res.set_content("User created", "json");
            } catch (const exception& ex) {
                res.status = 503;
                res.set_content("Request failed", "json");
            }
        } else {
            res.status = 400;
            res.set_content("Invalid request", "json");
        }
    } catch (const exception& ex) {
        res.status = 503;
        res.set_content("Request failed", "json");
    }
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
    } catch (const std::exception& ex) {
        cout << "Error: " << ex.what() << endl;
    }
}
