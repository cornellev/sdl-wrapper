// Copyright (C) 2024 Ethan Uppal. All rights reserved.

#include <iostream>
#include <memory>
#include "gui/window.h"
#include "demo_view.h"

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700

int main() {
    Window window("Demo", WINDOW_WIDTH, WINDOW_HEIGHT);

    DemoView* view = new DemoView();
    window.attach_view(view);

    window.present();
}
