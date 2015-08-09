# Troubleshooting

An attempt at problems...

## Rings light, but no beacon

The beacon is an entirely separate subsystem. It borrows the 12v
power, but has it's own micro controller. 

Did it work at all? Maybe the micro controller died. It happened
in 2014. :(


## Missing rings

The rings must be plugged into the lowest slots on the cable -- Start
nearest the power supply. Because the connections are a daisy chain,
and missing run will disable everything downstream.

Similarly, any broken ring, will disable anything downstream.

