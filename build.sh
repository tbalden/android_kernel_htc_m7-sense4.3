PATH=$PATH:/home/Mightybear007/arm-eabi-4.7/bin/

export CCOMPILER=/home/Mightybear007/arm-eabi-4.7/bin/arm-eabi-

make ARCH=arm sky_defconfig

make -j16 ARCH=arm CROSS_COMPILE=$CCOMPILER

cp arch/arm/boot/zImage ../finished/Oneimage;

find . -iname '*.ko' -exec cp {} ../finished/Onemodule \;

echo "";
echo "COMPILING FINISHED!!!";
echo "";
echo "Press any key to do a \"make clean\" or CTRL+C to skip it";
read;
alias make='make -j16 ARCH=arm CROSS_COMPILE=$CCOMPILER'
make clean