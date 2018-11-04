#ifndef COMMON_H
#define COMMON_H

#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QDebug>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define DEBUG_TAG "BasterMines"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640
#define NEAR_LIMIT 0.01
#define FAR_LIMIT 1000.0

#define LOGD(...) ( qDebug() << __VA_ARGS__)
#define LOGI(...) ( qDebug() << __VA_ARGS__)
#define LOGW(...) ( qDebug() << __VA_ARGS__)
#define LOGE(...) ( qDebug() << __VA_ARGS__)
#define ABORT_APP { LOGE("*** APP ABORTING."); *((volatile char*)0) = 'a'; }
#define DEBUG_BLIP LOGD("[ BLIP ]: %s:%d", __FILE__, __LINE__)

#define MY_ASSERT(cond) { if (!(cond)) { LOGE("ASSERTION FAILED: %s", #cond); \
   ABORT_APP; } }


#endif // COMMON_H
