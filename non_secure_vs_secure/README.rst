Non-Secure vs Secure PWM
###########
This sample will enable PWM driver PWM0 and PWM1.
If built for boards with postfix "_ns", such as nrf9160dk_nrf9160_ns, it will include Secure Partition Manager, see [SPM](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/1.8.0/nrf/libraries/others/spm.html) for more information on this.
SPM is configured to set PWM0 as Secure, and PWM1 as non-secure.


Configuration
********


Building and Running
********************

This application can be built and executed on QEMU as follows:

.. zephyr-app-commands::
   :zephyr-app: samples/hello_world
   :host-os: unix
   :board: qemu_x86
   :goals: run
   :compact:

To build for another board, change "qemu_x86" above to that board's name.

Sample Output
=============

.. code-block:: console

    Hello World! x86

Exit QEMU by pressing :kbd:`CTRL+A` :kbd:`x`.
