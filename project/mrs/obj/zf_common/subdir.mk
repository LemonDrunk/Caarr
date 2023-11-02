################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_common/zf_common_clock.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_common/zf_common_debug.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_common/zf_common_fifo.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_common/zf_common_font.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_common/zf_common_function.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_common/zf_common_interrupt.c 

OBJS += \
./zf_common/zf_common_clock.o \
./zf_common/zf_common_debug.o \
./zf_common/zf_common_fifo.o \
./zf_common/zf_common_font.o \
./zf_common/zf_common_function.o \
./zf_common/zf_common_interrupt.o 

C_DEPS += \
./zf_common/zf_common_clock.d \
./zf_common/zf_common_debug.d \
./zf_common/zf_common_fifo.d \
./zf_common/zf_common_font.d \
./zf_common/zf_common_function.d \
./zf_common/zf_common_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
zf_common/zf_common_clock.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_common/zf_common_clock.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_debug.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_common/zf_common_debug.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_fifo.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_common/zf_common_fifo.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_font.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_common/zf_common_font.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_function.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_common/zf_common_function.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_interrupt.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/libraries/zf_common/zf_common_interrupt.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

