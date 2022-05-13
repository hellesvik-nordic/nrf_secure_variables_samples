#include <zephyr.h>
#include <device.h>
#include <fs/nvs.h>
#include <storage/flash_map.h>
#include <string.h>

#include <fprotect.h>

// Toggle these define to choose if fprotect shall protect the NVS flash region from read and/or write
#define WRITE_AND_READ_PROTECT 0
#define WRITE_PROTECT 1

// The following code is copied from the insecure_storage/nvs_storage sample --------------------------------
#define DEVICE_LABEL storage
#define KEY_ID 1
#define KEY_SIZE 12
static struct nvs_fs nvs = {
    .sector_size = DT_PROP(DT_CHOSEN(zephyr_flash), erase_block_size), //Got this from samples/nfc/writable_ndef_msg
    .sector_count = 2, //Decided based on how much the application needs
    .offset = FLASH_AREA_OFFSET(DEVICE_LABEL),
};

void nvs_sample_code(){
    ssize_t ret = 0;
    const struct device *nvs_dev;
    uint8_t key[KEY_SIZE];

    nvs_dev = FLASH_AREA_DEVICE(DEVICE_LABEL);
    if(!device_is_ready(nvs_dev)){
        printk("Error: Device not ready\n");
        return; 
    }
    nvs_init(&nvs, nvs_dev->name);

    ret = nvs_read(&nvs, KEY_ID, key, sizeof(key));
    if(ret > 0){ // Key already in NVS
        printk("Key read from NVS: %s\n", key);
    }
    else{ // Key not in NVS
        strcpy(key,"password123");
        printk("Write key to NVS complete\n");
        nvs_write(&nvs, KEY_ID, key, sizeof(key));
    }
    printk("End of NVS simple sample\n");

}
// End of nvs_storage copy-paste ----------------------------------------------------------------------------

void main(void)
{
    printk("--------------------------------\n");
    printk("FPROTECT PROTECTED FLASH EXAMPLE\n");
    printk("--------------------------------\n");

    if(WRITE_AND_READ_PROTECT){
        fprotect_area_no_access(nvs.offset, nvs.sector_size * nvs.sector_count);
        printk("The NVS flash area has been locked for write and read. If the application tries to write or read to/from this area, a bus fault will occur.\n");
    }else if(WRITE_PROTECT){
        fprotect_area(nvs.offset, nvs.sector_size * nvs.sector_count);
        printk("The NVS flash area has been locked for write. If the application tries to write to this area, a bus fault will occur.\n");
    }

    nvs_sample_code();
}

