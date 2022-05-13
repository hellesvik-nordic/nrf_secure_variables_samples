# Simple fprotect Sample
**DISCLAIMER: This sample is unofficial. See the [Hardware flash write protection API](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/libraries/others/fprotect.html) for official documentation.**

This sample is intended as a quick reference for the TODO(put link here) blogpost.

It uses the [fprotect API](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/1.9.1/nrf/libraries/others/fprotect.html) to set read protection for the flash area used for NVS.
Then the code from the [Simple NVS Sample](../../insecure_storage/nvs_storage) is used to attempt a write or read from flash.
If the flash is protected by fprotect, a bussfault will occur when NVS tries to access the flash.

## Usage
Program and flash your developement kit. 
Edit the  WRITE\_AND\_READ\_PROTECT and WRITE\_PROTECT defines to choose which protections are used for flash area used for NVS.
If the key is not in NVS, it will be written to NVS. Otherwise, it will be read and printed.
Observe how the sample behaves after erase and reset from a serial terminal.

```
west build -b <board_name>
nrfjprog --reset
```
