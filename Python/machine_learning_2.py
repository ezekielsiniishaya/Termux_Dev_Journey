# Import necessary libraries
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt

# Step 3: Generate some sample data
# For example, let's say we have data of age (X) and height (y)
X = np.array([5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]).reshape(-1, 1)  # Age in years
y = np.array([110, 115, 120, 130, 135, 140, 150, 155, 160, 165, 170])  # Height in cm

# Step 4: Split the data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Step 5: Create a linear regression model
model = LinearRegression()

# Step 6: Train the model
model.fit(X_train, y_train)

# Step 7: Make predictions on the test set
y_pred = model.predict(X_test)

# Step 8: Visualize the result
plt.scatter(X, y, color='blue', label='Actual Data')
plt.plot(X_test, y_pred, color='red', label='Predicted Line')
plt.xlabel('Age (years)')
plt.ylabel('Height (cm)')
plt.title('Linear Regression Example')
plt.legend()
plt.show()

# Step 9: Evaluate the model (optional)
print("Model Coefficient (slope):", model.coef_)
print("Model Intercept:", model.intercept_)

