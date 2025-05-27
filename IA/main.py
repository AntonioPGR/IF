from sklearn.linear_model import LinearRegression
import numpy as np
import matplotlib.pyplot as plt

x = np.array([[1], [2], [3], [4], [5]])
y = np.array([3, 7, 8, 11, 16])

model = LinearRegression()
model.fit(x, y)

x_test = np.array([[2], [4],])
y_pred = model.predict(x_test)

plt.scatter(x, y, color='blue', label='Training Data')
plt.scatter(x_test, y_pred, color='green', label='Prediction')
plt.plot(x, model.predict(x), color='red',)
plt.legend()
plt.show()