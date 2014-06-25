#include "objects/systembox.h"
#include "include_gl.h"
#include "collision.h"

SystemBox::SystemBox(int x, int y, int type_id)
: FrameObject(x, y, type_id)
{
    collision = new InstanceBox(this);
}

SystemBox::~SystemBox()
{
    delete collision;
}

void SystemBox::draw()
{
    if (type == PATTERN_IMAGE) {
        glEnable(GL_SCISSOR_TEST);
        glc_scissor_world(x, y, width, height);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        for (int xx = x; xx < x + width; xx += image->width)
        for (int yy = y; yy < y + height; yy += image->height) {
            draw_image(image, xx + image->hotspot_x, yy + image->hotspot_y);
        }
        glDisable(GL_SCISSOR_TEST);
    } else if (type == CENTER_IMAGE) {
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        int xx = x + width / 2 - image->width / 2;
        int yy = y + height / 2 - image->height / 2;
        draw_image(image, xx + image->hotspot_x, yy + image->hotspot_y);
    } else if (type == TOPLEFT_IMAGE) {
        draw_image(image, x + image->hotspot_x, y + image->hotspot_y);
    }
}
