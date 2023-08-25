import tensorflow as tf

# Check if GPU is available
if tf.config.list_physical_devices('GPU'):
  # Set the device to GPU
  print("GPU\n")
  device = '/device:GPU:0'
else:
  # Set the device to CPU
  print("cpu\n")
  device = '/device:CPU:0'

# Load the data
(x_train, y_train), (x_test, y_test) = tf.keras.datasets.mnist.load_data()

# Create the model
model = tf.keras.Sequential([
  tf.keras.layers.Flatten(input_shape=(28, 28)),
  tf.keras.layers.Dense(128, activation='relu'),
  tf.keras.layers.Dense(10, activation='softmax')
])

# Compile the model
model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])

# Train the model
model.fit(x_train, y_train, epochs=10, batch_size=128)

# Evaluate the model
model.evaluate(x_test, y_test, batch_size=128)