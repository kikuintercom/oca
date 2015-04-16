[![Build Status](https://travis-ci.org/kikuintercom/oca.svg?branch=master)](https://travis-ci.org/kikuintercom/oca)
# OCA
Having a crack at a C++ implementation of the Open Control Architecture

In order to build an IP audio network, you need a way of sending control messages between devices, transparently and robustly. The Open Control Architecture, designed by the OCA Alliance, does exactly that - it's a full device control and monitoring protocol specification for AV networks. Already used by Bosch Communications and RTS for their IP intercom systems it's been proposed to the Audio Engineering Society as a standard, and is currently on track to become AES X-210, if it's ratified.

We want to use it too, to become the backbone of kiku's device control infrastructure. The only problem is, there isn't an open library for it yet, which means we have to build a C++ OCA library... from scratch.

We've never done this before, so this is something of a work in progress.

If you want to get in touch, give us a hand or contribute to the project in other ways, jump over to [kikuinter.com](http://kikuinter.com) and give us a shout, or email us at [admin@kikuinter.com](mailto:admin@kikuinter.com)!

Cheers,

Callum McLean,
kiku