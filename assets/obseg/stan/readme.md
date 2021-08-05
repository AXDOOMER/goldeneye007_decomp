# Stand Tile Readme

Known as Tile, Stand Tile, or stan. This defines floor information where Bond can stand.

The model conversion tool rare used has at least 2 modes for output. Release/16bit signed; no debug strings.  And debug/32bit float with debug strings.

Each stan file is composed of a short header, ends with a standard footer, and in between is a list of tiles and points.

Values are stored most significant byte first.

## Header

The header consists of 4 empty bytes, followed by a 32 bit integer giving the offset to tiles from the start of the file. There are optional bytes between the tile offset number and the start of the tiles, usually an empty 4 bytes.

The header is the same for both release and debug.

## Tiles

Tiles consist of a 64 bit tile description, followed by an array of points.

byte 0-3: a name, id or descriptor. One byte seems to be a "group id" and the other two bytes are some kind of tile id, but exact definition is unknown.  
byte 4: room number  
byte 5 (upper 4 bits): flags or attributes.  
byte 5 (lower 4 bits): Red  
byte 6 (upper 4 bits): Green  
byte 6 (lower 4 bits): Blue  
byte 7 (upper 4 bits): number of points within the tile  

The remaining 3 fields generally define the most extreme points within the tile

byte 7 (lower 4 bits): first point  
byte 8 (upper 4 bits): second point  
byte 8 (lower 4 bits): third point  

### Tile Points

A tile point is described by four 16-bit fields, giving X,Y,Z coordinates of the point as signed 16-bit integer.

The remaining field is the "link"

## Beta Tiles

Beta tiles consist of a 96 bit tile description, followed by an array of points.

byte 0-3: (same as regular tile)  
byte 4: room number (same as regular tile)  
byte 5 (upper 4 bits): flags or attributes. (same as regular tile)  
byte 5 (lower 4 bits): Red (same as regular tile)  
byte 6 (upper 4 bits): Green (same as regular tile)  
byte 6 (lower 4 bits): Blue (same as regular tile)  
byte 7-8: unknown 16-bit field.  
byte 9: number of points within the tile  

The remaining 3 fields generally define the most extreme points within the tile (same as regular tile, except one full byte)

byte 10: first point  
byte 11: second point  
byte 12: third point  

### Beta Tile Points

Beta tile points store the same information as regular tiles, but in a different format.

The X,Y,Z coordinates are now 32-bit floats.

The "link" is now a 32-bit int.

## Tile Attributes

Possible values for tile "flags" or "attributes":

0 = Normal  
1 = Kneeling  
3 = Ladder  

## Footer
After the tile list is a standard footer. This consists of 2 null pointers (8 bytes of zero), followed by an 8 character zero terminated string "unstric", followed by 4 more null points (16 bytes of zero).

### Beta Footer
Beta stan file contains a list of ASCII strings after the footer. Each string is exactly 8 bytes long. The strings give debug names to the tiles defined above.

These strings are not included with regular stan files.
