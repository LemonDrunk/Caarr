################################################################################
# MRS Version: 1.9.0
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/Seekfree_CH32V307VCT6_Opensource_Library/project/user/src/isr.c \
E:/Seekfree_CH32V307VCT6_Opensource_Library/project/user/src/main.c 

OBJS += \
./user_c/isr.o \
./user_c/main.o 

C_DEPS += \
./user_c/isr.d \
./user_c/main.d 


# Each subdirectory must supply rules for building sources it contributes
user_c/isr.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/project/user/src/isr.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
user_c/main.o: E:/Seekfree_CH32V307VCT6_Opensource_Library/project/user/src/main.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"E:\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

