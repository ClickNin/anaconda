#include "objects/viewport.h"
#include "chowconfig.h"
#include "collision.h"

// Viewport

Viewport * Viewport::instance = NULL;

Viewport::Viewport(int x, int y, int type_id)
: FrameObject(x, y, type_id)
{
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    collision = new InstanceBox(this);
    instance = this;
}

Viewport::~Viewport()
{
    glDeleteTextures(1, &texture);
    delete collision;
    instance = NULL;
}

void Viewport::set_source(int center_x, int center_y, int width, int height)
{
    this->center_x = center_x;
    this->center_y = center_y;
    src_width = width;
    src_height = height;
}

void Viewport::set_width(int w)
{
    width = w;
    collision->update_aabb();
}

void Viewport::set_height(int h)
{
    height = h;
    collision->update_aabb();
}

void Viewport::draw()
{
    if (src_width == width && src_height == height)
        return;
    if (src_width == 0 || src_height == 0)
        return;
    int src_x1 = center_x - src_width / 2;
    int src_y1 = center_y - src_height / 2;
    int src_x2 = src_x1 + src_width;
    int src_y2 = src_y1 + src_height;
    glc_copy_color_buffer_rect(texture, src_x1, src_y1, src_x2, src_y2);
    int x2 = x + width;
    int y2 = y + height;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glDisable(GL_BLEND);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(back_texcoords[0], back_texcoords[1]);
    glVertex2i(x, y);
    glTexCoord2f(back_texcoords[2], back_texcoords[3]);
    glVertex2i(x2, y);
    glTexCoord2f(back_texcoords[4], back_texcoords[5]);
    glVertex2i(x2, y2);
    glTexCoord2f(back_texcoords[6], back_texcoords[7]);
    glVertex2i(x, y2);
    glEnd();
    glEnable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
}
