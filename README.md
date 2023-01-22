# The Game of Life
This project is a visualization of "The Game of Life". Only character (ASCII) graphics are used to display the graphics (with output to the terminal). Implemented setting of the game speed.

The field is a rectangle of 80 by 25 squares. The field is "closed to itself", i.e. lower right square has lower left square as neighbor to the right, and upper right square - as neighbor to the bottom.

The initial initialization of the state and speed of the "game" is set via stdin. In the src folder there are 5 files with initial state for quick start and initialization through input redirection.

## Startup

```
./a.out 5000 < 4.txt 
```

## Video
[![Video](https://img.youtube.com/vi/l7tNmHZgnyw/maxresdefault.jpg)](https://youtu.be/l7tNmHZgnyw)

