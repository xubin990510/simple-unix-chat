/*
Copyright (C) 2013 Braden Walters
This file is licensed under the MIT Expat License. See LICENSE.txt.
*/

#ifndef CHATROOM_HPP
#define CHATROOM_HPP

#include <string>
#include <list>
#include "Connection.hpp"

class ChatRoom;

struct SendMessageInfo
{
  SendMessageInfo() : new_chatroom(NULL), quit(false), switch_chat_dir(0)
  {
  }

  ChatRoom* new_chatroom; //New chatroom generated by message.
  bool quit; //Quit the client
  int switch_chat_dir; //Switch to previous (-1) or next (1) chat. If none, 0.
};

class ChatRoom
{
  public:
    ChatRoom();
    ChatRoom(Connection* server);
    ~ChatRoom();
    SendMessageInfo sendMessage(std::string& message);
    void addHistory(std::string& to_history);
    const std::list<std::string>& getHistory() const;
    bool update();
    std::string getServerDescription() const;
  private:
    Connection* server;
    ChatRoom* new_chatroom;
    std::list<std::string> history;
    std::string nickname;
    std::list<std::string> members;
};

#endif
