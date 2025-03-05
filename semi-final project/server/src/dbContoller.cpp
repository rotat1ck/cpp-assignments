#include "../header/includes.h"

string dbSelectUser(Database& db ,string username, string pass) {
    Transaction transaction(db);
    Statement query {db, "SELECT user_id FROM users WHERE username = ? AND pass_hash = ?"};
    query.bind(1, username);
    query.bind(2, pass);

    query.executeStep();
    return query.getColumn(0);
}

string dbCreateUser(string username, string pass) {

}