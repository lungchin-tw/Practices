// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.28.1
// 	protoc        v3.6.1
// source: tutorial.proto

package tutorialpb

import (
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	reflect "reflect"
	sync "sync"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

type Item struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	ItemId         string `protobuf:"bytes,1,opt,name=item_id,json=itemId,proto3" json:"item_id,omitempty"`                           // e.g. "desk_1", "chair_6"
	ItemInstanceId string `protobuf:"bytes,2,opt,name=item_instance_id,json=itemInstanceId,proto3" json:"item_instance_id,omitempty"` // “desk_1-123e4567-e89b-12d3-a456-426614174000” globally unique
	NftToken       int64  `protobuf:"varint,3,opt,name=nft_token,json=nftToken,proto3" json:"nft_token,omitempty"`                    // need to check nft token type. need to think more...
	Stackable      bool   `protobuf:"varint,4,opt,name=stackable,proto3" json:"stackable,omitempty"`
}

func (x *Item) Reset() {
	*x = Item{}
	if protoimpl.UnsafeEnabled {
		mi := &file_tutorial_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *Item) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*Item) ProtoMessage() {}

func (x *Item) ProtoReflect() protoreflect.Message {
	mi := &file_tutorial_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use Item.ProtoReflect.Descriptor instead.
func (*Item) Descriptor() ([]byte, []int) {
	return file_tutorial_proto_rawDescGZIP(), []int{0}
}

func (x *Item) GetItemId() string {
	if x != nil {
		return x.ItemId
	}
	return ""
}

func (x *Item) GetItemInstanceId() string {
	if x != nil {
		return x.ItemInstanceId
	}
	return ""
}

func (x *Item) GetNftToken() int64 {
	if x != nil {
		return x.NftToken
	}
	return 0
}

func (x *Item) GetStackable() bool {
	if x != nil {
		return x.Stackable
	}
	return false
}

var File_tutorial_proto protoreflect.FileDescriptor

var file_tutorial_proto_rawDesc = []byte{
	0x0a, 0x0e, 0x74, 0x75, 0x74, 0x6f, 0x72, 0x69, 0x61, 0x6c, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f,
	0x12, 0x08, 0x74, 0x75, 0x74, 0x6f, 0x72, 0x69, 0x61, 0x6c, 0x22, 0x84, 0x01, 0x0a, 0x04, 0x49,
	0x74, 0x65, 0x6d, 0x12, 0x17, 0x0a, 0x07, 0x69, 0x74, 0x65, 0x6d, 0x5f, 0x69, 0x64, 0x18, 0x01,
	0x20, 0x01, 0x28, 0x09, 0x52, 0x06, 0x69, 0x74, 0x65, 0x6d, 0x49, 0x64, 0x12, 0x28, 0x0a, 0x10,
	0x69, 0x74, 0x65, 0x6d, 0x5f, 0x69, 0x6e, 0x73, 0x74, 0x61, 0x6e, 0x63, 0x65, 0x5f, 0x69, 0x64,
	0x18, 0x02, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0e, 0x69, 0x74, 0x65, 0x6d, 0x49, 0x6e, 0x73, 0x74,
	0x61, 0x6e, 0x63, 0x65, 0x49, 0x64, 0x12, 0x1b, 0x0a, 0x09, 0x6e, 0x66, 0x74, 0x5f, 0x74, 0x6f,
	0x6b, 0x65, 0x6e, 0x18, 0x03, 0x20, 0x01, 0x28, 0x03, 0x52, 0x08, 0x6e, 0x66, 0x74, 0x54, 0x6f,
	0x6b, 0x65, 0x6e, 0x12, 0x1c, 0x0a, 0x09, 0x73, 0x74, 0x61, 0x63, 0x6b, 0x61, 0x62, 0x6c, 0x65,
	0x18, 0x04, 0x20, 0x01, 0x28, 0x08, 0x52, 0x09, 0x73, 0x74, 0x61, 0x63, 0x6b, 0x61, 0x62, 0x6c,
	0x65, 0x42, 0x0e, 0x5a, 0x0c, 0x2e, 0x2f, 0x74, 0x75, 0x74, 0x6f, 0x72, 0x69, 0x61, 0x6c, 0x70,
	0x62, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_tutorial_proto_rawDescOnce sync.Once
	file_tutorial_proto_rawDescData = file_tutorial_proto_rawDesc
)

func file_tutorial_proto_rawDescGZIP() []byte {
	file_tutorial_proto_rawDescOnce.Do(func() {
		file_tutorial_proto_rawDescData = protoimpl.X.CompressGZIP(file_tutorial_proto_rawDescData)
	})
	return file_tutorial_proto_rawDescData
}

var file_tutorial_proto_msgTypes = make([]protoimpl.MessageInfo, 1)
var file_tutorial_proto_goTypes = []interface{}{
	(*Item)(nil), // 0: tutorial.Item
}
var file_tutorial_proto_depIdxs = []int32{
	0, // [0:0] is the sub-list for method output_type
	0, // [0:0] is the sub-list for method input_type
	0, // [0:0] is the sub-list for extension type_name
	0, // [0:0] is the sub-list for extension extendee
	0, // [0:0] is the sub-list for field type_name
}

func init() { file_tutorial_proto_init() }
func file_tutorial_proto_init() {
	if File_tutorial_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_tutorial_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*Item); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
	}
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_tutorial_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   1,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_tutorial_proto_goTypes,
		DependencyIndexes: file_tutorial_proto_depIdxs,
		MessageInfos:      file_tutorial_proto_msgTypes,
	}.Build()
	File_tutorial_proto = out.File
	file_tutorial_proto_rawDesc = nil
	file_tutorial_proto_goTypes = nil
	file_tutorial_proto_depIdxs = nil
}
