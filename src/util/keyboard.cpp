// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "keyboard.h"

Keyboard::Keyboard(bool ignores_key_repeat)
    : ignores_key_repeat(ignores_key_repeat) {}

void Keyboard::update(const SDL_Event& key_event) {
    // only handle key events
    if (key_event.type != SDL_KEYDOWN && key_event.type != SDL_KEYUP) {
        return;
    }

    // ignore held keys if configured
    if (ignores_key_repeat && key_event.key.repeat > 0) {
        return;
    }

    switch (key_event.type) {
        case SDL_KEYDOWN: {
            states[key_event.key.keysym.sym] = true;
            break;
        }
        case SDL_KEYUP: {
            states[key_event.key.keysym.sym] = false;
            break;
        }
    }
}

bool Keyboard::query(SDL_Keycode code) const {
    return states.count(code) ? states.find(code)->second : false;
}
