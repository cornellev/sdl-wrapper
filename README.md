# sdl-wrapper

Ethan's wrapper around SDL for easier use.

## Demo

```shell
git clone https://github.com/cornellev/sdl-wrapper.git
cd sdl-wrapper
make demo
./demo
```

## Usage

The [demo code](src/demo) does a good job showing all the features.
Here's a step-by-step example.
After including `gui/window.h`, you can create a window with
```c++
Window window("Window Name", WINDOW_WIDTH, WINDOW_HEIGHT);
```
Then, create a view that subclasses [`View`](src/gui/view.h) and attach it to the window.
```c++
MyView* my_view = new MyView();
window.attach_view(my_view);
```
From then on, the the window will manage the memory allocated for `my_view`.
Finally, present the window, which is a blocking call.
```c++
window.present();
```

You can install the library to `/usr/local` with `sudo make install`, `sudo make uninstall`, and `sudo make reinstall`.

## Documentation

All header files are well documented.
Please read them for additional information.
For example, [`geo/midpoint.h`](src/geo/midpoint.h) contains a circle-drawing primitive.

**GUI**

- [Windows](src/gui/window.h)
- [Views](src/gui/view.h)

**Geometry**

- [Vectors](src/geo//vector.h)
- [Circles](src/geo/circle.h)
- [Midpoint Algorithm](src/geo/midpoint.h)

**Utilities**

- [Keyboard](src/util/keyboard.h)
- [Logger](src/util/logger.h)
