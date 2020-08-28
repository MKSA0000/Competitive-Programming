import numpy as np
import tkinter as tk
import tkinter.ttk as ttk
import sys

def main():
    root = tk.Tk()
    style = ttk.Style()
    style.configure("TButton", font = ('', 16))
    style.configure("TRadiobutton", font = ('', 16))
    style.configure("TCheckbutton", font = ('', 16))

    v = tk.IntVar()
    v.set(0)

    opts = [tk.BooleanVar() for _ in range(4)]
    for x in range(4): opts[x].set(True)

    # ノートブック
    nb = ttk.Notebook(root)
    nb.pack()

    # ボタン類の配置
    f0 = ttk.Frame(root)
    f1 = ttk.Frame(root)
    f2 = ttk.Frame(root)
    for x in range(4):
        ttk.Button(f0, text = 'button {}'.format(x)).pack()
        ttk.Radiobutton(f1, text = 'radiobutton {}'.format(x), value = x, variable = v).pack()
        ttk.Checkbutton(f2, text = 'checkbutton {}'.format(x), variable = opts[x]).pack()

    nb.add(f0, text = 'Button', padding = 20)
    nb.add(f1, text = 'Radio', padding = 20)
    nb.add(f2, text = 'Check', padding = 20)

    root.mainloop()

main()