#include <android/log.h>

#ifndef LOG_TAG
#define LOG_TAG NULL
#endif

#ifndef LOGE
#if LOG_NDEBUG
#define LOGE(msg...) ((void)0)
#else
#define LOGE(msg...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, msg)
#endif
#endif

#ifndef LOGI
#if LOG_NDEBUG
#define LOGI(msg...) ((void)0)
#else
#define LOGI(msg...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,msg)
#endif
#endif

#ifndef LOGD
#if LOG_NDEBUG
#define LOGD(msg...) ((void)0)
#else
#define LOGD(msg...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,msg)
#endif
#endif

#ifndef LOGV
#if LOG_NDEBUG
#define LOGV(msg...) ((void)0)
#else
#define LOGV(msg...) __android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,msg)
#endif
#endif

#ifndef LOGW
#if LOG_NDEBUG
#define LOGW(msg...) ((void)0)
#else
#define LOGW(msg...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG,msg)
#endif
#endif

