#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>

#define handle_error(msg)   \
    do                      \
    {                       \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)

#define _PIOD_BANK_D                            0xA00

#define _PIO_OFFSET                             0xFF000008

/* When executing this on the board :
    long sz = sysconf(_SC_PAGESIZE);
    printf("%ld\n\r",sz);
   We have 4096.
// */
#define _MAP_SIZE                           8  // 4096

// #define _WPMR_OFFSET                        0x0E4   // PIO Write Protection Mode Register Bank D

#define _PIO_Direction 0xFF00000C
#define _PIO_Value 0xFF000008

// #define _PIO_DISABLE                        0x004
// #define _PIO_STATUS                         0x008
// #define _OUTPUT_ENABLE                      0x010
// #define _OUTPUT_DISABLE                     0x014
// #define _OUTPUT_STATUS                      0x018
// #define _FILTER_ENABLE                      0x020
// #define _FILTER_DISABLE                     0x024
// #define _FILTER_STATUS                      0x028
// #define _OUTPUT_DATA_SET                    0x030
// #define _OUTPUT_DATA_CLEAR                  0x034
// #define _OUTPUT_DATA_STATUS                 0x038
// #define _PIN_DATA_STATUS                    0x03c
// #define _MULTI_DRIVER_ENABLE                0x050
// #define _MULTI_DRIVER_DISABLE               0x054
// #define _MULTI_DRIVER_STATUS                0x058
// #define _PULL_UP_DISABLE                    0x060
// #define _PULL_UP_ENABLE                     0x064
// #define _PULL_UP_STATUS                     0x068
// #define _PULL_DOWN_DISABLE                  0x090
// #define _PULL_DOWN_ENABLE                   0x094
// #define _PULL_DOWN_STATUS                   0x098

// #define _DISABLE_WRITE_PROTECTION           0x50494F00  // Desable write protection

// #define LED_PIN                                 21

int main(void)
{
    volatile void *gpio_addr;
    volatile unsigned int  *gpio_value;
    volatile unsigned int *gpio_direction;

    // volatile unsigned int *gpio_output_mode_addr;
    // volatile unsigned int *gpio_output_set_addr;
    // volatile unsigned int *gpio_output_clear_addr;
    // volatile unsigned int *gpio_data_status_addr;
    // volatile unsigned int *gpio_write_protection_addr;

    int fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd < 0)
    {
        fprintf(stderr, "Unable to open port\n\r");
        exit(fd);
    }

    gpio_addr = mmap(NULL, _MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (gpio_addr == MAP_FAILED)
    {
        handle_error("mmap");
    }
    else{
        
    }

    gpio_value = gpio_addr;
    &gpio_direction = gpio_addr +4;
    
    gpio_direction = 1;
    gpio_value = 1;

    // gpio_enable_addr = _PIO_Value;
    // gpio_enable_addr = gpio_addr + _PIOD_BANK_D + _PIO_ENABLE;

    // gpio_output_mode_addr = gpio_addr + _PIOD_BANK_D + _OUTPUT_ENABLE;

    // gpio_output_set_addr = gpio_addr + _PIOD_BANK_D + _OUTPUT_DATA_SET;

    // gpio_output_clear_addr = gpio_addr + _PIOD_BANK_D + _OUTPUT_DATA_CLEAR;

    // gpio_data_status_addr = gpio_addr + _PIOD_BANK_D + _OUTPUT_DATA_STATUS;

    // *gpio_write_protection_addr = _DISABLE_WRITE_PROTECTION;

    // *gpio_enable_addr = 1 << LED_PIN;
    // *gpio_output_mode_addr = 1 << LED_PIN; // Output

    // // If LED
    // if((*gpio_data_status_addr & (1<<LED_PIN)) > 0){
    //     *gpio_output_clear_addr = 1 << LED_PIN;
    // }else{
    //     *gpio_output_set_addr = 1 << LED_PIN;
    // }

    return 0;
}