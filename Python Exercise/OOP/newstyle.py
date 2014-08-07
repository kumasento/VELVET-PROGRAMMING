#! /usr/local/bin/python

class NewStyleClass(object):
    def __init__(self):
        self.__egg = "MyEgg"
    #def get_egg(self):
    #    return self.__egg
    #def set_egg(self, egg):
    #    self.__egg = egg
    #egg.property(get_egg, set_egg)
    
    @property
    def egg(self):
        return self.__egg
    @egg.setter
    def egg(self,egg):
        self.__egg = egg


