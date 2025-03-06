#include "../header/includes.h"

bool dbDoesUserExist(Database& db, string username, string email) {
    Transaction transaction(db);
    Statement query {db, "SELECT user_id FROM users WHERE username = ? OR email = ?"};
    query.bind(1, username);
    query.bind(2, email);

    query.executeStep();
    return query.getColumn(0) != " ";
}

string dbSelectUser(Database& db ,string username, string pass) {
    Transaction transaction(db);
    Statement query {db, "SELECT user_id FROM users WHERE username = ? AND pass_hash = ? OR email = ? AND pass_hash = ?"};
    query.bind(1, username);
    query.bind(2, pass);
    query.bind(3, username);
    query.bind(4, pass);

    query.executeStep();
    return query.getColumn(0);
}

void dbCreateUser(Database& db ,string username, string pass, string email) {
    Transaction transaction(db);
    Statement query {db, "INSERT INTO users(username, pass_hash, email) VALUES (?, ?, ?)"};
    query.bind(1, username);
    query.bind(2, pass);
    query.bind(3, email);

    query.exec();
    transaction.commit();
}