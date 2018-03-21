// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Protos.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Protos.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace deepdf {

namespace {

const ::google::protobuf::Descriptor* UserInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  UserInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* DataResp_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DataResp_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Protos_2eproto() {
  protobuf_AddDesc_Protos_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Protos.proto");
  GOOGLE_CHECK(file != NULL);
  UserInfo_descriptor_ = file->message_type(0);
  static const int UserInfo_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserInfo, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserInfo, score_),
  };
  UserInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      UserInfo_descriptor_,
      UserInfo::default_instance_,
      UserInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(UserInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(UserInfo));
  DataResp_descriptor_ = file->message_type(1);
  static const int DataResp_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataResp, users_),
  };
  DataResp_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DataResp_descriptor_,
      DataResp::default_instance_,
      DataResp_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataResp, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataResp, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(DataResp));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Protos_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    UserInfo_descriptor_, &UserInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DataResp_descriptor_, &DataResp::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Protos_2eproto() {
  delete UserInfo::default_instance_;
  delete UserInfo_reflection_;
  delete DataResp::default_instance_;
  delete DataResp_reflection_;
}

void protobuf_AddDesc_Protos_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\014Protos.proto\022\006deepdf\"\'\n\010UserInfo\022\014\n\004na"
    "me\030\001 \001(\t\022\r\n\005score\030\002 \001(\r\"+\n\010DataResp\022\037\n\005u"
    "sers\030\001 \003(\0132\020.deepdf.UserInfo", 108);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Protos.proto", &protobuf_RegisterTypes);
  UserInfo::default_instance_ = new UserInfo();
  DataResp::default_instance_ = new DataResp();
  UserInfo::default_instance_->InitAsDefaultInstance();
  DataResp::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Protos_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Protos_2eproto {
  StaticDescriptorInitializer_Protos_2eproto() {
    protobuf_AddDesc_Protos_2eproto();
  }
} static_descriptor_initializer_Protos_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int UserInfo::kNameFieldNumber;
const int UserInfo::kScoreFieldNumber;
#endif  // !_MSC_VER

UserInfo::UserInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:deepdf.UserInfo)
}

void UserInfo::InitAsDefaultInstance() {
}

UserInfo::UserInfo(const UserInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:deepdf.UserInfo)
}

void UserInfo::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  score_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

UserInfo::~UserInfo() {
  // @@protoc_insertion_point(destructor:deepdf.UserInfo)
  SharedDtor();
}

void UserInfo::SharedDtor() {
  if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete name_;
  }
  if (this != default_instance_) {
  }
}

void UserInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* UserInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return UserInfo_descriptor_;
}

const UserInfo& UserInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Protos_2eproto();
  return *default_instance_;
}

UserInfo* UserInfo::default_instance_ = NULL;

UserInfo* UserInfo::New() const {
  return new UserInfo;
}

void UserInfo::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        name_->clear();
      }
    }
    score_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool UserInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:deepdf.UserInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string name = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_score;
        break;
      }

      // optional uint32 score = 2;
      case 2: {
        if (tag == 16) {
         parse_score:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &score_)));
          set_has_score();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:deepdf.UserInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:deepdf.UserInfo)
  return false;
#undef DO_
}

void UserInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:deepdf.UserInfo)
  // optional string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->name(), output);
  }

  // optional uint32 score = 2;
  if (has_score()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->score(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:deepdf.UserInfo)
}

::google::protobuf::uint8* UserInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:deepdf.UserInfo)
  // optional string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
  }

  // optional uint32 score = 2;
  if (has_score()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->score(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:deepdf.UserInfo)
  return target;
}

int UserInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional string name = 1;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // optional uint32 score = 2;
    if (has_score()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->score());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void UserInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const UserInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const UserInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void UserInfo::MergeFrom(const UserInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_score()) {
      set_score(from.score());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void UserInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UserInfo::CopyFrom(const UserInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UserInfo::IsInitialized() const {

  return true;
}

void UserInfo::Swap(UserInfo* other) {
  if (other != this) {
    std::swap(name_, other->name_);
    std::swap(score_, other->score_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata UserInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = UserInfo_descriptor_;
  metadata.reflection = UserInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int DataResp::kUsersFieldNumber;
#endif  // !_MSC_VER

DataResp::DataResp()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:deepdf.DataResp)
}

void DataResp::InitAsDefaultInstance() {
}

DataResp::DataResp(const DataResp& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:deepdf.DataResp)
}

void DataResp::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DataResp::~DataResp() {
  // @@protoc_insertion_point(destructor:deepdf.DataResp)
  SharedDtor();
}

void DataResp::SharedDtor() {
  if (this != default_instance_) {
  }
}

void DataResp::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DataResp::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DataResp_descriptor_;
}

const DataResp& DataResp::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Protos_2eproto();
  return *default_instance_;
}

DataResp* DataResp::default_instance_ = NULL;

DataResp* DataResp::New() const {
  return new DataResp;
}

void DataResp::Clear() {
  users_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool DataResp::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:deepdf.DataResp)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .deepdf.UserInfo users = 1;
      case 1: {
        if (tag == 10) {
         parse_users:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_users()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_users;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:deepdf.DataResp)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:deepdf.DataResp)
  return false;
#undef DO_
}

void DataResp::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:deepdf.DataResp)
  // repeated .deepdf.UserInfo users = 1;
  for (int i = 0; i < this->users_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->users(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:deepdf.DataResp)
}

::google::protobuf::uint8* DataResp::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:deepdf.DataResp)
  // repeated .deepdf.UserInfo users = 1;
  for (int i = 0; i < this->users_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->users(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:deepdf.DataResp)
  return target;
}

int DataResp::ByteSize() const {
  int total_size = 0;

  // repeated .deepdf.UserInfo users = 1;
  total_size += 1 * this->users_size();
  for (int i = 0; i < this->users_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->users(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void DataResp::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const DataResp* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const DataResp*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DataResp::MergeFrom(const DataResp& from) {
  GOOGLE_CHECK_NE(&from, this);
  users_.MergeFrom(from.users_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DataResp::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DataResp::CopyFrom(const DataResp& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DataResp::IsInitialized() const {

  return true;
}

void DataResp::Swap(DataResp* other) {
  if (other != this) {
    users_.Swap(&other->users_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata DataResp::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DataResp_descriptor_;
  metadata.reflection = DataResp_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace deepdf

// @@protoc_insertion_point(global_scope)
