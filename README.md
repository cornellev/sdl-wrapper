# sdl-wrapper

Ethan's wrapper around SDL for easier use.

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

## Documentation

All header files are well documented.
Please read them for additional information.
For example, [`geo/midpoint.h`](src/geo/midpoint.h) contains a circle-drawing primitive.
