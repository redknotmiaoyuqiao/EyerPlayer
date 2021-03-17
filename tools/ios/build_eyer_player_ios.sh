cd ../../

basepath=$(cd `dirname $0`; pwd)
echo ${basepath}

cd ${basepath}/EyerPlayerCore

if [ -d ./ios_build ];then 
    rm -rf ios_build
fi

if [ -d ./install ];then 
    rm -rf install
fi

mkdir ios_build

cd ios_build

# -DPLATFORM=OS64COMBINED \

cmake ../ \
-G Xcode \
-DCMAKE_TOOLCHAIN_FILE=${basepath}/tools/ios-cmake/ios.toolchain.cmake \
-DPLATFORM=OS64 \
-DENABLE_BITCODE=TRUE

# cmake --build . --config Release
# cmake --install . --config Release

cmake --build . --config Release --target install

cd ${basepath}/Lib
if [ -d ./player_install ];then 
    rm -rf player_install
fi

cd ${basepath}
cp -r EyerPlayerCore/install Lib/player_install


cd ${basepath}/Lib/player_install/lib

ar -x libEyerCore.a
ar -x libEyerGLContext.a
ar -x libEyerPlayerIOS.a
ar -x libEyerThread.a

ar -qcs libEyerPlayer.a *.o