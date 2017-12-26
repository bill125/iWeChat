#include "User.h"

void User::setUsername(std::string _username)
{
    username = _username;
}

std::string User::getUsername()
{
    return username;
}

void User::setPassword(std::string _password)
{
    password = _password;
}

bool User::checkPassword(std::string _password)
{
    return password == _password;
}

std::string User::getPassword()
{
    return password;
}

void User::setFriendList(std::vector<std::string> & _friendList)
{
    friendList = _friendList;
}

bool User::addFriend(std::string username)
{
    for (int i = friend_list.size() - 1; i >= 0; -- i) {
        if (friend_list[i] == username) {
            return false;
        }    
    }

    friend_list.push_back(username);
    return true;
}
    
std::vector<std::string> User::getFriendList()
{
    return friend_list;
}
