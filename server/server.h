#ifndef SERVER_H_
#define SERVER_H_

#include <vector>
#include <string>

class Server
{
public:
    Server() {}
    void startService();
    void stopService();
protected:
    void loadUserList(std::string filename);
    bool checkUserInList(std::string username);
    User loadUser(string username);
    void saveUser(User user);

    std::vector<std::string> user_list;
};

#endif