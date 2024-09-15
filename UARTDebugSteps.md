# UART
I use a CP2102 USB to TTL chip to connect to teh UART it always takes a fiew tries to get it working so will document the steps I take for next time I try and set this up on a new comptuer.
On Windowns: make sure you have the right drivers
On Ubuntu: make sure that you have the right rights on /dev/ttyUSB0, change baud rate

- Double check wiring (Not connected to +5V/3.3V)
- With current Kernel the rpi sends out a single message after booting (takes a few seconds), reboot when checking connection
- $ sudo chown pmasselot /dev/ttyUSB0
