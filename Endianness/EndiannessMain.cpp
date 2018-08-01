

#include <iostream>
#include <arpa/inet.h>


typedef unsigned int UInt32;
typedef unsigned char Byte;

union EndianDatum
{
    UInt32 Value;
    Byte Bytes[ 4 ];
};


bool operator==( const EndianDatum& lhs, const EndianDatum& rhs )
{
    return ( lhs.Value == rhs.Value );
}

void PrintEndianness()
{
    EndianDatum ed;
    ed.Value = 0x12345678;
    if( ( ed.Bytes[ 0 ] == 0x78 )
        && ( ed.Bytes[ 1 ] == 0x56 )
        && ( ed.Bytes[ 2 ] == 0x34 )
        && ( ed.Bytes[ 3 ] == 0x12 ) )
    {
        std::cout << "Little Endian\n";
    }
    else if( ( ed.Bytes[ 0 ] == 0x12 )
        && ( ed.Bytes[ 1 ] == 0x34 )
        && ( ed.Bytes[ 2 ] == 0x56 )
        && ( ed.Bytes[ 3 ] == 0x78 ) )
    {
        std::cout << "Big Endian\n";
    }
    else
    {
        std::cout << "Unknown Endian\n";
    }
}

void PrintBytesOrder( UInt32 value )
{
    EndianDatum ed;
    ed.Value = value;
    
    for( auto& byte : ed.Bytes )
    {
        printf( "%p : 0x%02X\n", &byte, byte );
    }
}

int main()
{
    PrintEndianness();

    std::cout << "The 0x12345678's <Address:Value> in Memory :\n";
    PrintBytesOrder( 0x12345678 );

    UInt32 net_value = htonl( 0x12345678 );
    printf( "The 0x12345678's Value in Networking : 0x%X\n", net_value );

    EndianDatum lhs; lhs.Value = 0x12345678;
    EndianDatum rhs; rhs.Value = net_value;
    std::cout << "Are they the equal? " << ( lhs == rhs ) << std::endl;
    std::cout << "The 0x12345678's <Address:Value> in Networking :\n";
    PrintBytesOrder( net_value );

    return 0;
}