// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#pragma once

#include <SDL.h>
#include <vector>
#include "gui/view.h"
#include "util/keyboard.h"

class DemoView final : public View {
    Keyboard keyboard;
    uint8_t r, g, b;

    void randomize_color();

public:
    DemoView();
    ~DemoView() noexcept override;

    void on_event(const SDL_Event& event) override;
    void draw(SDL_Renderer* renderer, const SDL_Rect* frame,
        double dtime) override;
};
