################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_adc.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_delay.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_dvp.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_encoder.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_exti.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_flash.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_gpio.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_iic.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_pit.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_pwm.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_soft_iic.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_soft_spi.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_spi.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_timer.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_uart.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_usb_cdc.c 

OBJS += \
./zf_driver/zf_driver_adc.o \
./zf_driver/zf_driver_delay.o \
./zf_driver/zf_driver_dvp.o \
./zf_driver/zf_driver_encoder.o \
./zf_driver/zf_driver_exti.o \
./zf_driver/zf_driver_flash.o \
./zf_driver/zf_driver_gpio.o \
./zf_driver/zf_driver_iic.o \
./zf_driver/zf_driver_pit.o \
./zf_driver/zf_driver_pwm.o \
./zf_driver/zf_driver_soft_iic.o \
./zf_driver/zf_driver_soft_spi.o \
./zf_driver/zf_driver_spi.o \
./zf_driver/zf_driver_timer.o \
./zf_driver/zf_driver_uart.o \
./zf_driver/zf_driver_usb_cdc.o 

C_DEPS += \
./zf_driver/zf_driver_adc.d \
./zf_driver/zf_driver_delay.d \
./zf_driver/zf_driver_dvp.d \
./zf_driver/zf_driver_encoder.d \
./zf_driver/zf_driver_exti.d \
./zf_driver/zf_driver_flash.d \
./zf_driver/zf_driver_gpio.d \
./zf_driver/zf_driver_iic.d \
./zf_driver/zf_driver_pit.d \
./zf_driver/zf_driver_pwm.d \
./zf_driver/zf_driver_soft_iic.d \
./zf_driver/zf_driver_soft_spi.d \
./zf_driver/zf_driver_spi.d \
./zf_driver/zf_driver_timer.d \
./zf_driver/zf_driver_uart.d \
./zf_driver/zf_driver_usb_cdc.d 


# Each subdirectory must supply rules for building sources it contributes
zf_driver/zf_driver_adc.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_delay.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_delay.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_dvp.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_dvp.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_encoder.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_encoder.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_exti.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_exti.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_flash.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_gpio.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_iic.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_iic.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_pit.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_pit.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_pwm.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_pwm.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_soft_iic.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_soft_iic.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_soft_spi.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_soft_spi.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_spi.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_spi.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_timer.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_timer.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_uart.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_uart.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_driver/zf_driver_usb_cdc.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_driver/zf_driver_usb_cdc.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

