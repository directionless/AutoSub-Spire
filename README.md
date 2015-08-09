# Introduction

[AutoSub](http://www.automaticsubconscious.com) has a large dome. It
has a spire. seph helped rebuild it in 2013, repaired and improved it
for 2014 and 2015. Here are the notes and instructions.

# Overview

The AutoSub dome spire has a handful or parts.

## Metal

There is the white metal spire. This has *11* mounting plates on
it. It has through holes where it attaches to the top of the dome. The
easiest way to install it, is post dome build.

1. Carry it (with all the lighting gack) up the dome.
2. Attach one of the bolts.
3. Tip it upward, and attach the second bolt.

You probably want 2 people, and you may want a mallet.

## Rings

There are *12* rainbow LED rings. (11 for the spire, and one extra)
They connect to the brackets via a sketchy mess of zip ties. Maybe
there's a picture.

They are a bunch of ws2812 style LED strips. They are the 12v variety,
this means they are addressable in groups of 3. Logically, they
present as one long strand.

Each ring has a 4 conductor connector. Ground, Vin, Data-in, and
Data-out. The cable carries power, along with the data
jumpers. Because the data jumpers are each only one hop, you must
**not** skip any connectors. They can be open on the tail end, but you
must fill from closest to the power supply. (And there are 12 cable
slots, so one is unused)

The controller is a small plastic box, with a computer power supply
and arduino wedged inside. It's got mesh filtering the input and
output, and taped seams. It's held up for 2 years, and seems solid.

## Beacon

The top beacon is a strip of white 5050 LEDs attached to a 2L soda
bottle. They are connected to a microcontroller running a simple
heartbeat pulse. (Breath in, breath out). They are quite bright, and
visible at great distance.

The beacon has a dedicated microcontroller (circa 2015) that hangs out
at the top of the spire. The whole assemble just takes 12v. and spits
out a heartbeat pattern.

Connectors are anderson powerpoles. They are oriented to ensure input
and output are not compatible.


# Year By Year

## 2015

seph brought everything home. And in typical fashion, mostly ignored
it till summer.

The rings remain fine.

The beacon light was cleaned. The microcontroller was reflashed and
taped up a bit better. But no substantial improvements. 

## 2014

seph brought everything home. And in typical fashion, mostly ignored
it till summer.

The rings worked fine, and were unchanged.

The beacon was redone on a new soda bottle. Unfortunately, the
microcontroller from 2013 returned to it's rightful place, so seph
build a trivial arduino + mosfet.

### Verdict:

Mixed.

While the rings survived and still look good, the top beacon tied in
during a rain and lightning storm. Post event analysis is unclear --
it worked after being reflashed. Not sure if rain or static shorted
things, not sure if that's fixable.


## 2013

Started from scratch. Doug made a white metal spire thing, which
brackets every foot.

seph designed and build LED rainbow rings, plus an associated, weather
resistant powersupply & controller.

The top beacon was build on playa out of scrap by seph and ???. It was
a strip of 5050 white LEDs wrapped around a soda bottle, with a simple
microcontroller and a lot of zipties.

### Verdict:

Success!

It was visible from great distance, looked good, and survived.

## Ancient History

No clue, but I hear it involved EL wire.
