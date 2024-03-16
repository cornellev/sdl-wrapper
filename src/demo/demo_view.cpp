// Copyright (C) 2023-4 Ethan Uppal. All rights reserved.

#include <cassert>
#include <cstdlib>
#include "util/logger.h"
#include "util/keyboard.h"
#include "geo/midpoint.h"
#include "demo_view.h"

DemoView::DemoView(): keyboard(true) {
    randomize_color();
}

DemoView::~DemoView() noexcept {}

void DemoView::randomize_color() {
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}

void DemoView::on_event(const SDL_Event& event) {
    bool before = keyboard.query(SDLK_SPACE);
    keyboard.update(event);
    bool after = keyboard.query(SDLK_SPACE);
    if (before && !after) {  // on key release
        randomize_color();
    }
}

void DemoView::draw(SDL_Renderer* renderer, const SDL_Rect* frame,
    double dtime) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
    int mx = frame->x + frame->w / 2;
    int my = frame->y + frame->h / 2;
    int r = std::min(frame->w, frame->h) / 2;
    SDL_DrawCircle(renderer, mx, my, r);
}
