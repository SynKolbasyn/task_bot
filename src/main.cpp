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


#include <Arduino.h>


#define FB_NO_FILE

#include <FastBot2.h>

#include <queue>

#include "log.hpp"


void update_handler(fb::Update& update);
bool have_access(size_t hash);


std::queue<Log> logs;

FastBot2 bot;


void setup() {
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED);
  Serial.println("WiFi is connected");

  bot.setToken(F(BOT_TOKEN));
  bot.attachUpdate(update_handler);
  bot.setPollMode(fb::Poll::Long, 30000);
  Serial.println("The bot is configured");
}

void loop() {
  bot.tick();
}


void update_handler(fb::Update& update) {
  fb::MessageRead message = update.message();
  fb::UserRead from = message.from();
  su::Text id = from.id();

  if (!have_access(id.hash())) return;

  su::Text message_text = message.text();
  uint32_t chat_id = message.chat().id();

  if (id.hash() != SH("1016975852")) logs.push(Log(id, from.firstName(), from.lastName(), from.username(), message_text));

  switch (message_text.hash()) {
    case SH("/start"):
      break;
    case SH("/logs"):
      break;
    default:
      bot.sendMessage(fb::Message("Unknown command", chat_id));
      break;
  }
}


bool have_access(size_t hash) {
  switch (hash) {
  case SH("1016975852"):
    break;
  case SH("6739030514"):
    break;
  default:
    return false;
  }
  return true;
}
