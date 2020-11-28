# PhySim - C++ Physics Simulation Framework

## Build Status

| Platform | Status |
|----------|--------|
| Windows |  |
| Linux |  |


## Compatibility

**Currently in alpha**

So if you really want to try it out at the moment:

| Feature                       | Status            |
|-----------------------------  |-------------------|
| Windows DLL Support           | Semi-Completed    |
| Linux Shared Object Support   | Not yet worked on |

As such Windows is the only platform PhySim supports at the moment
<br>This **will** change in the future

## How it works

This program uses addons to achieve it's goals
<br>The two types of addons are:
<br>1) Law addons
<br>2) Material addons

Addons are distributed in the shared library format of the platform they run on
<br>So on linux they are `.so` files
<br>Whilst on a PC they are `.dll` files
