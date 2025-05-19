import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


fig, ax = plt.subplots()
xdata, ydata = [], []
line, = ax.plot([], [], 'b-', lw=2)
ax.set_xlim(-1.1, 1.1)
ax.set_ylim(-1.1, 1.1)
ax.set_aspect('equal', adjustable='box')
ax.set_title('Lissajous Figure Animation (Phase Shift = 0)')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.grid(True)

def animate(i):

    b_over_a = i / 100.0
    a = 2
    b = a * b_over_a
    delta = 0

    t = np.linspace(0, 2 * np.pi, 500)
    x = np.sin(a * t + delta)
    y = np.sin(b * t)

    line.set_data(x, y)
    ax.set_title(f'Lissajous Figure (a:b = {a}:{b_over_a:.2f}, Phase Shift = 0)')
    return line,


ani = animation.FuncAnimation(fig, animate, frames=101, interval=50, blit=True)


ani.save('lissajous_animation.gif', writer='pillow')

