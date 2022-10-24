# Graphics.h 
Graphics programming in C used to drawing various geometrical shapes(rectangle, circle eclipse etc), use of mathematical function in drawing curves, coloring an object with different colors and patterns and simple animation programs like jumping ball and moving cars.

---
# How to use
1. clone this folder
2. create new file in this folder itself or you can add graphics to include files of your computer
3. ```include "graphics.cpp"```
4. use put_points(x,y) to plot the points
5. start the python display change folder in terminal to python folder in this folder then ``` python3 graphicss.py```
6. press the plot button to see result
---
# Limitations of graphics.h (old)
- incompetable with mac/linux based system
- high dependance on turbo c compiler
- not updated any more
- not open source
# Proposed Solution
- built a pythonic module to use instead of graphics.h
- multisystem module 
- only python installation is necessary
- open source so highly customisable
## screen short
![Screenshot 2022-10-18 at 10 51 06 PM](https://user-images.githubusercontent.com/82832791/196933424-c86e9dff-d964-4563-8363-a496e75f427e.png)
### examples
- dda
![Screenshot 2022-10-22 at 8 46 40 PM](https://user-images.githubusercontent.com/82832791/197348532-aeddca8c-8994-4506-a367-ba4451a99611.png)

- breshman
![Screenshot 2022-10-22 at 8 39 41 PM](https://user-images.githubusercontent.com/82832791/197348544-e521bb8d-3fa7-4edb-8f8a-69a5c6002d4b.png)
- circle
![Screenshot 2022-10-22 at 8 56 17 PM](https://user-images.githubusercontent.com/82832791/197348579-85f62159-4b8e-4fc2-874d-769288b47a21.png)

- ellipse
![Screenshot 2022-10-22 at 9 18 28 PM](https://user-images.githubusercontent.com/82832791/197348621-aecdbf9b-743a-4634-a7ca-9592d4ca7f94.png)

# TODOs
- [x] add c++ bindings for pythonic files
- [x] add some examples to use the new bindings
  - [x] line 
    - [x] dda
    - [x] breshman
  - [x] circle
  - [x] ellipse
- [x] add documentation 
