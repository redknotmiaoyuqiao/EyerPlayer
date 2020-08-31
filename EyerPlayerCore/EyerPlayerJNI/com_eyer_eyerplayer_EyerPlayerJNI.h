/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_eyer_eyerplayer_EyerPlayerJNI */

#ifndef _Included_com_eyer_eyerplayer_EyerPlayerJNI
#define _Included_com_eyer_eyerplayer_EyerPlayerJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_init
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1init
  (JNIEnv *, jclass);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_uninit
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1uninit
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_set_surface
 * Signature: (JLandroid/view/Surface;)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1set_1surface
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_set_callback
 * Signature: (JLcom/eyer/eyerplayer/callback/EyerCallback;)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1set_1callback
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_open
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1open
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_play
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1play
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_pause
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1pause
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_stop
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1stop
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_seek
 * Signature: (JD)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1seek
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    gl_context_alloc
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_gl_1context_1alloc
  (JNIEnv *, jclass);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    gl_context_dealloc
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_gl_1context_1dealloc
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    gl_context_init
 * Signature: (JLandroid/view/Surface;)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_gl_1context_1init
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    gl_context_uninit
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_gl_1context_1uninit
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    gl_context_makecurrent
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_gl_1context_1makecurrent
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    gl_context_start_gl_thread
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_gl_1context_1start_1gl_1thread
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    gl_context_stop_gl_thread
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_gl_1context_1stop_1gl_1thread
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
