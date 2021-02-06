# Serial-over-bluetooh-car-control-code

Type of car : Servo steered and rear motor driven 

Serial data format for sending to device : "100,-255;\n" (without quotes for direct arduino serial) where the first number(100) is steer angle and second number(-255) is directed speed(negative for reverse, positive for forward)

# WARNING: Serial data flow from pc must be continiuous, no delay is allowed , otherwise there will be rouge control 

While using python make sure to close the port after finishing 
