from cStringIO import StringIO
from mmfparser.bytereader import ByteReader

class Platform(object):
    def __init__(self, converter):
        self.converter = converter
        self.initialize()

    def get_image(self, image):
        temp = StringIO()
        image.save(temp, 'PNG')
        return temp.getvalue()

    def get_shader(self, vertex, fragment):
        raise NotImplementedError()

    def initialize(self):
        pass

    def install(self):
        pass

    def get_sound(self, name, data):
        return name, data
