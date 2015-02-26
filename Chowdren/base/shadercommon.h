#ifndef CHOWDREN_SHADER_H
#define CHOWDREN_SHADER_H

#include <string>
#include "image.h"

// GLES attrib indexes
#define MAX_ATTRIB 4
#define POSITION_ATTRIB_IDX 0
#define POSITION_ATTRIB_NAME "in_pos"
#define COLOR_ATTRIB_IDX 1
#define COLOR_ATTRIB_NAME "in_blend_color"
#define TEXCOORD1_ATTRIB_IDX 2
#define TEXCOORD1_ATTRIB_NAME "in_tex_coord1"
#define TEXCOORD2_ATTRIB_IDX 3
#define TEXCOORD2_ATTRIB_NAME "in_tex_coord2"
#define TEXTURE_SAMPLER_NAME "texture"
#define BACKTEX_SAMPLER_NAME "background_texture"
#define SIZE_UNIFORM_NAME "texture_size"

// shader flags
enum ShaderFlags
{
    SHADER_HAS_BACK = (1 << 0),
    SHADER_HAS_TEX_SIZE = (1 << 1)
};

class FrameObject;

extern std::string shader_path;
void set_shader_path(const std::string & path);
void init_shaders();
void convert_vec4(int value, float & a, float & b, float & c, float & d);

class Shader
{
public:


    virtual void begin(FrameObject * instance, int width, int height) {}
    virtual void end(FrameObject * instance) {}

    void begin(FrameObject * instance, Image * image)
    {
        begin(instance, image->width, image->height);
    }

    virtual unsigned int get_background_texture()
    {
        return 0;
    }

    virtual bool get_texture_param()
    {
        return 0;
    }
};

extern Shader * subtract_shader;
extern Shader * additive_shader;
extern Shader * monochrome_shader;
extern Shader * mixer_shader;
extern Shader * hue_shader;
extern Shader * dummy_shader;
extern Shader * blend_shader;
extern Shader * offset_shader;
extern Shader * dodgeblur_shader;
extern Shader * invert_shader;
extern Shader * grain_shader;
extern Shader * multiply_shader;
extern Shader * hardlight_shader;
extern Shader * tint_shader;
extern Shader * channelblur_shader;
extern Shader * bgbloom_shader;
extern Shader * underwater_shader;
extern Shader * rotatesub_shader;
extern Shader * simplemask_shader;
extern Shader * offsetstationary_shader;
extern Shader * patternoverlay_shader;
extern Shader * crt_shader;
extern Shader * subpx_shader;
extern Shader * zoomoffset_shader;
extern Shader * gradient_shader;
extern Shader * overlayalpha_shader;
extern Shader * lens_shader;
extern Shader * coldirblur_shader;
extern Shader * ninepatch_shader;
extern Shader * pixeloutline_shader;
extern Shader * brightsatbg_shader;
extern Shader * bgblur_shader;

// extension shaders
extern Shader * perspective_shader;

// system shaders
extern Shader * replace_shader;
#ifndef CHOWDREN_USE_GL
extern Shader * basic_shader;
extern Shader * texture_shader;
#endif

#endif // CHOWDREN_SHADER_H
