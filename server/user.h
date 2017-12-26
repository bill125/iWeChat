#ifndef USER_H_
#define USER_H_

#include <vector>
#include <string>

class User
{
public:
    User() {}
    void setUsername(std::string _username);
    std::string getUsername();
    void setPassword(std::string _password);
    bool checkPassword(std::string _password);
    std::string getPassword();
    void setFriendList(std::vector<std::string> & _friendList);
    bool addFriend(std::string username);
    std::vector<std::string> getFriendList();

protected:
    std::string username;
    std::string password;
    std::vector<std::string> friend_list;
};

#endif