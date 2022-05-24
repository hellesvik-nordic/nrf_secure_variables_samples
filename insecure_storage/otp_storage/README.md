# OTP Storage Sample
**DISCLAIMER: This sample is unofficial. Official documentation on the driver can be found at the end of the README**
This sample is intended as a quick reference for the TODO(put link here) blogpost.

This sample uses the [nrfxliv NVMC driver](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/1.9.1/nrfx/drivers/nvmc/driver.html?highlight=uicr#c.nrfx_nvmc_all_erase) to read and write from the One Time Programmable(OTP) memory.
The nRF51 and nRF52 series does not have functionality for OTP.
The nRF OTP will be erased and can be written again after an eraseall operation. This makes it not real OTP, but emulated OTP.

## Howto
Build and flash:
```
west build -b <board_name>
west flash
```
To reset the OTP, use either of these two commands
```
nrfjprog --eraseall
west flash --erase
```

## Documentation
- [nRF5340 Product Specification on OTP](https://infocenter.nordicsemi.com/topic/ps_nrf5340/kmu.html?cp=3_0_0_6_16_3_0#kmu_otp)
- [nRF5340 Product Specification on UICR](https://infocenter.nordicsemi.com/topic/ps_nrf5340/chapters/uicr/doc/uicr.html?cp=3_0_0_4_3_2)
- [nRF9160 Product Specification on OTP](https://infocenter.nordicsemi.com/topic/ps_nrf9160/kmu.html?cp=2_0_0_5_7_3_0#kmu_otp)
- [nRF9160 Product Specification on UICR](https://infocenter.nordicsemi.com/topic/ps_nrf9160/uicr.html?cp=2_0_0_3_5)
