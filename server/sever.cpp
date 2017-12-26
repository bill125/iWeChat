#include "Server.h"
#include "User.h"
#include <sys/socket.h>
#include <cstdio>
#include <fstream>

using namespace std;

void Server::startService()
{
    puts("iWeChat server lauching ...");

    
    return ;
}

void Server::stopService()
{
    puts("iWeChat server shutting ...");



    return ;
}

void Server::loadUserList(std::string filename)
{
    ifstream fin("data/userlist");

    user_list.clear();
    while (!fin.eof()) {
        string username;
        fin >> username;
        user_list.push_back(username);
    }

    fin.close();

    return ;
}

User Server::loadUser(string username)
{
    // Set username
    User new_user;
    new_user.setUsername(username);

    vector<string> friend_list;
    string filename;
    string pattern;
    ifstream fin;

    // Load password
    filename = "data/" + username + "/passowrd";
    fin.open(filename.c_str());
    fin >> pattern;
    fin.close();
    new_user.setPassword(pattern);
    
    // Load friend list
    filename = "data/" + username + "/friends";
    fin.open(filename.c_str());
    friend_list.clear();
    while (!fin.eof) {
        fin >> pattern;
        friend_list.push_back(pattern);
    }
    fin.close();
    new_user.setFriendList(friend_list);

    return new_user;
}

void Server::saveUser(User user)
{
    vector<string> friend_list;
    string filename;
    string pattern;
    string username;
    ofstream fout;

    // Get username
    username = user.getUsername();

    // Load password
    filename = "data/" + username + "/passowrd";
    fout.open(filename.c_str());
    pattern = user.getPassword();
    fout << pattern << endl;
    fout.close();
    
    // Load friend list
    filename = "data/" + username + "/friends";
    fout.open(filename.c_str());
    friend_list = user.getFriendList();
    for (int i = 0; i < friend_list.size(); ++ i) {
        fout << friend_list[i] << endl;
    }
    fout.close();
}