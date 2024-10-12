/**
 * Task bot. A bot for issuing tasks and sending them for verification.
 * Copyright (C) 2024  Andrew Kozmin <syn.kolbasyn.06@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


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
