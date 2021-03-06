# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from communication_test/func_motors_feedback.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class func_motors_feedback(genpy.Message):
  _md5sum = "71b9c468b90827306b28dd711ec11502"
  _type = "communication_test/func_motors_feedback"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """    int32 Encorder_linearModule  
    int32 Hall_putter_1_left     
    int32 Hall_putter_1_right   
    int32 Hall_putter_2_left     
    int32 Hall_putter_2_right   
    int32 Hall_putter_3_left     
    int32 Hall_putter_3_right    """
  __slots__ = ['Encorder_linearModule','Hall_putter_1_left','Hall_putter_1_right','Hall_putter_2_left','Hall_putter_2_right','Hall_putter_3_left','Hall_putter_3_right']
  _slot_types = ['int32','int32','int32','int32','int32','int32','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       Encorder_linearModule,Hall_putter_1_left,Hall_putter_1_right,Hall_putter_2_left,Hall_putter_2_right,Hall_putter_3_left,Hall_putter_3_right

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(func_motors_feedback, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.Encorder_linearModule is None:
        self.Encorder_linearModule = 0
      if self.Hall_putter_1_left is None:
        self.Hall_putter_1_left = 0
      if self.Hall_putter_1_right is None:
        self.Hall_putter_1_right = 0
      if self.Hall_putter_2_left is None:
        self.Hall_putter_2_left = 0
      if self.Hall_putter_2_right is None:
        self.Hall_putter_2_right = 0
      if self.Hall_putter_3_left is None:
        self.Hall_putter_3_left = 0
      if self.Hall_putter_3_right is None:
        self.Hall_putter_3_right = 0
    else:
      self.Encorder_linearModule = 0
      self.Hall_putter_1_left = 0
      self.Hall_putter_1_right = 0
      self.Hall_putter_2_left = 0
      self.Hall_putter_2_right = 0
      self.Hall_putter_3_left = 0
      self.Hall_putter_3_right = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_7i().pack(_x.Encorder_linearModule, _x.Hall_putter_1_left, _x.Hall_putter_1_right, _x.Hall_putter_2_left, _x.Hall_putter_2_right, _x.Hall_putter_3_left, _x.Hall_putter_3_right))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 28
      (_x.Encorder_linearModule, _x.Hall_putter_1_left, _x.Hall_putter_1_right, _x.Hall_putter_2_left, _x.Hall_putter_2_right, _x.Hall_putter_3_left, _x.Hall_putter_3_right,) = _get_struct_7i().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_7i().pack(_x.Encorder_linearModule, _x.Hall_putter_1_left, _x.Hall_putter_1_right, _x.Hall_putter_2_left, _x.Hall_putter_2_right, _x.Hall_putter_3_left, _x.Hall_putter_3_right))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 28
      (_x.Encorder_linearModule, _x.Hall_putter_1_left, _x.Hall_putter_1_right, _x.Hall_putter_2_left, _x.Hall_putter_2_right, _x.Hall_putter_3_left, _x.Hall_putter_3_right,) = _get_struct_7i().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_7i = None
def _get_struct_7i():
    global _struct_7i
    if _struct_7i is None:
        _struct_7i = struct.Struct("<7i")
    return _struct_7i
