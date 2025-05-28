// UserManager.cpp
#include "UserManager.h"
#include <pqxx/pqxx>
#include <iostream>

using namespace pqxx;
using namespace std;

// Temporary database string, will be moved later or passed in
extern string DataBaseAddress;

void UserManager::Load() {
    try {
        connection conn(DataBaseAddress);

        if (conn.is_open()) {
            cout << "Connected to the database successfully." << endl;
            work txn(conn);
            result res = txn.exec("SELECT username, password, security_question, security_answer, last_sign_in, entry_count FROM users;");

            users.clear();
            for (const auto& row : res) {
                UserInfo user;
                user.SetUsername(row["username"].c_str());
                user.SetPassword(row["password"].c_str());
                user.SetSecurityQuestion(row["security_question"].c_str());
                user.SetSecurityAnswer(row["security_answer"].c_str());
                user.SetLastSignIn(row["last_sign_in"].c_str());
                user.SetEntryCount(row["entry_count"].as<int>());
                users.push_back(user);
            }
        } else {
            cout << "Can't open the database." << endl;
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

void UserManager::Save() {
    try {
        connection conn(DataBaseAddress);

        if (conn.is_open()) {
            work txn(conn);
            for (const auto& user : users) {
                string sql = "INSERT INTO users (username, password, security_question, security_answer, last_sign_in, entry_count) VALUES (" +
                             txn.quote(user.GetUsername()) + ", " +
                             txn.quote(user.GetPassword()) + ", " +
                             txn.quote(user.GetSecurityQuestion()) + ", " +
                             txn.quote(user.GetSecurityAnswer()) + ", " +
                             txn.quote(user.GetLastSignIn()) + ", " +
                             to_string(user.GetEntryCount()) +
                             ") ON CONFLICT (username) DO UPDATE SET " +
                             "password = EXCLUDED.password, " +
                             "security_question = EXCLUDED.security_question, " +
                             "security_answer = EXCLUDED.security_answer, " +
                             "last_sign_in = EXCLUDED.last_sign_in, " +
                             "entry_count = EXCLUDED.entry_count;";
                txn.exec(sql);
            }
            txn.commit();
            cout << "Users saved to the database successfully." << endl;
        } else {
            cout << "Can't open the database." << endl;
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

const std::vector<UserInfo>& UserManager::GetUsers() const {
    return users;
}

void UserManager::AddUser(const UserInfo& user) {
    users.push_back(user);
}

void UserManager::DeleteUser(size_t index) {
    if (index < users.size()) {
        users.erase(users.begin() + index);
    }
}
