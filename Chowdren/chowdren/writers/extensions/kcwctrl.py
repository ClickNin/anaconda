from chowdren.writers.objects import ObjectWriter

from chowdren.common import (get_image_name, get_animation_name, to_c,
    make_color)

from chowdren.writers.events import (StaticActionWriter, StaticConditionWriter,
    ExpressionMethodWriter, StaticExpressionWriter, make_table)

class WindowControl(ObjectWriter):
    class_name = 'WindowControl'
    use_alterables = True

class WindowWidth(ExpressionMethodWriter):
    method = '.WINDOW_WIDTH'

class WindowHeight(ExpressionMethodWriter):
    method = '.WINDOW_HEIGHT'

actions = make_table(StaticActionWriter, {
    0 : 'set_x',
    1 : 'set_y',
    3 : 'set_width',
    4 : 'set_height',
    17 : 'set_position',
    12 : 'maximize',
    13 : 'restore',
    21 : 'set_focus(true)'
})

conditions = make_table(StaticConditionWriter, {
    1 : 'is_maximized',
    4 : 'has_focus'
})

expressions = make_table(StaticExpressionWriter, {
    0 : 'get_x()',
    1 : 'get_y()',
    2 : 'get_width()',
    3 : 'get_height()',
    4 : 'get_screen_width()',
    5 : 'get_screen_height()',
    7 : 'get_width()', # client area
    8 : 'get_height()', # client area
    13 : WindowWidth,
    14 : WindowHeight
})

def get_object():
    return WindowControl