# Simple NVS Sample
**DISCLAIMER: This sample is unofficial. See the [NVS:Non-Volatile Storage in Zephyr](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/1.9.1/zephyr/samples/subsys/nvs/README.html) for an official sample.**

This sample is intended as a quick reference for the TODO(put link here) blogpost.
It uses the Zephyr Non-Volatile Storage (NVS) API to save a key to flash.
This key is **not protected** by anything.

## Usage
Program and flash your developement kit. The "--erase" flag is to erase the key to be able to rewrite it.
If the key is not in NVS, it will be written to NVS. Otherwise, it will be read and printed.
Observe how the sample behaves after erase and reset from a serial terminal.

```
west build -b <board_name>
west flash --erase
nrfjprog --reset
```
