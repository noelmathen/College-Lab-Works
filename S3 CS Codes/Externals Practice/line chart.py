# import matplotlib.pyplot as plt
# x = [10, 20, 30, 40]
# y = [20, 25, 35, 55]
# z=  [10, 25, 43, 58]
# plt.plot(x, y, z , color='green', linewidth=3, markersize=15, linestyle='dotted')
# plt.title("Line Chart")
# plt.ylabel('Y-Axis')
# plt.xlabel('X-Axis')
# plt.show()

import matplotlib.pyplot as plt

x = [10, 20, 30, 40]
y = [20, 25, 35, 55]
plt.plot(x,y)
plt.savefig("output.jpg")
plt.show()
