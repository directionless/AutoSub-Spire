# Ideas for the Future

## Improved Beacon Control

The beacon currently has a simple microcontroller dangling at the top
of the spire. This feels silly. On some reflection, it shouldn't be
that hard to wire it into the rest of the ws2812 network. This would
make it easy to attach to the ws2812 connection at the top.

Doing this would probably mean tying some PNP mosfets into the pixel
of ws2812. (the strips are common annode, which I think means we
really do need a PNP)

## General beacon improvements

Can we make it brighter? 100watt LEDs are pretty cheap.

## Spire LED upgrades

More rings? Different rings? Tighter spacing?
