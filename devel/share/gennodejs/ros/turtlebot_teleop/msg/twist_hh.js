// Auto-generated. Do not edit!

// (in-package turtlebot_teleop.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class twist_hh {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.linear_module = null;
      this.putter_1 = null;
      this.putter_2 = null;
      this.oblique_angle = null;
      this.oblique_drawer = null;
      this.flat_drawer = null;
      this.belt = null;
      this.camera_angle = null;
      this.camera_tilt = null;
      this.arm_auto = null;
    }
    else {
      if (initObj.hasOwnProperty('linear_module')) {
        this.linear_module = initObj.linear_module
      }
      else {
        this.linear_module = 0.0;
      }
      if (initObj.hasOwnProperty('putter_1')) {
        this.putter_1 = initObj.putter_1
      }
      else {
        this.putter_1 = 0.0;
      }
      if (initObj.hasOwnProperty('putter_2')) {
        this.putter_2 = initObj.putter_2
      }
      else {
        this.putter_2 = 0.0;
      }
      if (initObj.hasOwnProperty('oblique_angle')) {
        this.oblique_angle = initObj.oblique_angle
      }
      else {
        this.oblique_angle = 0.0;
      }
      if (initObj.hasOwnProperty('oblique_drawer')) {
        this.oblique_drawer = initObj.oblique_drawer
      }
      else {
        this.oblique_drawer = 0;
      }
      if (initObj.hasOwnProperty('flat_drawer')) {
        this.flat_drawer = initObj.flat_drawer
      }
      else {
        this.flat_drawer = 0;
      }
      if (initObj.hasOwnProperty('belt')) {
        this.belt = initObj.belt
      }
      else {
        this.belt = 0;
      }
      if (initObj.hasOwnProperty('camera_angle')) {
        this.camera_angle = initObj.camera_angle
      }
      else {
        this.camera_angle = 0;
      }
      if (initObj.hasOwnProperty('camera_tilt')) {
        this.camera_tilt = initObj.camera_tilt
      }
      else {
        this.camera_tilt = 0;
      }
      if (initObj.hasOwnProperty('arm_auto')) {
        this.arm_auto = initObj.arm_auto
      }
      else {
        this.arm_auto = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type twist_hh
    // Serialize message field [linear_module]
    bufferOffset = _serializer.float32(obj.linear_module, buffer, bufferOffset);
    // Serialize message field [putter_1]
    bufferOffset = _serializer.float32(obj.putter_1, buffer, bufferOffset);
    // Serialize message field [putter_2]
    bufferOffset = _serializer.float32(obj.putter_2, buffer, bufferOffset);
    // Serialize message field [oblique_angle]
    bufferOffset = _serializer.float32(obj.oblique_angle, buffer, bufferOffset);
    // Serialize message field [oblique_drawer]
    bufferOffset = _serializer.int8(obj.oblique_drawer, buffer, bufferOffset);
    // Serialize message field [flat_drawer]
    bufferOffset = _serializer.int8(obj.flat_drawer, buffer, bufferOffset);
    // Serialize message field [belt]
    bufferOffset = _serializer.uint8(obj.belt, buffer, bufferOffset);
    // Serialize message field [camera_angle]
    bufferOffset = _serializer.int8(obj.camera_angle, buffer, bufferOffset);
    // Serialize message field [camera_tilt]
    bufferOffset = _serializer.int8(obj.camera_tilt, buffer, bufferOffset);
    // Serialize message field [arm_auto]
    bufferOffset = _serializer.int8(obj.arm_auto, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type twist_hh
    let len;
    let data = new twist_hh(null);
    // Deserialize message field [linear_module]
    data.linear_module = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [putter_1]
    data.putter_1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [putter_2]
    data.putter_2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [oblique_angle]
    data.oblique_angle = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [oblique_drawer]
    data.oblique_drawer = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [flat_drawer]
    data.flat_drawer = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [belt]
    data.belt = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [camera_angle]
    data.camera_angle = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [camera_tilt]
    data.camera_tilt = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [arm_auto]
    data.arm_auto = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 22;
  }

  static datatype() {
    // Returns string type for a message object
    return 'turtlebot_teleop/twist_hh';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5e6950298e015b052c3449e8eabb1ac3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This expresses velocity in free space broken into its linear and angular parts.
    
    
    
    float32 linear_module
    float32 putter_1
    float32 putter_2
    
    float32 oblique_angle
    int8 oblique_drawer
    int8 flat_drawer
    
    uint8 belt
    int8 camera_angle
    int8 camera_tilt
    
    int8 arm_auto
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new twist_hh(null);
    if (msg.linear_module !== undefined) {
      resolved.linear_module = msg.linear_module;
    }
    else {
      resolved.linear_module = 0.0
    }

    if (msg.putter_1 !== undefined) {
      resolved.putter_1 = msg.putter_1;
    }
    else {
      resolved.putter_1 = 0.0
    }

    if (msg.putter_2 !== undefined) {
      resolved.putter_2 = msg.putter_2;
    }
    else {
      resolved.putter_2 = 0.0
    }

    if (msg.oblique_angle !== undefined) {
      resolved.oblique_angle = msg.oblique_angle;
    }
    else {
      resolved.oblique_angle = 0.0
    }

    if (msg.oblique_drawer !== undefined) {
      resolved.oblique_drawer = msg.oblique_drawer;
    }
    else {
      resolved.oblique_drawer = 0
    }

    if (msg.flat_drawer !== undefined) {
      resolved.flat_drawer = msg.flat_drawer;
    }
    else {
      resolved.flat_drawer = 0
    }

    if (msg.belt !== undefined) {
      resolved.belt = msg.belt;
    }
    else {
      resolved.belt = 0
    }

    if (msg.camera_angle !== undefined) {
      resolved.camera_angle = msg.camera_angle;
    }
    else {
      resolved.camera_angle = 0
    }

    if (msg.camera_tilt !== undefined) {
      resolved.camera_tilt = msg.camera_tilt;
    }
    else {
      resolved.camera_tilt = 0
    }

    if (msg.arm_auto !== undefined) {
      resolved.arm_auto = msg.arm_auto;
    }
    else {
      resolved.arm_auto = 0
    }

    return resolved;
    }
};

module.exports = twist_hh;
