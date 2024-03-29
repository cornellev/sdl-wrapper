// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <SDL.h>
#include <unordered_map>

/** Handles keyboard input. */
class Keyboard final {
    /** The states of each key as defined by SDL. */
    std::unordered_map<SDL_Keycode, bool> states;

    /** Whether holding down a key should count as repeated presses. */
    bool ignores_key_repeat;

public:
    /** Constructs a new keyboard tracker.
     *
     * @param ignores_key_repeat Pass `true` to ignore key repeat.
     */
    Keyboard(bool ignores_key_repeat = false);

    /** Updates the keyboard with a new event given by `key_event`. It does not
     * necessarily have to be pre-checked to be a key-related event because the
     * internals will handle that. */
    void update(const SDL_Event& key_event);

    /** Returns whether the key represented by the keycode `code` is currently
     * pressed. */
    bool query(SDL_Keycode code) const;
};
