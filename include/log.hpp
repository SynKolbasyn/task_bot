#pragma once

#ifndef _LOG_HPP_
#define _LOG_HPP_


#include <StringUtils.h>


class Log {
  public:
    Log(su::Text id, su::Text first_name, su::Text last_name, su::Text user_name, su::Text message);
    ~Log();

    su::Text to_text() const;


  private:
    su::Text id;
    su::Text first_name;
    su::Text last_name;
    su::Text user_name;
    su::Text message;
};


Log::Log(su::Text id, su::Text first_name, su::Text last_name, su::Text user_name, su::Text message) {
  this->id = id;
  this->first_name = first_name;
  this->last_name = last_name;
  this->user_name = user_name;
  this->message = message;
}


Log::~Log() {

}


su::Text Log::to_text() const {
  return "ID: " + this->id.toString() + "\nFULL NAME: " + this->first_name.toString(true) + " " + this->last_name.toString(true) + "\nUSER NAME: " + this->user_name.toString(true) + "\nMESSAGE: " + this->message.toString(true) + "\n";
}


#endif // !_LOG_HPP_
