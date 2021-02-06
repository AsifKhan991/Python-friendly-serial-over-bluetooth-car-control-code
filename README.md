# Serial-over-bluetooh-toy-car-python-friendly-

Type of car : Servo steered and rear motor driven common cars

Serial data format for sending to device : "100,-255;\n" (without quotes for direct arduino serial) where the first number(100) is steer angle and second number(-255) is directed speed(negative for reverse, positive for forward)

# WARNING: Serial data must continously come from the pc bluetooth, no delay is allowed , otherwise the control will be a disaster!

While using python make sure to close the port after finishing 
