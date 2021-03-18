cd ../../

basepath=$(cd `dirname $0`; pwd)
echo ${basepath}

:<<!
if [ -d ./Eyer3rdpart ];then 
    rm -rf Eyer3rdpart
fi

git clone https://gitee.com/redknot/Eyer3rdpart
!


export COMMON_FF_CFG_FLAGS=
. ${basepath}/tools/configs/module.sh

cd ${basepath}/Eyer3rdpart/ffmpeg-4.3/


ARCH=arm64

PLATFORM="iPhoneOS"
XCRUN_SDK=`echo $PLATFORM | tr '[:upper:]' '[:lower:]'`
CC="xcrun -sdk $XCRUN_SDK clang"

AS="gas-preprocessor.pl -arch aarch64 -- $CC"

CONFIGURE_FLAGS="--enable-cross-compile --disable-debug --disable-programs --disable-doc --enable-pic"

# $COMMON_FF_CFG_FLAGS \
./configure \
--target-os=darwin \
--arch="$ARCH" \
--cc="$CC" \
--as="$AS" \
$CONFIGURE_FLAGS \
--prefix=./ffmpeg_install \

make clean
make -j4
make install