// UserManager.h
#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "UserInfo.h"

class UserManager {
public:
    void Load();
    void Save();
    const std::vector<UserInfo>& GetUsers() const;
    void AddUser(const UserInfo& user);
    void DeleteUser(size_t index);

private:
    std::vector<UserInfo> users;
};

#endif