void loginFunc(const Request& req, Response& res) {
    res.set_content("Login", "text/html");
}

void registerFunc(const Request& req, Response& res) {
    res.
}

void setEndpoints(SSLServer& svr) {
    try {
        svr.Get("/login", [&](const Request& req, Response& res) {

            loginFunc(req, res);
        });
        svr.Get("/register", [&](const Request& req, Response& res) {

            registerFunc(req, res);
        });
    } catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
