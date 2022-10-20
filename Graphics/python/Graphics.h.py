from random import random
from turtle import onclick
from kivy.app import App
from kivy.uix.widget import Widget
from kivy.uix.button import Button
from kivy.uix.boxlayout import BoxLayout
from kivy.graphics import Color, Ellipse, Line
import time

class MyPaintWidget(Widget):

    def on_touch_down(self, touch):
        color = (random(), 1, 1)
        with self.canvas:
            Color(*color, mode='hsv')
            d = 30.
            Ellipse(pos=(touch.x - d / 2, touch.y - d / 2), size=(d, d))
            touch.ud['line'] =Line()

    def on_touch_move(self, touch):
        touch.ud['line'].points += [touch.x, touch.y]

from kivy.lang import Builder
design="""
<MyPaintApp>
    GridLayout:
            cols: 1
            size_hint: None, None
            size: self.minimum_size
            Button:
                size_hint: None, None
                size: 100, 44
                text: 'clear'
                on_state: self.clear_canvas
            Button:
                size_hint: None, None
                size: 100, 44
                text: 'plot'
                on_press: self.plot
    """
class MyPaintApp(App):

    def build(self):
        parent = Widget()
        self.painter = MyPaintWidget()
        box = BoxLayout()
        p=Button(text='Plot')
        p.bind(on_release=self.plot_btn)
        box.add_widget(p)

        clearbtn = Button(text='Clear')
        clearbtn.bind(on_release=self.clear_canvas)
        parent.add_widget(self.painter)
        #parent.add_widget(clearbtn)
        box.add_widget(clearbtn)
        parent.add_widget(box)
        return parent

    def clear_canvas(self, obj):
        self.painter.canvas.clear()
        with open('output.txt','w') as f:
            pass
    def plot_btn(self,obj):
        self.plot()
    def plot(self):
        with open('output.txt','r') as f:
            points=[]
            lt=f.readlines()
            for item in lt:
                #print(item.split())
                points.append(list(map(int,item.split())))
        #print(points)
        #lt=map(lambda a: a.split(),lt)
        color=(random(),1,1)
        with self.painter.canvas:
            Color(*color,mode='hsv')
            for point in points:
                d=10.0
                Ellipse(pos=(point[0]-d/2,point[1]-d/2),size=(d,d))
    

if __name__ == '__main__':
    MyPaintApp().run()
