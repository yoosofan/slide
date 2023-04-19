from tkinter import *
def frame(root, side):w=Frame(root);w.pack(side=side,expand=YES,fill=BOTH);return w
def button(root, side, text, command=None):
  w=Button(root,text=text,command=command);w.pack(side=side,expand=YES,fill=BOTH);return w
class Calculator(Frame):
  def __init__(self):
    Frame.__init__(self);    self.option_add('*Font', 'Verdana 12 bold')
    self.pack(expand=YES, fill=BOTH);  self.master.title('Simple Calculator')
    self.master.iconname("calc1"); display = StringVar();prevd=StringVar()
    Entry(self, relief=SUNKEN,textvariable=display).pack(side=TOP,expand=YES,fill=BOTH)
    Label(self, relief=SUNKEN,textvariable=prevd).pack(side=TOP,expand=YES,fill=BOTH)
    for key in ("789-/","456+*","123^%", "0.()"):
      keyF = frame(self, TOP)
      for char in key:
        button(keyF, LEFT, char, lambda w=display, c=char: w.set(w.get() + c))
    clF = frame(self, BOTTOM)
    for char in "←C=X":
      if char == '=':
        btn = button(clF, LEFT, char)
        btn.bind('<ButtonRelease-1>',lambda e,s=self,w=display,l=prevd:s.calc(w,l),'+')
      elif char=='C':btn=button(clF,LEFT,char,lambda w=display:w.set(''))
      elif char=='←':btn=button(clF,LEFT,char,lambda w=display:w.set(str(w.get())[:-1]))
      else:btn=button(clF,LEFT,char,lambda w=display: exit(0))
  def calc(self, display,prevd):
    try:
      s1=str(display.get());x1=str(eval(s1.replace('^','**')));
      print(s1+'='+x1);display.set(x1);prevd.set(s1);
    except:display.set("ERROR")
if __name__=='__main__':Calculator().mainloop()
