# Non-Secure vs Secure PWM

This sample will enable PWM driver PWM0 and PWM1.
If built for boards with postfix "_ns", such as nrf9160dk_nrf9160_ns, it will include Secure Partition Manager, see [SPM](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/1.8.0/nrf/libraries/others/spm.html) for more information on this.
SPM is configured to set PWM0 as Non-Secure, and PWM0 as Non-Secure.

So if the project is built for nrf9160dk_nrf9160, it will run fine:

```
west build -p -b nrf9160dk_nrf9160

west flash
```

However, if the project is built for nrf9160dk_nrf9160_ns, it will crash with a bus fault due to PWM1 being Secure, and not accessible from the main function. 
The application is in the Non-Secure domain.

```
west build -p -b nrf9160dk_nrf9160_ns

west flash
```

## Configuration explanation
In prj.conf, PWM is enabled and some debugging options are set. 

PWM devices are enabled in the DeviceTree before using app.overlay. See [Set DeviceTree Overlays](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/1.8.0/zephyr/guides/dts/howtos.html#set-devicetree-overlays) for why it is named app.overlay.

PWM devices are configured as Secure/Non-Secure in the SPM child image. Overlay configurations for the SPM are set in child_image/spm.conf. See [Multi-Image Builds](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/1.8.0/nrf/ug_multi_image.html) for why it is named child_image/spm.conf.



