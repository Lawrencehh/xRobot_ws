// Auto-generated. Do not edit!

// (in-package communication_test.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class func_motors_feedback {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Encorder_linearModule = null;
      this.Hall_putter_1_left = null;
      this.Hall_putter_1_right = null;
      this.Hall_putter_2_left = null;
      this.Hall_putter_2_right = null;
      this.Hall_putter_3_left = null;
      this.Hall_putter_3_right = null;
    }
    else {
      if (initObj.hasOwnProperty('Encorder_linearModule')) {
        this.Encorder_linearModule = initObj.Encorder_linearModule
      }
      else {
        this.Encorder_linearModule = 0;
      }
      if (initObj.hasOwnProperty('Hall_putter_1_left')) {
        this.Hall_putter_1_left = initObj.Hall_putter_1_left
      }
      else {
        this.Hall_putter_1_left = 0;
      }
      if (initObj.hasOwnProperty('Hall_putter_1_right')) {
        this.Hall_putter_1_right = initObj.Hall_putter_1_right
      }
      else {
        this.Hall_putter_1_right = 0;
      }
      if (initObj.hasOwnProperty('Hall_putter_2_left')) {
        this.Hall_putter_2_left = initObj.Hall_putter_2_left
      }
      else {
        this.Hall_putter_2_left = 0;
      }
      if (initObj.hasOwnProperty('Hall_putter_2_right')) {
        this.Hall_putter_2_right = initObj.Hall_putter_2_right
      }
      else {
        this.Hall_putter_2_right = 0;
      }
      if (initObj.hasOwnProperty('Hall_putter_3_left')) {
        this.Hall_putter_3_left = initObj.Hall_putter_3_left
      }
      else {
        this.Hall_putter_3_left = 0;
      }
      if (initObj.hasOwnProperty('Hall_putter_3_right')) {
        this.Hall_putter_3_right = initObj.Hall_putter_3_right
      }
      else {
        this.Hall_putter_3_right = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type func_motors_feedback
    // Serialize message field [Encorder_linearModule]
    bufferOffset = _serializer.int32(obj.Encorder_linearModule, buffer, bufferOffset);
    // Serialize message field [Hall_putter_1_left]
    bufferOffset = _serializer.int32(obj.Hall_putter_1_left, buffer, bufferOffset);
    // Serialize message field [Hall_putter_1_right]
    bufferOffset = _serializer.int32(obj.Hall_putter_1_right, buffer, bufferOffset);
    // Serialize message field [Hall_putter_2_left]
    bufferOffset = _serializer.int32(obj.Hall_putter_2_left, buffer, bufferOffset);
    // Serialize message field [Hall_putter_2_right]
    bufferOffset = _serializer.int32(obj.Hall_putter_2_right, buffer, bufferOffset);
    // Serialize message field [Hall_putter_3_left]
    bufferOffset = _serializer.int32(obj.Hall_putter_3_left, buffer, bufferOffset);
    // Serialize message field [Hall_putter_3_right]
    bufferOffset = _serializer.int32(obj.Hall_putter_3_right, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type func_motors_feedback
    let len;
    let data = new func_motors_feedback(null);
    // Deserialize message field [Encorder_linearModule]
    data.Encorder_linearModule = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [Hall_putter_1_left]
    data.Hall_putter_1_left = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [Hall_putter_1_right]
    data.Hall_putter_1_right = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [Hall_putter_2_left]
    data.Hall_putter_2_left = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [Hall_putter_2_right]
    data.Hall_putter_2_right = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [Hall_putter_3_left]
    data.Hall_putter_3_left = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [Hall_putter_3_right]
    data.Hall_putter_3_right = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 28;
  }

  static datatype() {
    // Returns string type for a message object
    return 'communication_test/func_motors_feedback';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '71b9c468b90827306b28dd711ec11502';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
        int32 Encorder_linearModule  
        int32 Hall_putter_1_left     
        int32 Hall_putter_1_right   
        int32 Hall_putter_2_left     
        int32 Hall_putter_2_right   
        int32 Hall_putter_3_left     
        int32 Hall_putter_3_right    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new func_motors_feedback(null);
    if (msg.Encorder_linearModule !== undefined) {
      resolved.Encorder_linearModule = msg.Encorder_linearModule;
    }
    else {
      resolved.Encorder_linearModule = 0
    }

    if (msg.Hall_putter_1_left !== undefined) {
      resolved.Hall_putter_1_left = msg.Hall_putter_1_left;
    }
    else {
      resolved.Hall_putter_1_left = 0
    }

    if (msg.Hall_putter_1_right !== undefined) {
      resolved.Hall_putter_1_right = msg.Hall_putter_1_right;
    }
    else {
      resolved.Hall_putter_1_right = 0
    }

    if (msg.Hall_putter_2_left !== undefined) {
      resolved.Hall_putter_2_left = msg.Hall_putter_2_left;
    }
    else {
      resolved.Hall_putter_2_left = 0
    }

    if (msg.Hall_putter_2_right !== undefined) {
      resolved.Hall_putter_2_right = msg.Hall_putter_2_right;
    }
    else {
      resolved.Hall_putter_2_right = 0
    }

    if (msg.Hall_putter_3_left !== undefined) {
      resolved.Hall_putter_3_left = msg.Hall_putter_3_left;
    }
    else {
      resolved.Hall_putter_3_left = 0
    }

    if (msg.Hall_putter_3_right !== undefined) {
      resolved.Hall_putter_3_right = msg.Hall_putter_3_right;
    }
    else {
      resolved.Hall_putter_3_right = 0
    }

    return resolved;
    }
};

module.exports = func_motors_feedback;
