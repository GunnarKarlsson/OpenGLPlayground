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

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 600
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

/// Holds all state information relevant to a character as loaded using FreeType
struct Character {
    GLuint TextureID;   // ID handle of the glyph texture
    glm::ivec2 Size;    // Size of glyph
    glm::ivec2 Bearing;  // Offset from baseline to left/top of glyph
    GLuint Advance;    // Horizontal offset to advance to next glyph
};

#endif // COMMON_H
